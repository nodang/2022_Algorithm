/*
단순 브루트포스인데 어려움
왜 어렵냐

dfs처럼 풀어야할 거 같이 생김
백트래킹이 필요없고 원래 상태일 때 한 번 세고
스왑하면서 한 번 세는데 따지지 말고 전부 한 번식 교환하면서 세면 됨
따질려고 하면 어려워짐
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