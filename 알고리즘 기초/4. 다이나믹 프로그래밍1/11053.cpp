#include <iostream>
using namespace std;

int arr[1001] = { 0, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);		cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int curr;
		cin >> curr;
		arr[curr] = 1;
	}
	
	int result = 0;
	for (int i = 1; i < 1001; i++)
		result += arr[i];

	cout << result;

	return 0;
}