// 1시간 39분 50초
// 배열 돌리기 및 배열 배치 구현문제

#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int N, K;
deque<int> arr[100];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void share_fish()
{
	int check[100][100] = { { 0,}, };
	deque<int> copy[100];
	for (int i = 0; i < N; i++)
		copy[i] = arr[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			check[j][i] = 1;
			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k], y = j + dy[k];

				if (x < 0 || x >= N || y < 0 || y >= arr[i].size())
					continue;

				if (y >= arr[x].size() || check[y][x] != 0)
					continue;

				int d = abs(arr[i][j] - arr[x][y]) / 5;

				if (d == 0)
					continue;

				if (arr[i][j] > arr[x][y])
				{
					copy[x][y] += d;
					copy[i][j] -= d;
				}
				else
				{
					copy[i][j] += d;
					copy[x][y] -= d;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
		arr[i] = copy[i];
}

void rollback()
{
	int front = 0;
	for (int i = 0; i < N; i++)
	{
		if (!arr[front].empty())
			break;

		while (!arr[i].empty() && front < i)
		{
			arr[front++].push_back(arr[i].front());
			arr[i].pop_front();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	
	int mm = 10000, MM = 0;
	for (int i = 0; i < N; i++)
	{
		int fish;
		cin >> fish;

		arr[i].push_back(fish);

		mm = min(fish, mm);
		MM = max(fish, MM);
	}

	int score = 0;
	while (MM - mm > K)
	{
		// 물고기 넣기
		for (int i = 0; i < N; i++)
			if (arr[i].back() == mm)
				arr[i].back()++;

		// 어항 쌍기
		arr[1].push_back(arr[0].back());
		arr[0].pop_back();
		bool turn_off = false;
		for (int i = 1; i < N; i++)
		{
			if (turn_off)
				break;

			int over2 = 0;
			for (int j = i; j < N; j++)
			{
				if (arr[j].size() > 1)
					over2++;
				else
					break;
			}

			int over = 0;
			for (int j = i + over2 - 1; j >= i && j < N; j--)
			{
				int size = arr[j].size() + over;
				if (j + size >= N)
				{
					turn_off = true;
					break;
				}

				while (!arr[j].empty())
				{
					size = arr[j].size() + over;
					arr[j + size].push_back(arr[j].back());
					arr[j].pop_back();
				}
				over++;
			}
		}
		// 물고기 재분배
		share_fish();
		// 어항 재배치
		rollback();
		// 어항 공중부양 2번
		for (int i = 0; i < N / 2; i++)
		{
			arr[(N - 1) - i].push_back(arr[i].back());
			arr[i].pop_back();
		}
		for (int i = N / 2; i < N; i++)
		{
			if (i >= (N + N / 2) / 2)
				break;

			while (!arr[i].empty())
			{
				arr[(N - 1) - (i - N / 2)].push_back(arr[i].back());
				arr[i].pop_back();
			}
		}
		// 물고기 재분배
		share_fish();
		// 어항 재배치
		rollback();

		// 최소 최대 찾기
		mm = 10000, MM = 0;
		for (int i = 0; i < N; i++)
		{
			mm = min(arr[i][0], mm);
			MM = max(arr[i][0], MM);
		}
		score++;
	}
	cout << score;

	return 0;
}