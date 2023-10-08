/*
현재까지의 합과 현재 더할 값을 비교해서 큰 값부터 다시 시작
why?
현재 더할 값을 더했는데도 현재 더할 값보다 작으면 최대값으로 도달할 수 없음

*/

#include <iostream>
using namespace std;

int n, arr[100000];

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int sum, max;
	sum = max = arr[0];
	for (int i = 1; i < n; i++)
	{
		sum += arr[i];
		//cout << sum << ' ' << max << '\n';
		if (sum < arr[i])
		{
			sum = arr[i];
		}

		if (max < sum)
		{
			max = sum;
		}
	}
	cout << max;

	return 0;
}