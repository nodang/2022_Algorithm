#include <iostream>
using namespace std;

int arr[100001];

int main(void)
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		arr[i] = i;

	for (int i = 1; i <= N; i++)
	{
		int min = N;
		for (int j = 1; j * j <= i; j++)
		{
			int curr = j * j;
			min = min > arr[i - curr] + 1 ? arr[i - curr] + 1 : min;
		}
		arr[i] = min;
	}

	cout << arr[N];

	return 0;
}