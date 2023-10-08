// 1�ð� 10�� 6��
// �������� bfs. deque�� �����ϸ� �޸� �ʰ���
// �ּ����� �Լ� ȣ��� �����ؾ��ϹǷ� �迭�� �ִ밪�� �����ϸ鼭 bfs�� ������

#include <iostream>
using namespace std;

int N;
int arr[1000];
int check[1000];

void func(int ind, int cnt)
{
	for (int i = 1; i < N - ind; i++)
		if (arr[ind] < arr[ind + i])
			check[ind + i] = cnt + 1 > check[ind + i] ? cnt + 1 : check[ind + i];
} 

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i = 0; i < N; i++)
		func(i, check[i]);

	int rtn = 0;
	for (int i = 0; i < N; i++)
		rtn = rtn > check[i] ? rtn : check[i];

	cout << rtn + 1;

	return 0;
}