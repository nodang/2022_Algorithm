#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int x;
	cin >> x;

	int cnt = 0;
	while (x != 1) {
		if ((x - 1) % 3 == 0) {
			cnt++;
			x--;
		}
		else if (x % 3 == 0) {
			cnt++;
			x /= 3;
		}
		else if (x % 2 == 0) {
			cnt++;
			x /= 2;
		}
		else {
			cnt++;
			x--;
		}
	}

	cout << cnt;

	return 0;
}