// 备泅 巩力 : 37盒 50檬

#include <iostream>
using namespace std;

typedef struct {
	int x, y, d;
}robot;

int N, M;
int room[51][51];
robot R;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	cin >> R.y >> R.x >> R.d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> room[i][j];

	while (1)
	{
		// 1. 没家
		if (room[R.y][R.x] == 0)
		{
			room[R.y][R.x] = 2;
			cnt++;
		}
		else
		{
			bool cleanable = false;
			for (int i = 0; i < 4; i++)
			{
				int x = R.x + dx[i], y = R.y + dy[i];

				if(room[y][x] == 0)
					cleanable = true;
			}

			// 2. 后 沫 绝澜
			if (cleanable == false)
			{
				int d = (R.d + 2) % 4;
				int x = R.x + dx[d], y = R.y + dy[d];

				if (room[y][x] == 1)
					break;
				else
					R.x = x, R.y = y;
			}
			// 3. 后 沫 乐澜
			else
			{
				int x, y;
				do {
					R.d--;
					R.d = (R.d + 4) % 4;
					x = R.x + dx[R.d], y = R.y + dy[R.d];
				} while (room[y][x] != 0);

				R.x = x, R.y = y;
			}
			/*
			cout << '\n';
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
					cout << room[i][j] << ' ';
				cout << '\n';
			}
			cout << '\n';
			*/
		}
	}

	cout << cnt;

	return 0;
}