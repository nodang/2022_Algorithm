/*

�ִ� �н��� ã�� ����
��� ����� �� �� ���� �۰� �����ϴ� ��츦 ���Ѵ�. ����? �迭��
������ ����ߴ� ��츦 �״�� �����ٰ� ���ؼ� �̹� �迭�� ����Ѵ�.

�ش� ������ X�� 1�� ����� ���������� �ݴ�� 1�� X�� ����� �����ε� �� �� �ִ�.
1�� X�� ���� �� �� ���ڿ� ������ ���� �ּ��� ����� ������ �����ϸ鼭 ���ڸ� X���� ����� �ȴ�!

*/

#include <iostream>
using namespace std;

#define N 1000000

int d[N] = { 0, };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int x, i = 0;
	cin >> x;

	for (i = 2; i <= x; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2])
			d[i] = d[i / 2] + 1;
		if (i % 3 == 0 && d[i] > d[i / 3])
			d[i] = d[i / 3] + 1;
	}

	cout << d[x];
	
	return 0;
}