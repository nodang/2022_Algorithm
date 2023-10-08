// 1시간 22분 9초
// 복잡한 시뮬레이션 구현 문제
// 각 방향에 따른 우선순위 방향 구현이 핵심

#include <iostream>
#include<deque>
#include<algorithm>
#include<cstring>
using namespace std;

typedef struct {
	int num, x, y, dir;
	int priority[5][4];
}shark;

typedef struct {
	int cnt, num;
}smell;

int N, M, k;
int arr[21][21];
deque<shark> shk;

smell check[21][21];

int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, -1, 1, 0, 0 };

int cmp(const shark& a, const shark& b)
{
	if (a.num < b.num)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> k;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0)
			{
				shark cur = { arr[i][j], j, i, 0, { { 0, }, } };
				shk.push_back(cur);
				check[i][j] = { k, arr[i][j] };
			}
		}
	sort(shk.begin(), shk.end(), cmp);
	for (int i = 0; i < M; i++)
		cin >> shk[i].dir;

	for (int i = 0; i < M; i++)
		for (int d = 1; d <= 4; d++)
			for (int j = 0; j < 4; j++)
				cin >> shk[i].priority[d][j];

	int time = 0;
	while (shk.size() != 1)
	{
		if (time >= 1000)
		{
			time = -1;
			break;
		}
		// 상어 이동
		deque<shark> copy = shk;
		deque<shark> dq;
		while (!copy.empty())
		{
			shark cur = copy.front();
			copy.pop_front();

			bool movable = false;
			for (int i = 0; i < 4; i++)
			{
				int step = cur.priority[cur.dir][i];
				int x = cur.x + dx[step], y = cur.y + dy[step];

				if (x < 0 || x >= N || y < 0 || y >= N)
					continue;

				if (arr[y][x] == 0 && check[y][x].cnt == 0)
				{
					movable = true;

					cur.x = x, cur.y = y;
					cur.dir = step;

					dq.push_back(cur);
					break;
				}
			}
			if (!movable)
			{
				for (int i = 0; i < 4; i++)
				{
					int step = cur.priority[cur.dir][i];
					int x = cur.x + dx[step], y = cur.y + dy[step];

					if (x < 0 || x >= N || y < 0 || y >= N)
						continue;

					if (check[y][x].num == cur.num)
					{
						cur.x = x, cur.y = y;
						cur.dir = step;

						dq.push_back(cur);
						break;
					}
				}
			}
		}
		
		// 상어 내쫒기
		int size = dq.size();
		while (size--)
		{
			shark cur = dq.front();
			dq.pop_front();

			if (arr[cur.y][cur.x] != 0 && arr[cur.y][cur.x] < cur.num)
				continue;
			
			arr[cur.y][cur.x] = cur.num;
			check[cur.y][cur.x].cnt = k + 1;
			check[cur.y][cur.x].num = cur.num;
			dq.push_back(cur);
		}

		// 상어 냄새
		for(int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (check[i][j].cnt > 0)
					check[i][j].cnt--;

				if (check[i][j].cnt == 0)
					check[i][j].num = 0;
			}

		while (!shk.empty())
		{
			shark cur = shk.front();
			shk.pop_front();

			arr[cur.y][cur.x] = 0;
		}

		shk = dq;
		time++;
	}

	cout << time;

	return 0;
}