#include <stdlib.h>
#include <memory.h>

typedef struct StockLinkedList
{
    int num;
    int stock;
    int qty;
    int cost;
    struct StockLinkedList *Prev;
    struct StockLinkedList *Next;
}SLL;

extern SLL *buy_head = (SLL*)malloc(sizeof(SLL));
extern SLL *sell_head = (SLL*)malloc(sizeof(SLL));
extern SLL* pf_head = (SLL*)malloc(sizeof(SLL));
extern SLL *ext_node[200000] = { 0, };
extern int count_node = 0;

SLL *next_node(SLL *std_node, int *mNumber, int *mStock, int *mQuantity, int *mPrice)
{
    SLL *node = (SLL*)malloc(sizeof(SLL));
    if (node == NULL)    return NULL;

    node->num = *mNumber;
    node->stock = *mStock;
    node->qty = *mQuantity;
    node->cost = *mPrice;

    if (std_node->Next != NULL)
    {
        node->Prev = std_node;
        node->Next = std_node->Next;
        std_node->Next->Prev = node;
        std_node->Next = node;
    }
    else
    {
        std_node->Next = node;
        node->Prev = std_node;
        node->Next = NULL;
    }

    return node;
}

SLL *exit_node(SLL *rm_node)
{
    SLL *keep_node = rm_node->Prev;
    if (rm_node->Next != NULL)
    {
        rm_node->Next->Prev = rm_node->Prev;
        rm_node->Prev->Next = rm_node->Next;
    }
    else
    {
        rm_node->Prev->Next = NULL;
    }

    rm_node->Prev = NULL;  
    rm_node->Next = NULL;  

    if (rm_node != NULL)    free(rm_node);

    return keep_node;
}

SLL* copy_node(int mstock, int mcost)
{
    SLL* copy_save = (SLL*)malloc(sizeof(SLL));
    if (copy_save == NULL)    return NULL;

    copy_save->cost = mcost;
    copy_save->stock = mstock;

    if (pf_head->Next != NULL)
    {
        SLL* curr = pf_head;
        while (curr->Next != NULL)    curr = curr->Next;
        curr->Next = copy_save;
        copy_save->Prev = curr;
    }
    else
    {
        pf_head->Next = copy_save;
        copy_save->Prev = pf_head;
    }
    copy_save->Next = NULL;

    return copy_save;
}

