// 58분 26초
// 우선순위를 어떻게 할래?
// 우선순위 큐 문제였을까?

#include <iostream>
#include <deque>
using namespace std;

typedef struct {
	int x, y, cnt;
}coord;

int N;
int arr[21][21];

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

coord shark;
int shark_size;
deque<coord> will_eat_fish;
int how_many;
int fishes;

int second;

void bfs()
{
	int check[21][21] = { { 0, }, };
	deque<coord> dq;
	dq.push_back(shark);
	check[dq.front().y ][dq.front().x] = 1;

	while (!dq.empty())
	{
		coord cur = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int x = cur.x + dx[i], y = cur.y + dy[i];

			if (x < 0 || x >= N || y < 0 || y >= N)
				continue;

			if (arr[y][x] > shark_size)
				continue;

			if (!will_eat_fish.empty() && cur.cnt + 1 > will_eat_fish.front().cnt)
				return;

			if (check[y][x] == 0)
			{
				check[y][x] = 1;
				if (arr[y][x] != 0 && arr[y][x] < shark_size)
				{
					if (will_eat_fish.empty())
						will_eat_fish.push_back({ x, y, cur.cnt + 1 });
					else if(will_eat_fish.front().y > y)
					{
						will_eat_fish.clear();
						will_eat_fish.push_back({ x, y, cur.cnt + 1 });
					}
					else if (will_eat_fish.front().y == y)
					{
						if (will_eat_fish.front().x > x)
						{
							will_eat_fish.clear();
							will_eat_fish.push_back({ x, y, cur.cnt + 1 });
						}
					}
				}
				else
					dq.push_back({ x, y, cur.cnt + 1 });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
				shark.x = j, shark.y = i, shark.cnt = 0;
			else if (arr[i][j] != 0)
				fishes++;
		}

	shark_size = 2;
	while (fishes--)
	{
		bfs();

		if (will_eat_fish.empty())
			break;

		coord cur = will_eat_fish.front();
		will_eat_fish.pop_front();
		second += cur.cnt;
		
		arr[cur.y][cur.x] = 9;

		arr[shark.y][shark.x] = 0;
		shark.x = cur.x, shark.y = cur.y;

		how_many++;

		if (shark_size == how_many)
		{
			shark_size++;
			how_many = 0;
		}
	}
	cout << second;

	return 0;
}