/*
��������� �հ� ���� ���� ���� ���ؼ� ū ������ �ٽ� ����
why?
���� ���� ���� ���ߴµ��� ���� ���� ������ ������ �ִ밪���� ������ �� ����

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