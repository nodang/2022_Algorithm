#include<iostream>
using namespace std;

int M, N, x, y;

int main(void)
{
	int T;
	cin >> T;

	while (T--)
	{
		cin >> M >> N >> x >> y;

		int cnt = 0;

		int sum[2] = { 0 , 0 };
		while (M != N)
		{
			cnt += min(M, N);

			if (sum[0] > 40000 || sum[1] > 40000)
			{
				cnt = -1;
				break;
			}

			sum[0] += M;
			sum[1] += N;

			int ma = max(sum[0], sum[1]);
			int mi = min(sum[0], sum[1]);

			int temp = max(M, N) - (ma - mi);

			if (M > N && temp == x - y)
				break;
			else if (M < N && temp == y - x)
				break;
		}

		if (cnt != -1)
			cnt += M > N ? y : x;

		if (x == y)
			cnt = x;

		cout << cnt << '\n';
	}

	return 0;
}