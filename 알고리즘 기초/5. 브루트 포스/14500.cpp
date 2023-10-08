#include<iostream>
using namespace std;

int N, M, arr[500][500];
int chk[500][500];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int func(int x, int y, int val, int cnt)
{
	int rtn = val;

	if (cnt == 4)
		return rtn;

	chk[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];

		if (xx < 0 || xx >= M || yy < 0 || yy >= N)
			continue;

		if (chk[yy][xx] == 0)
		{
			int cur = func(xx, yy, val + arr[yy][xx], cnt + 1);
			rtn = max(rtn, cur);
		}
	}
	chk[y][x] = 0;

	return rtn;
}

int func2(int x, int y)
{
	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		int xx[3], yy[3], err = 0;
		for (int j = 0; j < 3; j++)
		{
			xx[j] = x + dx[(i + j) % 4];
			yy[j] = y + dy[(i + j) % 4];

			if (xx[j] < 0 || xx[j] >= M || yy[j] < 0 || yy[j] >= N)
			{
				err = 1;
				break;
			}
		}

		if (err)
			continue;

		int cur = arr[y][x];
		for (int j = 0; j < 3; j++)
			cur += arr[yy[j]][xx[j]];

		sum = max(sum, cur);
	}

	return sum;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			ans = max(ans, func(j, i, arr[i][j], 1));
			ans = max(ans, func2(j, i));
		}
	}

	cout << ans;

	return 0;
}