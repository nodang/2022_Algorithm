#include <iostream>
using namespace std;

int prime[1000001], check[1000001];

bool func(int n, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if (check[n - prime[i]] == false)
		{
			cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
			return true;
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 0;
	for (int i = 2; i <= 1000000; i++)
	{
		if (check[i] == 0)
		{
			if(i != 2)
				prime[cnt++] = i;
			for (int j = i * 2; j <= 1000000; j += i)
				check[j] = 1;
		}
	}

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;

		if (func(n, cnt) == false)
			cout << "Goldbach's conjecture is wrong.\n";	
	}

	return 0;
}