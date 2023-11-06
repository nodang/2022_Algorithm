// 1�ð� 17�� 21��
// �����ϴ� dx dy�� �켱������ �ΰ� Ǯ�� ������ Ǯ���µ� �ش� ������ �ƴѵ�..
// �ᱹ ��� �°��� ���ؼ� �ִ� �Ÿ��� �����ϰ� sort�ϴ� ������� ����

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
	// ������ ���� true -> E = -1 ����
	// dist == -1�̸� ��θ� ã�� ����
	// ������ ��� false
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
	// �մ��� ã�� �ý��� ��ǥ�� ����, �Ÿ� ���
	// �ý��� ��ǥ�� �ٷ� �մ��� �������� �����ص� �� -> ������ �մ����ױ��� ������ ����Ǵϱ�
	// ã���� �ýô� �մ� ��ġ�� �̵��ϰ� �̵��� �Ÿ� ��ȯ�ϰ� �մ��� �������� �� �غ�
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
	//���������� �ִܰ�θ� ã�� �Ÿ� ���
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

	// 1 ��, 10�̻� �°�, ������ ǥ�� ����
	// 1. ���� ����� �°��� �¿�� �������� �̵�
	// 1-1. �°����� �̵��� �� ������ -1 ��ȯ
	// 1-2. �°��� �¿�� �������� �̵��� �� ������ -1 ��ȯ
	// 2. �������� �̵��ϸ� �̵��� �Ÿ��� ������ŭ ���� ����
	// 3. ��� �°��� �̵���Ű��� �����ϰ� ���� ���� ��ȯ

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