/*
�ܼ� ���Ʈ�����ε� �����
�� ��Ƴ�

dfsó�� Ǯ����� �� ���� ����
��Ʈ��ŷ�� �ʿ���� ���� ������ �� �� �� ����
�����ϸ鼭 �� �� ���µ� ������ ���� ���� �� ���� ��ȯ�ϸ鼭 ���� ��
�������� �ϸ� �������
*/
#include<iostream>
#include<cstring>
using namespace std;

int N;
string arr[51];

int func(int ans)
{
	for (int i = 0; i < N; i++)
	{
		int cnt = 1;
		for (int j = 1; j < N; j++)
		{
			if (arr[i][j] == arr[i][j - 1])
				cnt++;
			else
			{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}
	for (int i = 0; i < N; i++)
	{
		int cnt = 1;
		for (int j = 1; j < N; j++)
		{
			if (arr[j][i] == arr[j - 1][i])
				cnt++;
			else
			{
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}

	return ans;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int ans = 0;
	ans = func(ans);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j < N - 1)
			{
				char cur1 = arr[i][j], cur2 = arr[i][j + 1];
				arr[i][j] = cur2;
				arr[i][j + 1] = cur1;

				ans = func(ans);

				arr[i][j] = cur1;
				arr[i][j + 1] = cur2;
			}
			if (i < N - 1) 
			{
				int cur1 = arr[i][j], cur2 = arr[i + 1][j];
				arr[i][j] = cur2;
				arr[i + 1][j] = cur1;

				ans = func(ans);

				arr[i][j] = cur1;
				arr[i + 1][j] = cur2;
			}
		}
	}

	cout << ans;

	return 0;
}