#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n;
	cin >> n;

	int curr = n / 2, rmd = n % 2, cs = curr + rmd;
	for (int i = curr; i > 0; i--)
		for(int j = curr; j > 0; j--)
			cs += 2;
	cs += rmd;

	cout << cs;

	return 0;
}