/*
��Ŭ���� ȣ����
���� ��� ������ �ִ� ������� ����

�����θ� ���������� ������ ����
���� ó���� �� �Ұ�
*/

#include <iostream>
using namespace std;

int p[100000] = { 0, };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, s;
	cin >> n >> s;
	
	int result = 0, small = 1000000000;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i] = abs(p[i] - s);
		if (small > p[i])
			small = p[i];
	}
	if (n == 1)
		result = p[0];
	else {
		int check = n;
		while (check) {
			for (int i = 0; i < n; i++) {
				if (p[i] != 0 && p[i] != small) {
					p[i] < small ? small = p[i] : p[i] %= small;
					if (p[i] == 0) {
						result = small;
						check--;
					}
				}
			}
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (p[i] == small || p[i] == 0)
					cnt++;
			}
			if (cnt == n)
				check = 0;
		}
	}
	cout << result << '\n';

	return 0;
}