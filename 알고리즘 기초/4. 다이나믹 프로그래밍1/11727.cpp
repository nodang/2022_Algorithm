#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);		cout.tie(nullptr);

	int n;
	cin >> n;

	int arr[1001] = { 0, };
	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= n; i++)
		arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % 10007;

	cout << arr[n];

	return 0;
}
