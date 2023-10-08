#include<iostream>
using namespace std;

int N, M;
int arr[6], chk[10];

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int curr;
		cin >> curr;
		chk[curr] = 1;
	}

	int ans1 = 0, ans2 = 0;

	int n = N, tf = 1;
	while (tf)
	{
		int curr = n;
		for (int i = 0; i < 6; i++)
		{
			if (chk[curr % 10] != 0)
				break;

			curr /= 10;
			if (curr == 0)
			{
				tf = 0;
				ans1 = n;
				break;
			}
		}

		if (n >= 1000000)
		{
			ans1 = n;
			break;
		}

		n++;
	}

	n = N, tf = 1;
	while (tf)
	{
		int curr = n;
		for (int i = 0; i < 6; i++)
		{
			if (chk[curr % 10] != 0)
				break;

			curr /= 10;
			if (curr == 0)
			{
				tf = 0;
				ans2 = n;
				break;
			}
		}

		if (n <= 0)
		{
			ans2 = n;
			break;
		}

		n--;
	}

	int curr = ans1;
	ans1 = abs(ans1 - N);
	do
	{
		curr /= 10;
		ans1++;
	} while (curr);
	curr = ans2;
	if (ans2 < 10 && chk[ans2] == 1)
		ans2 = abs(ans2 - 100);
	else
		ans2 = abs(ans2 - N);
	do
	{
		curr /= 10;
		ans2++;
	} while (curr);

	int ans = abs(N - 100);
	if(M < 10)
		ans = min(ans, min(ans1, ans2));

	cout << ans;

	return 0;
}