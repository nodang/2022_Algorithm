// 54분 4초
// 구현 문제 + 수학적인 사고

#include <iostream>
using namespace std;

typedef struct {
	int x, y;
} coord;

int N;
int A[500][500];
int check[500][500];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

// i = 0
int sand[10][3] = {
	{ -2, 0, 5 },
	{ -1, -1, 10 },
	{ -1, 1,10 },
	{ 0, -2, 2 },
	{ 0, -1, 7 },
	{ 0, 1, 7 },
	{ 0, 2, 2 },
	{ 1, -1, 1 },
	{ 1, 1, 1 },
	{ -1, 0, 0 }
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	coord tornado = { N/2, N/2 };
	check[tornado.y][tornado.x] = 1;
	int dir = 0, output = 0;
	while(!(tornado.x == 0 && tornado.y == 0))
	{
		int x = tornado.x + dx[dir], y = tornado.y + dy[dir];
		int head = dir;

		if (x < 0 || x >= N || y < 0 || y >= N)
		{
			dir = (dir + 1) % 4;
			continue;
		}

		if (check[y][x] == 0)
			dir = (dir + 1) % 4;
		else
		{
			dir = (dir - 1) % 4;
			if (dir < 0)
				dir += 4;
			continue;
		}

		tornado.x = x, tornado.y = y;
		check[y][x] = 1;
		
		int val = A[y][x];
		for (int i = 0; i < 10; i++)
		{
			int xx, yy;
			switch (head)
			{
			case 0:
				xx = x + sand[i][0], yy = y + sand[i][1];
				break;
			case 1:
				xx = x - sand[i][1], yy = y - sand[i][0];
				break;
			case 2:
				xx = x - sand[i][0], yy = y + sand[i][1];
				break;
			case 3:
				xx = x - sand[i][1], yy = y + sand[i][0];
				break;
			}
			int ratio = val * sand[i][2] / 100;

			if (i == 9)
				ratio = A[y][x];

			A[y][x] -= ratio;

			if (xx < 0 || xx >= N || yy < 0 || yy >= N)
			{
				output += ratio;
				continue;
			}

			A[yy][xx] += ratio;
		}
	}

	cout << output;

	return 0;
}