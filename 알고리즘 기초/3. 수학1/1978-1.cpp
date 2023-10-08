#include <iostream>
using namespace std;

bool prime(int n)
{
	if (n < 2)
		return false;
	else
	{
		for (int i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
				return false;
		}
		return true;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, cnt = 0;
	cin >> T;
	
	while (T--)
	{
		int n;
		cin >> n;

		cnt += prime(n);
	}

	cout << cnt;

	return 0;
}