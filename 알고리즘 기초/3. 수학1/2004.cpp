#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;

	int n_r = n - m;

	int cnt2[2] = { 0, 0 }, cnt5[2] = { 0, 0 };

	int n_ = n;
	while (n_ > 1) {
		n_ /= 2;
		cnt2[0] += n_;
	}
	n_ = n;
	while (n_ > 1) {
		n_ /= 5;
		cnt5[0] += n_;
	}
	int m_ = m;
	while (m_ > 1) {
		m_ /= 2;
		cnt2[1] += m_;
	}
	m_ = m;
	while (m_ > 1) {
		m_ /= 5;
		cnt5[1] += m_;
	}
	int nr = n_r;
	while (nr > 1) {
		nr /= 2;
		cnt2[1] += nr;
	}
	nr = n_r;
	while (nr > 1) {
		nr /= 5;
		cnt5[1] += nr;
	}

	int cnt_2 = cnt2[0] - cnt2[1], cnt_5 = cnt5[0] - cnt5[1];
	int rst = cnt_2 > cnt_5 ? cnt_5 : cnt_2;

	cout << rst;

	return 0;
}