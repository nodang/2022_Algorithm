#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;

	int out = 1, zero = 0;
	for (int i = 1; i <= n; i++) {
		out *= i;
		while (out % 10 == 0) {
			out /= 10;
			zero++;
		}
		if(out % 10 != 0)
			out = out % 1000;	//500���� Ŀ����
	}
	cout << zero;

	return 0;
}