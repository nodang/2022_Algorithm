// 3시간 10분 1초
// 개 어 려 움
// 상어의 움직임에 유의할 것 -> 갔던 자리도 중복해서 체크해야한다는 점
// deque 물고기를 전부 넣으면 백만 마리를 하나하나 계산해야함
// 이러면 시간 초과가 되기 때문에 같은 공간에 방향이 같으면 동시에 움직이도록 구현
// 그러면 최악의 경우도 4 * 4 * 9 만 확인하면 전부 확인 가능해짐

#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct {
	int x, y, d;
}fish;

int M, S;

int arr[4][4][9];

int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int dx_s[] = { 1, 0, -1, 0 };
int dy_s[] = { 0, 1, 0, -1 };

fish shark;

int comp_max;
deque<fish> cleared;

void dfs(deque<fish> cur, int cnt, int fishes, fish cur_s)
{
	if (cnt == 3)
	{
		if (comp_max <= fishes)
		{
			comp_max = fishes;
			cleared.clear();
			cleared = cur;
			shark = cur_s;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int x = cur_s.x + dx_s[i], y = cur_s.y + dy_s[i];

		if (x < 0 || x > 3 || y < 0 || y > 3)
			continue;

		if (arr[y][x][0] > 0)
		{
			cur.push_back({ x, y, 0 });
			int save = arr[y][x][0];
			arr[y][x][0] = 0;
			dfs(cur, cnt + 1, fishes + save, { x, y, 0 });
			arr[y][x][0] = save;
			cur.pop_back();
		}
		else
			dfs(cur, cnt + 1, fishes, { x, y, 0 });
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> S;
	for (int i = 0; i < M; i++)
	{
		fish f;
		cin >> f.y >> f.x >> f.d;
		f.x--;
		f.y--;

		arr[f.y][f.x][0]++;
		arr[f.y][f.x][f.d]++;
	}
	cin >> shark.y >> shark.x;
	shark.x--;
	shark.y--;

	int smell[4][4] = { { 0, }, };
	while (S--)
	{
		// 1. 복제 마법 실시
		int copy[4][4][9];
		memcpy(copy, arr, sizeof(arr));

		// 2. 모든 물고기 이동. 상어, 물고기 냄새 있는 칸으로 이동 불가
		// 이동할 수 있을 때까지 45도 반시계 회전. 그래도 없으면 이동 X
		int place[4][4][9] = { { { 0, }, }, };
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 1; k < 9; k++)
				{
					if (arr[i][j][k] == 0)
						continue;

					int x, y, dir = k;
					bool move_check = false;
					for (int l = 0; l < 8; l++)
					{
						x = j + dx[dir], y = i + dy[dir];

						if ((x < 0 || x > 3 || y < 0 || y > 3) ||
							(smell[y][x] != 0 || (shark.x == x && shark.y == y)))
						{
							dir = dir == 1 ? 8 : dir - 1;
							continue;
						}

						move_check = true;
						break;
					}
					if (move_check)
					{
						place[y][x][dir] += arr[i][j][k];
						place[y][x][0] += arr[i][j][k];
					}
					else
					{
						place[i][j][k] += arr[i][j][k];
						place[i][j][0] += arr[i][j][k];
					}
				}
			}
		}
		memcpy(arr, place, sizeof(arr));

		// 3. 상어 3칸 이동, 가장 많은 물고기를 거치며 이동. 
		// 물고기를 만나면, 물고기 냄새로 바꿈
		cleared.clear();
		comp_max = 0;
		deque<fish> cur;
		//check[shark.y][shark.x] = 1;
		dfs(cur, 0, 0, shark);

		while(!cleared.empty())
		{
			fish cur = cleared.front();
			cleared.pop_front();

			memset(arr[cur.y][cur.x], 0, sizeof(arr[cur.y][cur.x]));
			smell[cur.y][cur.x] = -1;
		}

		// 4. 2번 전에 생성된 냄새는 제거
		for(int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				if (smell[i][j] == 1)
					smell[i][j]++;
				else if (smell[i][j] == -1)
					smell[i][j] = 1;
				else if(smell[i][j] == 2)
					smell[i][j] = 0;
			}

		// 5. 복제 마법 완료
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				for(int k = 0; k < 9; k++)
					arr[i][j][k] += copy[i][j][k];
	}
	int output = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			output += arr[i][j][0];

	cout << output;

	return 0;
}