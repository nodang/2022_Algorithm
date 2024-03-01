#include <iostream>
#include <deque>
#include <cmath>
#include <cstring>
using namespace std;

typedef struct {
	int x, y;
} Coord;

typedef struct {
	int x, y, cnt;
} BFS;

int N, M;
int arr[52][52];
int virus[52][52];
int check[52][52];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

deque<Coord> dq;	//바이러스 놓을 수 있는 좌표
deque<int> num;		//놓을 수 있는 좌표 조합
deque<BFS> bfs;

int check_max(void)
{
	int curr_max = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			curr_max = curr_max > virus[i][j] ? curr_max : virus[i][j];

			if (virus[i][j] == 0 && arr[i][j] == 0)
				return -1;

			if (virus[i][j] == 0 && arr[i][j] == 2)
				return -1;
		}
	}

	return curr_max;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 2)
				dq.push_back({ j, i });
		}

	for (int i = 0; i < M; i++)
		num.push_back(i);

	int tf = 1;
	int min = -1;

	while (tf)
	{
		memset(virus, 0, sizeof(virus));

		for (int i = 0; i < M; i++)
		{
			int x = dq[num[i]].x, y = dq[num[i]].y;
			
			memset(check, 0, sizeof(check));

			virus[y][x] = -1;
			bfs.push_back({ x, y, 0 });
			check[y][x] = 1;

			while (!bfs.empty())
			{
				int xx = bfs.front().x, yy = bfs.front().y, cc = bfs.front().cnt;
				bfs.pop_front();

				if (virus[yy][xx] == 0 || virus[yy][xx] > cc)
					virus[yy][xx] = cc;

				for (int i = 0; i < 4; i++)
				{
					int xxx = xx + dx[i], yyy = yy + dy[i];

					if (check[yyy][xxx] != 0)
						continue;

					if (arr[yyy][xxx] != 1 && xxx > 0 && xxx <= N && yyy > 0 && yyy <= N)
					{
						bfs.push_back({ xxx, yyy, cc + 1 });
						check[yyy][xxx] = 1;
					}
				}
			}

		}

		int curr_max = check_max();

		if (curr_max != -1 && (min == -1 || min > curr_max))
			min = curr_max;

		int limit = M - 1;
		for (int i = 0; i < M; i++)
		{
			int curr = limit - i;

			if (num.at(curr) < (dq.size() - (i + 1)))
			{
				num.at(curr)++;

				for (int j = curr + 1; j < M; j++)
					num.at(j) = num.at(j - 1) + 1;

				break;
			}
			else if (i == limit)
				tf = 0;
		}
	}

	cout << min;

	return 0;
}