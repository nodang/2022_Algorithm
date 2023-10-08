#include <iostream>
using namespace std;

int prime[1000001], check[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> m >> n;

	int cnt = 0;
	for (int i = 2; i <= n; i++)
	{
		if (check[i] == 0)
		{
			prime[cnt++] = i;
			for (int j = i * 2; j <= n; j += i)
				check[j] = 1;
		}
	}

	int cur = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (prime[i] < m || prime[i] > n)
			continue;

		cout << prime[i] << '\n';
	}

	return 0;
}