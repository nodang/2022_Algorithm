/*
이전 배열에서의 숫자 조합에 따른 2차원 배열을 생성

오버플로우에 유의할 것!
*/

#include <iostream>
using namespace std;

unsigned int arr[100001][4] = { {0, }, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);		cout.tie(nullptr);

	int N;
	cin >> N;
	while (N--)
	{
		int n;
		cin >> n;

		arr[1][1] = 1;
		arr[2][1] = 0;	arr[2][2] = 1;
		arr[3][1] = 1;	arr[3][2] = 1;	arr[3][3] = 1;

		arr[4][1] = 2;	arr[4][2] = 0;	arr[4][3] = 1;
		arr[5][1] = 1;	arr[5][2] = 2;	arr[5][3] = 1;

		for (int i = 4; i <= n; i++)
		{
			arr[i][1] = (arr[i - 1][2] + arr[i - 1][3]) % 1000000009;
			arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) % 1000000009;
			arr[i][3] = (arr[i - 3][1] + arr[i - 3][2]) % 1000000009;
		}
		int curr = (arr[n][1] + arr[n][2] + arr[n][3]) % 1000000009;
		cout << curr << '\n';
	}
	return 0;
}