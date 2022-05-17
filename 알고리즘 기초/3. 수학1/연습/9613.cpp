/*

GCD : 최대 공약수 / Greatest Common Divisor

*/
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);
	
	int n;
	cin >> n;

	while (n--) {
		int m, i;
		cin >> m;
		
		int num[100] = { 0, };
		for (i = 0; m--; i++)
			cin >> num[i];
		m = i;

		long long sum = 0, rmd = 0;
		for (i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				int big, small, result = 0;
				num[i] > num[j] ? (big =  num[i], small = num[j]) : (big = num[j], small = num[i]);

				rmd = big % small;

				if (rmd == 0)
					result = small;
				else
					do {
						big% rmd == 0 && small % rmd == 0 ? result = rmd, rmd = 0 :
							big % rmd != 0 ? rmd = big % rmd : rmd = small % rmd;
					} while (rmd);
				
				sum += result;
			}
		}

		cout << sum << '\n';
		
	}

	return 0;
}

