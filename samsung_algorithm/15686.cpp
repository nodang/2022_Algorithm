// dfs문제 아닌데 낚임; 구현 문제 : 1시간 4분 43초

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

#define MM 250000000 

typedef struct {
	int x, y;
} coord;

int N, M;
int arr[51][51];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	deque<coord> chi;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			
			if (arr[i][j] == 2)
				chi.push_back({ j, i });
		}

	vector<int> collect;
	for (int i = 0; i < chi.size(); i++)
	{
		if (i < M)
			collect.push_back(1);
		else
			collect.push_back(0);
	}

	int score = MM;
	do {
		deque<coord> curr;
		for (int i = 0; i < chi.size(); i++)
		{
			if (collect[i] == 1)
				curr.push_back(chi[i]);
		}

		int score_cur = 0;
		for(int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] != 1)
					continue;

				int value = MM;
				for (int k = 0; k < curr.size(); k++)
				{
					int dist = abs(j - curr[k].x) + abs(i - curr[k].y);
					value = min(value, dist);
				}

				score_cur += value;
			}

		score = min(score, score_cur);

	} while (prev_permutation(collect.begin(), collect.end()));

	cout << score;

	return 0;
}