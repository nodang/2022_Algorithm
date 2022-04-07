#include <iostream>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;

	int out = 1;
	for (int i = 1; i <= n; i++)
		out *= i;

	cout << out;

	return 0;
}
