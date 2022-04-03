#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int i;
	cin >> i;

	while (i--) {
		int n, m;
		cin >> n >> m;

		int res1 = n > m ? n % m == 0 ? m : n % m : m % n == 0 ? n : m % n;
		while (n % res1 != 0 || m % res1 != 0) {
			int res2 = res1;
			if (n % res1 != 0)
				res2 = n % res1;
			if (m % res1 != 0)
				res2 = m % res1;
			res1 = res2;
		}

		int res3 = n * m / res1;
		cout << res3 << '\n';
	}

	return 0;
}