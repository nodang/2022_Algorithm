/*

-2������ �� �ڸ��� -2�� !
16 -8 4 -2 1
0  0  0  0 0

�������� ������ �Ǹ� �ȵǰ� ������ ����� �Ǿ�� �Ѵ�.

*/

#include <iostream>
#include <stack>
using namespace std;

stack <int> st;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int num;
	cin >> num;

	while (num) {
		int remainder = num % -2;
		num /= -2;
		if (remainder < 0) {
			remainder += 2;
			num++;
		}

		st.push(remainder);
	}

	do {
		if (st.empty())
			cout << 0;
		else {
			cout << st.top();
			st.pop();
		}
	} while (!st.empty());

	return 0;
}