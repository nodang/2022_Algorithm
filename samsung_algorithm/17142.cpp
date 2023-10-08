// bfs, ���� �� �б� : 53�� 28��
// Ȱ���� �ֵ鸸 ����ϴ°� �ƴ� ��Ȱ���� Ȱ���� ������ �Ѿ �� �ִ°��� ����߾����
// ����, �ð��� �� �� ó������ �����ϳ� �����ϴ� ������ ������ �� ��

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

#define MM 100000000

typedef struct {
	int x, y, cnt;
}coord;

int N, M;
int arr[51][51];
deque<coord> dq;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int num;

int bfs(deque<coord>& curr)
{
	int check[51][51] = { { 0, }, };
	int m = 0, comp = 0;

	for (int i = 0; i < curr.size(); i++)
		check[curr[i].y][curr[i].x] = -1;

	while (!curr.empty())
	{
		int x = curr.front().x, y = curr.front().y, cnt = curr.front().cnt + 1;
		curr.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i], yy = y + dy[i];

			if (xx < 0 || xx >= N || yy < 0 || yy >= N)
				continue;

			if (arr[yy][xx] == 0 && (check[yy][xx] > cnt || check[yy][xx] == 0))
			{
				if (check[yy][xx] == 0)
					comp++;

				check[yy][xx] = cnt;
				m = max(m, cnt);
				curr.push_back({ xx, yy, cnt });
			}
			else if (arr[yy][xx] == 2 && check[yy][xx] != -1)
			{
				check[yy][xx] = -1;
				curr.push_back({ xx, yy, cnt });
			}
		}
	}
	if (comp == num)
		return m;
	else
		return MM;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				dq.push_back({ j, i, 0 });
			else if (arr[i][j] == 0)
				num++;
		}

	vector<int> collect;
	for (int i = 0; i < dq.size(); i++)
	{
		if (i < M)
			collect.push_back(1);
		else
			collect.push_back(0);
	}

	int output = MM;
	do {
		deque<coord> curr;
		for (int i = 0; i < dq.size(); i++)
		{
			if (collect[i] == 1)
				curr.push_back(dq[i]);
		}

		int time = bfs(curr);
		output = min(output, time);

	} while (prev_permutation(collect.begin(), collect.end()));

	if (output == MM)
		output = -1;

	cout << output;

	return 0;
}