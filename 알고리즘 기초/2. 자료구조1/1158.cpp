#include <iostream>
#include <string>
using namespace std;

int D[5001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	cout << '<';

	int num = 1;
	while (num <= n) {
		D[num] = num;
		num++;
	}

	int i = 1, j = 1;
	volatile int CNT = 0;
	num = 1;
	while (CNT < n)
	{
		j = i + k - 1;
		if (j > n)
			j -= n;

		while (CNT < n) {
			if (D[i] == 0) {
				if (j == n)
					j = 1;
				else
					j++;
				if (i == n)
					i = 1;
				else
					i++;
			}
			else {
				if (i == j)
					break;
				else {
					i++;
					if (i > n)
						i -= n;
				}
			}
		}

		num = D[i];
		D[i] = 0;

		CNT++;
		if (CNT == n)
			cout << num << '>';
		else
			cout << num << ", ";
	}

	return 0;
}