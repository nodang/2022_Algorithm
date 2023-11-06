// 1시간 47분 19초
// 3번째 풀이... 너무 오랜만에 해서 그런가

#include<iostream>
#include<algorithm>
#include<deque>
#include<queue>
#include<unordered_map>
#include<cstring>
using namespace std;

struct Coordinate {
	int x, y;
};

int N, M;
int arr[22][22];
int check[22][22];

deque<Coordinate> dq;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool cmp(const Coordinate &a, const Coordinate& b)
{
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}

bool find_block_group()
{
	dq.clear();
	memset(check, 0, sizeof(check));

	int max_rainbow_block = 0;
	deque<Coordinate> temp_dq;

	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == -2 || arr[i][j] == -1 || arr[i][j] == 0 || check[i][j] != 0)
				continue;

			deque<Coordinate> _dq;
			deque<Coordinate> _block;
			_dq.push_back({ j, i });
			_block = _dq;
			check[i][j] = 1;

			deque<Coordinate> rainbow_rollback;

			while (!_dq.empty())
			{
				Coordinate curr;
				curr = _dq.front();
				_dq.pop_front();

				for (int k = 0; k < 4; k++)
				{
					int x = curr.x + dx[k], y = curr.y + dy[k];

					if (x < 1 || x > N || y < 1 || y > N)
						continue;

					if (check[y][x] == 1)
						continue;

					if (arr[y][x] == arr[i][j] || arr[y][x] == 0)
					{
						if (arr[y][x] == 0)
							rainbow_rollback.push_back({ x, y });

						_dq.push_back({ x, y });
						_block.push_back({ x, y });
						check[y][x] = 1;
					}
				}
			}

			sort(_block.begin(), _block.end(), cmp);

			if (temp_dq.size() < _block.size())
			{
				max_rainbow_block = rainbow_rollback.size();
				temp_dq = _block;
			}
			else if (temp_dq.size() == _block.size())
			{
				if (max_rainbow_block < rainbow_rollback.size())
				{
					max_rainbow_block = rainbow_rollback.size();
					temp_dq = _block;
				}
				else if (max_rainbow_block == rainbow_rollback.size())
				{
					while (arr[_block.front().y][_block.front().x] == 0)
					{
						_block.push_back(_block.front());
						_block.pop_front();
					}

					if (temp_dq.front().y < _block.front().y)
						temp_dq = _block;
					else if (temp_dq.front().y == _block.front().y)
					{
						if(temp_dq.front().x < _block.front().x)
							temp_dq = _block;
					}
				}
			}

			while (!rainbow_rollback.empty())
			{
				Coordinate& curr = rainbow_rollback.front();
				check[curr.y][curr.x] = 0;
				rainbow_rollback.pop_front();
			}
		}

	if (temp_dq.size() < 2)
		return false;
	else
	{
		dq = temp_dq;
		return true;
	}
}

unsigned long long remove_block_group()
{
	unsigned long long rtn = dq.size();

	while (!dq.empty())
	{
		Coordinate& curr = dq.front();
		arr[curr.y][curr.x] = -2;		//mean empty
		dq.pop_front();
	}

	return rtn * rtn;
}

void gravity()
{
	for(int i = N - 1; i > 0; i--)
		for (int j = N; j > 0; j--)
		{
			if (arr[i][j] == -1 || arr[i][j] == -2)
				continue;

			int change_flag = 0;
			for (int k = i + 1; k <= N; k++)
			{
				if (arr[k][j] == -2)
					change_flag = 1;
				else
					break;

				if (change_flag && arr[k + 1][j] != -2)
				{
					arr[k][j] = arr[i][j];
					arr[i][j] = -2;
					break;
				}
			}
		}
}

void turn_90()
{
	int cpy_arr[22][22];
	memcpy(cpy_arr, arr, sizeof(cpy_arr));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			int x = ((i - 1) + N) % N + 1, y = (2 * N - j) % N + 1;
			arr[y][x] = cpy_arr[i][j];
		}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	unsigned long long score = 0;
	while (find_block_group())
	{
		score += remove_block_group();
		gravity();
		turn_90();
		gravity();
	}

	cout << score;

	return 0;
}