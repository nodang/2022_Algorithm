// 1시간 35분 51초
// 단순 구현 문제 
// 복잡하게 생각하지 말고 일단 구현

#include<iostream>
#include<algorithm>
#include<deque>
#include<cstring>
using namespace std;

struct Coordinate {
	int x, y;
};

int N;
int student[401][4];
int space[21][21];

deque<int> dq;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

deque<Coordinate> choosen_space;

bool cmp(const Coordinate& a, const Coordinate& b)
{
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}

bool first_case(int& curr)
{
	int fav_cnt[21][21];
	int max_cnt = 0;

	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (space[i][j] != 0)
				continue;

			int cnt = 0;

			for (int k = 0; k < 4; k++)
			{
				int x = j + dx[k], y = i + dy[k];

				if (x < 1 || x > N || y < 1 || y > N)
					continue;

				for (int n = 0; n < 4; n++)
				{
					if (space[y][x] == student[curr][n])
						cnt++;
				}
			}

			fav_cnt[i][j] = cnt;
			if (cnt > max_cnt)
				max_cnt = cnt;
		}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (space[i][j] == 0 && fav_cnt[i][j] == max_cnt)
				choosen_space.push_back({ j, i });

	if (choosen_space.size() > 1)
		return false;
	else
		return true;
}

bool second_case(int& curr)
{
	int max_cnt = 0;
	int size = choosen_space.size();
	deque<Coordinate> copy_before;

	while (size--)
	{
		Coordinate temp = choosen_space.front();
		choosen_space.pop_front();

		int empty_cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int x = temp.x + dx[i], y = temp.y + dy[i];

			if (x < 1 || x > N || y < 1 || y > N)
				continue;

			if (space[y][x] == 0)
				empty_cnt++;
		}
		if (max_cnt <= empty_cnt)
		{
			if (max_cnt < empty_cnt)
			{
				max_cnt = empty_cnt;
				copy_before.clear();
			}
			copy_before.push_back(temp);
		}
	}

	choosen_space = copy_before;
	if (choosen_space.size() > 1)
		return false;
	else
		return true;
}

bool third_case(int& curr)
{
	sort(choosen_space.begin(), choosen_space.end(), cmp);

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N * N; i++)
	{
		int temp;
		cin >> temp;
		dq.push_back(temp);

		for (int j = 0; j < 4; j++)
			cin >> student[temp][j];
	}

	while (!dq.empty())
	{
		int curr = dq.front();
		dq.pop_front();

		choosen_space.clear();

		if (first_case(curr) || second_case(curr) || third_case(curr));

		space[choosen_space.front().y][choosen_space.front().x] = curr;
	}

	int cost = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			int cnt = 0;

			for (int k = 0; k < 4; k++)
			{
				int x = j + dx[k], y = i + dy[k];

				if (x < 1 || x > N || y < 1 || y > N)
					continue;

				for (int n = 0; n < 4; n++)
				{
					if (space[y][x] == student[space[i][j]][n])
						cnt++;
				}
			}

			if (cnt == 1)
				cost += 1;
			else if (cnt == 2)
				cost += 10;
			else if (cnt == 3)
				cost += 100;
			else if (cnt == 4)
				cost += 1000;
		}

	cout << cost;

	return 0;
}