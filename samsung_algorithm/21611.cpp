// 2시간 5초
// 잔실수 금지
// 예외 상황 캐치하는 능력 부족..

#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

typedef struct {
	int d, s;
} magic;

int N, M;
int arr[50][50];
int ball_n;

deque<magic> dq1;
deque<int> dq2;

int dx_m[] = { 0, 0, 0, -1, 1 };
int dy_m[] = { 0, -1, 1, 0, 0 };

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0)
				ball_n++;
		}

	for (int i = 0; i < M; i++)
	{
		magic m;
		cin >> m.d >> m.s;
		dq1.push_back(m);
	}

	int x = N / 2, y = N / 2;
	int score = 0;
	while (!dq1.empty())
	{
		// 마법 사용
		magic m = dq1.front();
		dq1.pop_front();
		{
			int xx = x, yy = y;
			for (int i = 0; i < m.s; i++)
			{
				xx += dx_m[m.d], yy += dy_m[m.d];
				if (arr[yy][xx] != 0)
					ball_n--;
				arr[yy][xx] = 0;
			}
		}

		// dq2 최신화
		{
			int xx = x, yy = y, dir = 0;
			int check[50][50] = { { 0, }, };
			check[yy][xx] = 1;
			dq2.clear();
			while(dq2.size() != ball_n)
			{
				int xxx = xx + dx[dir], yyy = yy + dy[dir];

				if (xxx < 0 || xxx >= N || yyy < 0 || yyy >= N)
				{
					dir = (dir + 1) % 4;
					continue;
				}

				if (check[yyy][xxx] == 0)
				{
					dir = (dir + 1) % 4;
					if(arr[yyy][xxx] != 0)
						dq2.push_back(arr[yyy][xxx]);
					check[yyy][xxx] = 1;
					xx = xxx, yy = yyy;
				}
				else
				{
					dir = (dir - 1) % 4;
					if (dir < 0)
						dir += 4;
					continue;
				}
			}
		}

		// dq2 에서 4개 이상 인접한 구슬 제거
		while (!dq2.empty())
		{
			bool browup = false;
			int color = dq2.back();
			int cnt = 1;
			for (int i = dq2.size() - 2; i >= 0; i--)
			{
				if (dq2[i] == color)
					cnt++;
				else
				{
					if (cnt >= 4)
					{
						browup = true;
						score += color * cnt;

						for (int j = 0; j < cnt; j++)
							dq2.erase(dq2.begin() + i + 1);
					}

					color = dq2[i];
					cnt = 1;
				}
			}
			if (cnt >= 4)
			{
				browup = true;
				score += color * cnt;

				for (int j = 0; j < cnt; j++)
					dq2.erase(dq2.begin());
			}
			if (!browup)
				break;
		}

		// 구슬 변형
		if (!dq2.empty())
		{
			deque<int> copy;
			int color = dq2.back();
			copy.push_front(color);
			int cnt = 1;
			for (int i = dq2.size() - 2; i >= 0; i--)
			{
				if (dq2[i] == color)
					cnt++;
				else
				{
					color = dq2[i];
					copy.push_front(cnt);
					copy.push_front(color);
					cnt = 1;
				}
			}
			copy.push_front(cnt);

			dq2 = copy;
		}

		// 배열에 재정렬
		{
			int xx = x, yy = y, dir = 0;
			int copy[50][50] = { { 0, }, };
			int check[50][50] = { { 0, }, };
			check[yy][xx] = 1;
			ball_n = 0;
			while (!dq2.empty())
			{
				int xxx = xx + dx[dir], yyy = yy + dy[dir];

				if (xxx < 0 || xxx >= N || yyy < 0 || yyy >= N)
				{
					dir = (dir + 1) % 4;
					continue;
				}

				if (check[yyy][xxx] == 0)
				{
					dir = (dir + 1) % 4;
					copy[yyy][xxx] = dq2.front();
					ball_n++;
					dq2.pop_front();
					check[yyy][xxx] = 1;
					xx = xxx, yy = yyy;
				}
				else
				{
					dir = (dir - 1) % 4;
					if (dir < 0)
						dir += 4;
					continue;
				}

				if (xx == 0 && yy == 0)
					break;
			}
			memcpy(arr, copy, sizeof(arr));
		}
	}
	cout << score;

	return 0;
}