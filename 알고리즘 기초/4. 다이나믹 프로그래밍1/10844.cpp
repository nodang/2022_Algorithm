/*
왠만하면 long long 을 써서 오버플로우를 방지할 것
*/

#include <iostream>
using namespace std;

long long arr[101][10] = { {0, }, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);		cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i < 10; i++)
		arr[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		arr[i][0] = arr[i - 1][1];

		for (int j = 1; j < 9; j++)
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
		
		arr[i][9] = arr[i - 1][8];
	}

	long long curr = 0;
	for (int i = 0; i < 10; i++)
		curr += arr[n][i] % 1000000000;
	curr %= 1000000000;

	cout << curr;

	return 0;
}