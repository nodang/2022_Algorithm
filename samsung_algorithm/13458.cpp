// 18분 17초
// 쉬울 수록 방심 금지
// people <= 0 인 경우를 왜 생각못했지?

#include <iostream>
using namespace std;

int N, B, C;
int arr[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> B >> C;

	unsigned long long score = 0;
	for (int i = 0; i < N; i++)
	{
		int people = arr[i] - B;
		score++;

		if (people <= 0)
			continue;

		int mod = people % C;
		unsigned long long val = people / C;
		if (mod != 0)
			score += val + 1;
		else
			score += val;
	}

	cout << score;

	return 0;
}