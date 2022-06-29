#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int N;
	cin >> N;

	while (N--)
	{
		int n;
		cin >> n;

		int arr[11] = { 0, };
		arr[0] = 1;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;

		for (int i = 3; i <= n; i++)
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

		cout << arr[n] << '\n';
	}

	return 0;
}