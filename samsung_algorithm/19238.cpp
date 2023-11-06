// 1시간 17분 21초
// 접근하는 dx dy에 우선순위를 두고 풀면 보통은 풀리는데 해당 문제는 아닌듯..
// 결국 모든 승객에 대해서 최단 거리를 측정하고 sort하는 방식으로 구현

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<deque>
#include<queue>
#include<cmath>
#include<unordered_map>
using namespace std;

#define LL long long

struct Passenger {
	int sy, sx, gy, gx;
};

struct Coordinate {
	int x, y;
};

struct InQueue {
	int x, y;
	LL dist;
};

int N, M;
LL E;

int arr[22][22];
Coordinate taxi;
Coordinate taxi_goal;
unordered_map<int, Passenger> um;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool cmp(const InQueue& a, const InQueue& b)
{
	if (a.dist == b.dist)
	{
		if (a.y == b.y)
			return a.x < b.x;
		else
			return a.y < b.y;
	}
	else
		return a.dist < b.dist;
}

bool check_energy(LL dist)
{
	// 에너지 부족 true -> E = -1 대입
	// dist == -1이면 경로를 찾지 못함
	// 에너지 충분 false
	if (dist > E || dist == -1)
	{
		E = -1;
		return true;
	}
	else
	{
		E -= dist;
		return false;
	}
}

LL find_passenger()
{
	// 손님을 찾고 택시의 목표를 설정, 거리 계산
	// 택시의 목표를 바로 손님의 목적지로 설정해도 됌 -> 어차피 손님한테까지 못가면 종료되니깐
	// 찾으면 택시는 손님 위치로 이동하고 이동한 거리 반환하고 손님의 목적지로 갈 준비
	queue<InQueue> qu;
	LL rtn = 0;
	qu.push({ taxi.x, taxi.y, rtn });
	int check[22][22]{ 0 };
	check[qu.front().y][qu.front().x] = 1;

	deque<InQueue> sort_dq;

	while (!qu.empty())
	{
		InQueue curr = qu.front();
		qu.pop();

		if (arr[curr.y][curr.x] > 9)
			sort_dq.push_back(curr);

		for (int i = 0; i < 4; i++)
		{
			int x = curr.x + dx[i], y = curr.y + dy[i];

			if (x < 1 || x > N || y < 1 || y > N)
				continue;

			if (check[y][x] == 1 || arr[y][x] == 1)
				continue;

			check[y][x] = 1;
			qu.push({ x, y, curr.dist + 1 });
		}
	}

	if (sort_dq.empty())
		return -1;
	else
	{
		sort(sort_dq.begin(), sort_dq.end(), cmp);

		InQueue& curr = sort_dq.front();

		taxi = { curr.x, curr.y };
		taxi_goal = { um[arr[curr.y][curr.x]].gx, um[arr[curr.y][curr.x]].gy };
		rtn = curr.dist;

		arr[curr.y][curr.x] = 0;
		um.erase(arr[curr.y][curr.x]);

		return rtn;
	}
}

LL find_path()
{
	//목적지까지 최단경로를 찾고 거리 계산
	queue<InQueue> qu;
	LL rtn = 0;
	qu.push({ taxi.x, taxi.y, rtn });
	int check[22][22]{ 0 };
	check[qu.front().y][qu.front().x] = 1;

	bool found_flag = false;
	while (!qu.empty())
	{
		InQueue curr = qu.front();
		qu.pop();

		if (curr.x == taxi_goal.x && curr.y == taxi_goal.y)
		{
			found_flag = true;
			taxi = { curr.x, curr.y };
			rtn = curr.dist;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int x = curr.x + dx[i], y = curr.y + dy[i];

			if (x < 1 || x > N || y < 1 || y > N)
				continue;

			if (check[y][x] == 1 || arr[y][x] == 1)
				continue;

			check[y][x] = 1;
			qu.push({ x, y, curr.dist + 1 });
		}
	}
	if (found_flag)
		return rtn;
	else
		return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> E;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	{
		int x, y;
		cin >> y >> x;
		taxi = { x, y };
	}

	for (int i = 1; i <= M; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		arr[a][b] = i * 10;
		um[arr[a][b]] = { a, b, c, d };
	}

	// 1 벽, 10이상 승객, 목적지 표시 안함
	// 1. 가장 가까운 승객을 태우고 목적지로 이동
	// 1-1. 승객에게 이동할 수 없으면 -1 반환
	// 1-2. 승객을 태우고 목적지로 이동할 수 없으면 -1 반환
	// 2. 목적지로 이동하면 이동한 거리의 제곱만큼 연료 충전
	// 3. 모든 승객을 이동시키기면 종료하고 남은 연료 반환

	while (M--)
	{
		if (check_energy(find_passenger()))
			break;

		LL dist = find_path();

		if (check_energy(dist))
			break;

		E += 2*dist;
	}

	cout << E;

	return 0;
}