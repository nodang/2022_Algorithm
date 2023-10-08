// 58분 27초

#include <iostream>
#include <deque>
using namespace std;

int N, K;
int belt[201][2];
int choice;

deque<int> robot;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= 2 * N; i++)
		cin >> belt[i][0];

	choice = 1;
	

	int T = 1;
	while (1)
	{
		// 1. 벨트 회전
		choice = choice == 1 ? 2 * N : choice - 1;
		// 2. 로봇 이동
		if (!robot.empty())
		{
			int size = robot.size();
			for (int i = 0; i < size; i++)
			{
				int place = robot.front(); 
				robot.pop_front();
				
				int limit = (choice + N - 1) % (2 * N);
				limit = limit == 0 ? 2 * N : limit;

				if (place == limit)
				{
					belt[place][1] = 0;
					continue;
				}

				int next = place == 2 * N ? 1 : place + 1;
				if (belt[next][0] > 0 && belt[next][1] == 0)
				{
					belt[next][0]--;
					belt[place][1] = 0;
					belt[next][1] = 1;
					place = next;
				}

				if (place == limit)
				{
					belt[place][1] = 0;
					continue;
				}
				
				robot.push_back(place);
			}
		}
		// 3. 로봇 올림
		if (belt[choice][0] > 0)
		{
			belt[choice][0]--;
			belt[choice][1] = 1;
			robot.push_back(choice);
		}
		// 4. 내구도 체크
		int cnt = 0;
		for (int i = 1; i <= 2 * N; i++)
		{
			if (belt[i][0] == 0)
				cnt++;

			//cout << belt[i][0] << '(' << belt[i][1] << ") ";
		}
		//cout << '\n' << robot.size() << '\n';
		if (cnt >= K)
		{
			cout << T;
			break;
		}
		else
			T++;
	}
	
	return 0;
}