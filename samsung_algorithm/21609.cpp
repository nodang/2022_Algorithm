// BFS를 사용하는 구현문제 : 2시간 5분 46초 
// 2번째 풀이인데 2시간? 망했다

#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct {
	int x, y, size, raindows;
} save;

int N, M;
int arr[21][21];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1 ,0 };

bool cmp(const save& a, const save& b)
{
	if (a.size > b.size)
		return true;
	else if (a.size == b.size)
	{
		if (a.raindows > b.raindows)
			return true;
		else if (a.raindows == b.raindows)
		{
			if (a.y > b.y)
				return true;
			else if (a.y == b.y)
				if (a.x > b.x)
					return true;
		}
	}

	return false;
}

void rotate_array()
{
	int copy[21][21];
	memcpy(copy, arr, sizeof(arr));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int y = (N - 1) - j;
			arr[y][i] = copy[i][j];
		}
}

void delete_group(int x, int y)
{
	int check[21][21] = { { 0, }, };

	deque< pair<int, int> > dq;
	dq.push_back({ x, y });
	check[y][x] = 1;
	
	int color = arr[y][x];
	arr[y][x] = -2;

	while (!dq.empty())
	{
		int xxx = dq.front().first, yyy = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int xx = xxx + dx[i], yy = yyy + dy[i];

			if (xx < 0 || xx >= N || yy < 0 || yy >= N)
				continue;

			if (check[yy][xx] == 0 && (arr[yy][xx] == color || arr[yy][xx] == 0))
			{
				check[yy][xx] = 1;
				dq.push_back({ xx, yy });
				arr[yy][xx] = -2;
			}
		}
	}
}

save find_group(int x, int y)
{
	int check[21][21] = { { 0, }, };

	save cur = { x, y, 1, 0 };

	deque< pair<int, int> > dq;
	dq.push_back({ x, y });
	check[y][x] = 1;

	int color = arr[y][x];

	while (!dq.empty())
	{
		int xxx = dq.front().first, yyy = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int xx = xxx + dx[i], yy = yyy + dy[i];

			if (xx < 0 || xx >= N || yy < 0 || yy >= N)
				continue;

			if (check[yy][xx] == 0 && (arr[yy][xx] == color || arr[yy][xx] == 0))
			{
				check[yy][xx] = 1;
				cur.size++;
				dq.push_back({ xx, yy });

				if(arr[yy][xx] == 0)
					cur.raindows++;
				else
				{
					if (cur.y > yy)
						cur.x = xx, cur.y = yy;
					else if (cur.y == yy)
					{
						if(cur.x > xx)
							cur.x = xx, cur.y = yy;
					}
				}
			}
		}
	}

	return cur;
}

void gravity()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			if (arr[j][i] == -2)
				for (int k = j - 1; k >= 0; k--)
				{
					if (arr[k][i] == -1)
						break;
					
					if (arr[k][i] == -2)
						continue;

					arr[j][i] = arr[k][i];
					arr[k][i] = -2;
					break;
				}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	unsigned long long score = 0;
	while (1)
	{
		// 1. 큰 블록 그룸 찾기, 개수가 같으면 무지개 블록 수가 많은 그룸, 그것도 같으면 블록의 행이 가장 큰, 그것도 같으면 열이 가장 큰
		deque<save> dq;
		for(int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (arr[i][j] > 0)
				{
					save cur = find_group(j, i);
					
					if (cur.size > 1)
						dq.push_back(cur);
				}

		if (dq.empty())
			break;

		sort(dq.begin(), dq.end(), cmp);
		save g = dq.front();
		// 2. 찾은 블록 제거, 제거한 블록 수의 제곱을 점수로 합산
		score += g.size * g.size;
		delete_group(g.x, g.y);
		// 3. 중력
		gravity();
		// 4. 격자 90도 반시계 회전
		rotate_array();
		// 5. 중력
		gravity();
		/*
		cout << '\n';
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout <<  arr[i][j] << "          ";
			cout << '\n';
		}
		cout << g.size * g.size << '\n';
		*/
	}

	cout << score;

	return 0;
}