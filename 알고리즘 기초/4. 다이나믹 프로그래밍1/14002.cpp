// 1�ð� 53�� 02��
// ���� �𸣰���
// ������ ���ߴµ� ������ �ǰ��ؼ� �κ������� ����°� �����
// 

#include <iostream>
using namespace std;

int N;
int arr[1000], check[1000], output[1000];

void func_up(int ind, int cnt)
{
	for (int i = 1; i < N - ind; i++)
		if (arr[ind] < arr[ind + i])
			if (check[ind + i] < cnt + 1)
				check[ind + i] = cnt + 1;
}

void func_down(int ind, int cnt)
{
	int max = 0;
	for (int i = 1; i <= ind; i++)
		if (output[cnt] > arr[ind - i] && check[ind - i] == cnt - 1)
			max = max > arr[ind - i] ? max : arr[ind - i];
	if(max != 0)
		output[cnt - 1] = max;
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int rtn = -1, curr = 0;;
	for (int i = 0; i < N; i++)
	{
		func_up(i, check[i]);

		if (check[i] > rtn)
		{
			rtn = check[i];
			curr = arr[i];
		}
	}

	output[rtn] = curr;
	for (int i = N - 1; i >= 0; i--)
		func_down(i, check[i]);

	cout << rtn + 1 << '\n';
	
	for (int i = 0; i <= rtn; i++)
		cout << output[i] << ' ';


	return 0;
}