void init()
{
    buy_head->Next = NULL;
    buy_head->Prev = NULL;

    sell_head->Next = NULL;
    sell_head->Prev = NULL;

    pf_head->Next = NULL;
    pf_head->Prev = NULL;

    memset(ext_node, 0, 200000*sizeof(SLL*));

    count_node = 0;
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
    if (sell_head->Next != NULL)
    {
        SLL* curr = sell_head->Next;
        while (curr != NULL)
        {
            if (curr->cost <= mPrice)
            {
                if (curr->stock == mStock)
                {
                    if (curr->qty < mQuantity)
                    {
                        mQuantity -= curr->qty;
                        ext_node[count_node++] = copy_node(curr->stock, curr->cost);
                        curr = exit_node(curr);
                    }
                    else if (curr->qty == mQuantity)
                    {
                        ext_node[count_node++] = copy_node(curr->stock, curr->cost);
                        curr = exit_node(curr);
                        return 0;
                    }
                    else
                    {
                        ext_node[count_node++] = copy_node(curr->stock, curr->cost);
                        curr->qty -= mQuantity;
                        return 0;
                    }
                }
            }
            else    break;
            curr = curr->Next;
        }
    }

    if (buy_head->Next == NULL)
        ext_node[count_node++] = next_node(buy_head, &mNumber, &mStock, &mQuantity, &mPrice);
    else
    {
        SLL *curr = buy_head->Next;
        while (curr != NULL)
        {
            if (curr->cost <= mPrice)
            {
                if (curr->cost < mPrice)
                {
                    ext_node[count_node] = next_node(curr->Prev, &mNumber, &mStock, &mQuantity, &mPrice);
                    break;
                }
                else if (curr->num > mNumber)
                {
                    ext_node[count_node] = next_node(curr->Prev, &mNumber, &mStock, &mQuantity, &mPrice);
                    break;
                }
                else if (curr->num < mNumber)
                {
                    if (curr->Next != NULL)
                    {
                        SLL* sub_curr = curr;
                        while (sub_curr->num > mNumber)     sub_curr = sub_curr->Next;
                        ext_node[count_node] = next_node(sub_curr, &mNumber, &mStock, &mQuantity, &mPrice);
                        break;
                    }
                    else
                    {
                        ext_node[count_node] = next_node(curr, &mNumber, &mStock, &mQuantity, &mPrice);
                        break;
                    }
                }
            }
            else if (curr->Next == NULL)
            {
                ext_node[count_node] = next_node(curr, &mNumber, &mStock, &mQuantity, &mPrice);
                break;
            }
            curr = curr->Next;
        }
        count_node++;
     }

    return mQuantity;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
    if (buy_head->Next != NULL)
    {
        SLL* curr = buy_head->Next;
        while (curr != NULL)
        {
            if (curr->cost >= mPrice)
            {
                if (curr->stock == mStock)
                {
                    if (curr->qty < mQuantity)
                    {
                        mQuantity -= curr->qty;
                        ext_node[count_node++] = copy_node(curr->stock, curr->cost);
                        curr = exit_node(curr);
                    }
                    else if (curr->qty == mQuantity)
                    {
                        ext_node[count_node++] = copy_node(curr->stock, curr->cost);
                        curr = exit_node(curr);
                        return 0;
                    }
                    else
                    {
                        ext_node[count_node++] = copy_node(curr->stock, curr->cost);
                        curr->qty -= mQuantity;
                        return 0;
                    }
                }
            }
            else   break;
            curr = curr->Next;
        }
    }

    if (sell_head->Next == NULL)
        ext_node[count_node++] = next_node(sell_head, &mNumber, &mStock, &mQuantity, &mPrice);
    else
    {
        SLL *curr = sell_head->Next;
        while (curr != NULL)
        {
            if (curr->cost >= mPrice)
            {
                if (curr->cost > mPrice)
                {
                    ext_node[count_node] = next_node(curr->Prev, &mNumber, &mStock, &mQuantity, &mPrice);
                    break;
                }
                else if (curr->num > mNumber)
                {
                    ext_node[count_node] = next_node(curr->Prev, &mNumber, &mStock, &mQuantity, &mPrice);
                    break;
                }
                else if (curr->num < mNumber)
                {
                    if (curr->Next != NULL)
                    {
                        SLL *sub_curr = curr->Next;
                        while (sub_curr->num > mNumber)     sub_curr = sub_curr->Next;
                        ext_node[count_node] = next_node(sub_curr, &mNumber, &mStock, &mQuantity, &mPrice);
                        break;
                    }
                    else
                    {
                        ext_node[count_node] = next_node(curr, &mNumber, &mStock, &mQuantity, &mPrice);
                        break;
                    }
                }
            }
            else if (curr->Next == NULL)
            {
                ext_node[count_node] = next_node(curr, &mNumber, &mStock, &mQuantity, &mPrice);
                break;
            }
            curr = curr->Next;
        }
        count_node++;
    }

    return mQuantity;
}

void cancel(int mNumber)
{
    SLL *curr1 = buy_head->Next;
    SLL* curr2 = sell_head->Next;
    while (curr1 != NULL || curr2 != NULL)
    {
        if (curr1 != NULL) 
        {
            if (curr1->num == mNumber)
            {
                curr1 = exit_node(curr1);
                return;
            }
            curr1 = curr1->Next;
        }  
        if (curr2 != NULL)
        {
            if (curr2->num == mNumber)
            {
                curr2 = exit_node(curr2);
                return;
            }
            curr2 = curr2->Next;
        }
    }
}

int bestProfit(int mStock)
{
    int max = 0;
    SLL *curr = pf_head;
    while (curr != NULL)
    {
        if (curr->stock == mStock)
        {
            SLL* s_curr = curr;
            while (s_curr != NULL)
            {
                if (s_curr->stock == mStock)
                    if (max < s_curr->cost - curr->cost)
                        max = s_curr->cost - curr->cost;
                s_curr = s_curr->Next;
            }
        }
        curr = curr->Next;
    }
    if (max < 0)     max = 0;

    return max;
}