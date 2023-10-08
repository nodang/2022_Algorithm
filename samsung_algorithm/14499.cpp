// 1시간 40분 45초
// 주사위의 규칙 찾는게 어려웠음
// 문제를 제대로 읽을 것;;

#include <iostream>
#include <deque>
using namespace std;

int N, M, x, y, K;
int arr[21][21];
deque<int> cmd;

int dx[] = { 0, 1, -1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };

int cube[7];

int top_case[7][7] = {
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 4, 2, 5, 3, 0 },
	{ 0, 3, 0, 6, 1, 0, 4 },
	{ 0, 5, 1, 0, 0, 6, 2 },
	{ 0, 2, 6, 0, 0, 1, 5 },
	{ 0, 4, 0, 1, 6, 0, 3 },
	{ 0, 0, 3, 5, 2, 4, 0 }
};

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	for (int i = 0; i < K; i++)
	{
		int cur;
		cin >> cur;
		cmd.push_back(cur);
	}

	int top = 1, right = 3;
	while (!cmd.empty())
	{
		int command = cmd.front();
		cmd.pop_front();

		int xx = x + dx[command], yy = y + dy[command];

		if (xx < 0 || xx >= M || yy < 0 || yy >= N)
			continue;

		x = xx, y = yy;
		int t = top, r = right;
		switch (command)
		{
		case 1:
			top = 7 - r;
			right = t;
			break;
		case 2:
			top = r;
			right = 7 - t;
			break;
		case 3:
			top = 7 - top_case[t][r];
			break;
		case 4:
			top = top_case[t][r];
			break;
		}
		
		if (arr[yy][xx] == 0)
			arr[yy][xx] = cube[7 - top];
		else
		{
			cube[7 - top] = arr[yy][xx];
			arr[yy][xx] = 0;
		}
		cout << cube[top] << '\n';
	}

	return 0;
}