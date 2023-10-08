// 57분 15초
// 우선순위 큐 써보렬고 해쓴ㄴ데 못씀 ㅋㅋ

#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct {
	int num, times;
}info;

int r, c, k;
int A[101][101];

bool cmp(const info& a, const info& b)
{
	if (a.times < b.times)
		return true;
	else if (a.times == b.times)
		if (a.num < b.num)
			return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> A[i][j];

	int second = 0;
	int N = 3, M = 3;
	while (A[r][c] != k)
	{
		if (second >= 100)
		{
			second = -1;
			break;
		}
		int AA[101][101] = { { 0, }, };
		// C 연산
		if (N < M)
		{
			int MM_N = 0;
			for (int i = 1; i <= M; i++)
			{
				int check[100] = { 0, };
				deque<int> dq;
				for (int j = 1; j <= N; j++)
				{
					if (A[j][i] == 0)
						continue;

					check[A[j][i]]++;
					if (!binary_search(dq.begin(), dq.end(), A[j][i]))
					{
						dq.push_back(A[j][i]);
						sort(dq.begin(), dq.end());
					}
				}

				deque<info> dq_info;
				while (!dq.empty())
				{
					int num = dq.front();
					dq.pop_front();
					dq_info.push_back({ num, check[num] });
				}
				sort(dq_info.begin(), dq_info.end(), cmp);
				
				MM_N = max(MM_N, ((int)dq_info.size()) * 2);

				int ind = 1;
				while (!dq_info.empty())
				{
					if (ind == 100)
						break;
					info cur = dq_info.front();
					dq_info.pop_front();
					AA[ind++][i] = cur.num;
					AA[ind++][i] = cur.times;
				}
			}

			N = MM_N;
		}
		// R 연산
		else
		{
			int MM_M = 0;
			for (int i = 1; i <= N; i++)
			{
				int check[100] = { 0, };
				deque<int> dq;
				for (int j = 1; j <= M; j++)
				{
					if (A[i][j] == 0)
						continue;

					check[A[i][j]]++;
					if (!binary_search(dq.begin(), dq.end(), A[i][j]))
					{
						dq.push_back(A[i][j]);
						sort(dq.begin(), dq.end());
					}
				}

				deque<info> dq_info;
				while (!dq.empty())
				{
					int num = dq.front();
					dq.pop_front();
					dq_info.push_back({ num, check[num] });
				}
				sort(dq_info.begin(), dq_info.end(), cmp);

				MM_M = max(MM_M, ((int)dq_info.size()) * 2);

				int ind = 1;
				while (!dq_info.empty())
				{
					if (ind == 100)
						break;
					info cur = dq_info.front();
					dq_info.pop_front();
					AA[i][ind++] = cur.num;
					AA[i][ind++] = cur.times;
				}
			}

			M = MM_M;
		}
		memcpy(A, AA, sizeof(A));

		second++;
	}

	cout << second;

	return 0;
}