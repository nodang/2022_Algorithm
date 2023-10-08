// 32Ка 42УЪ

#include <iostream>
#include <cstring>
using namespace std;

int N, M, R;
int arr[301][301];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int dfs(int x, int y, int rotate[301][301], int dir, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[dir], yy = y + dy[dir];

		if ((xx <= 0 || xx > M || yy <= 0 || yy > N) || (rotate[yy][xx] != 0))
		{
			dir = (dir + 1) % 4;
			continue;
		}
		
		rotate[yy][xx] = arr[y][x];
		int rtn = dfs(xx, yy, rotate, dir, cnt + 1);

		return rtn;
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	while (R--)
	{
		int rotate[301][301] = { { 0, }, };

		int MM = N * M, cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
				if (rotate[i][j] == 0)
				{
					cnt += dfs(j, i, rotate, 0, 0);
					if (MM == cnt)
						break;
				}

			if (MM == cnt)
				break;
		}

		memcpy(arr, rotate, sizeof(arr));
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}