// 58분 40초
// 특이한 구현 문제
// 격자화된 배열을 회전시키는 알고리즘이 특이함

#include <iostream>
#include <cmath>
#include <deque>
#include <cstring>
using namespace std;

typedef struct {
	int x, y;
} coord;

int N, Q, limit;
int arr[100][100];

deque<int> l;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	limit = pow(2, N);
	for (int i = 0; i < limit; i++)
		for (int j = 0; j < limit; j++)
			cin >> arr[i][j];
	for (int i = 0; i < Q; i++)
	{
		int cur;
		cin >> cur;
		l.push_back(cur);
	}

	while (!l.empty())
	{
		int L = pow(2, l.front());
		l.pop_front();

		// 격자 시계방향 90도 회전
		int after[100][100] = { { 0,}, };
		for (int i = 0; i < limit; i++)
			for (int j = 0; j < limit; j++)
			{
				int dx = j % L, dy = i % L;
				int x = j - dx, y = i - dy;

				after[y + dx][x + ((L - 1) - dy)] = arr[i][j];
			}
		memcpy(arr, after, sizeof(arr));

		// 얼음 녹이기
		for (int i = 0; i < limit; i++)
			for (int j = 0; j < limit; j++)
				if (arr[i][j] > 0)
				{
					int dx[] = { 0, 0, -1, 1 };
					int dy[] = { -1, 1, 0, 0 };

					int nearby = 0;

					for (int k = 0; k < 4; k++)
					{
						int x = j + dx[k], y = i + dy[k];

						if (x < 0 || x >= limit || y < 0 || y > limit)
							nearby++;
						else if (arr[y][x] == 0)
							nearby++;
					}

					if (nearby > 1)
						after[i][j]--;
				}

		memcpy(arr, after, sizeof(arr));
	}
	int sum = 0, how_many = 0;
	int check[100][100] = { { 0, }, };
	for (int i = 0; i < limit; i++)
		for (int j = 0; j < limit; j++)
			if (arr[i][j] > 0)
			{
				sum += arr[i][j];

				if (check[i][j] == 0)
				{
					// bfs
					deque<coord> dq;
					dq.push_back({ j, i });
					check[i][j] = 1;

					int dx[] = { 0, 0, -1, 1 };
					int dy[] = { -1, 1, 0, 0 };

					int cnt = 1;
					while (!dq.empty())
					{
						int x = dq.front().x, y = dq.front().y;
						dq.pop_front();

						for (int i = 0; i < 4; i++)
						{
							int xx = x + dx[i], yy = y + dy[i];

							if (xx < 0 || xx >= limit || yy < 0 || yy >= limit)
								continue;

							if (arr[yy][xx] > 0 && check[yy][xx] == 0)
							{
								check[yy][xx] = 1;
								cnt++;
								dq.push_back({ xx, yy });
							}
						}
					}
					how_many = max(how_many, cnt);
				}
			}
	cout << sum << '\n' << how_many;

	return 0;
}