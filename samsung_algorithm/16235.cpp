// 3시간 22분 20초
// 시간초과 최적화 문제인데
// 시간초과 최적화하려고 구조를 바꾸는 순간 에러가 미친듯이 발생할 확률 높음 ㅋ
// 저번 상어 복제 문제랑 동일하게 같은 공간의 나이가 같은 나무는 동시에 계산되어야 함
// 추가적으로 일부가 죽을 수 있으므로 에러처리가 필요햇음

#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct {
	int x, y, age, cnt;
} tree;

int N, M, K;
int A[11][11];
int ground[11][11][2000];

deque<int> dq[11][11];
deque<tree> dead;

int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int cmp(const tree& a, const tree& b)
{
	if (a.age < b.age)
		return true;
	else if (a.age == b.age)
	{
		if (a.x < b.x)
			return true;
		else if (a.x == b.x)
			if (a.y < b.y)
				return true;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
			ground[i][j][0] = 5;
		}
	for (int i = 0; i < M; i++)
	{
		tree cur;
		cin >> cur.y >> cur.x >> cur.age;
		ground[cur.y][cur.x][cur.age]++;

		if (!binary_search(dq[cur.y][cur.x].begin(), dq[cur.y][cur.x].end(), cur.age))
		{
			dq[cur.y][cur.x].push_back(cur.age);
			sort(dq[cur.y][cur.x].begin(), dq[cur.y][cur.x].end());
		}
	}

	while (K--)
	{
		// 봄
		int grd[11][11][2000] = { { 0,}, };
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				grd[i][j][0] = ground[i][j][0];

				if (dq[i][j].empty())
					continue;

				int size = dq[i][j].size();
				sort(dq[i][j].begin(), dq[i][j].end(), less<>());
				for (int s = 0; s < size; s++)
				{
					int age = dq[i][j].front();
					dq[i][j].pop_front();

					if (grd[i][j][0] == 0)
					{
						dead.push_back({ j, i, age, ground[i][j][age] });
						continue;
					}

					if (!(grd[i][j][0] >= age * ground[i][j][age]))
					{
						int died = ground[i][j][age] - grd[i][j][0] / age;
						dead.push_back({ j, i, age, died });
						ground[i][j][age] = grd[i][j][0] / age;
					}

					if (ground[i][j][age] != 0)
					{
						grd[i][j][0] -= age * ground[i][j][age];
						grd[i][j][age + 1] = ground[i][j][age];
						dq[i][j].push_back(age + 1);
					}
				}
			}
		}
		memcpy(ground, grd, sizeof(ground));
		// 여름
		while (!dead.empty())
		{
			tree cur = dead.front();
			dead.pop_front();

			ground[cur.y][cur.x][0] += (cur.age / 2) * cur.cnt;
		}
		// 가을
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				for (int s = 0; s < dq[i][j].size(); s++)
				{
					if (dq[i][j][s] % 5 != 0)
						continue;

					for (int k = 0; k < 8; k++)
					{
						int x = j + dx[k], y = i + dy[k];

						if (x <= 0 || x > N || y <= 0 || y > N)
							continue;

						if (dq[y][x].empty() || dq[y][x].front() != 1)
							dq[y][x].push_front(1);

						ground[y][x][1] += ground[i][j][dq[i][j][s]];
					}
				}
			}
		}
		// 겨울
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				ground[i][j][0] += A[i][j];
#if 0
		cout << '\n';
		for (int k = 0; k < 10; k++)
		{
			cout << "age : " << k << '\n';
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
					cout << ground[i][j][k] << ' ';
				cout << '\n';
			}
			cout << "\n\n";
		}
		cout << '\n';
#endif
	}
	int score = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			while (!dq[i][j].empty())
			{
				int age = dq[i][j].front();
				dq[i][j].pop_front();

				score += ground[i][j][age];
			}
	cout << score;

	return 0;
}