#include<iostream>
using namespace std;

int E, S, M;

int main(void)
{
	cin >> E >> S >> M;

	int cnt = 1;
	while (E != 1 || S != 1 || M != 1)
	{
		if (E > 1)
			E--;
		else
			E = 15;

		if (S > 1)
			S--;
		else
			S = 28;

		if (M > 1)
			M--;
		else
			M = 19;

		cnt++;
	}

	cout << cnt;

	return 0;
}