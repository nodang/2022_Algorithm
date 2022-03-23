#include <iostream>
#include <string>
using namespace std;

int stack[10000];
int stack_cnt;

void push(int X)
{
    stack[stack_cnt++] = X;
}

int size(void)
{
    return stack_cnt;
}

int empty(void)
{
    if (stack_cnt != 0)
        return 0;
    else
        return 1;
}

int pop(void)
{
    int rtn = empty();
    if (rtn == 1)
        return -1;

    return stack[--stack_cnt];
}

int top(void)
{
    int rtn = empty();
    if (rtn == 1)
        return -1;
    else
        return stack[stack_cnt-1];
}

int main(void)
{
    int n, X, rtn;
    string command;
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    stack_cnt = 0;

    while(n--)
    {
        cin >> command;

        if (command == "push")
        {
            cin >> X;
            push(X);
        }
        else if (command == "top")
            rtn = top();
        else if (command == "size")
            rtn = size();
        else if (command == "empty")
            rtn = empty();
        else
            rtn = pop();

        if(command != "push")
            cout << rtn << '\n';
    }
    
    return 0;
}