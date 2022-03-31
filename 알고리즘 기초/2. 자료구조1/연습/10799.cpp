#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> S;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	int cnt = 0, n = 0;
	for (int i = 0; i < str.size(); i++) {
		char curr = str.at(i);
		if (curr == '(') {
			cnt++;
			S.push(curr);
		}
		else if (curr == ')') {
			cnt--;
			if (S.top() == ')') {
				n++;
				S.pop();
			}
			else {
				n += cnt;
				S.pop();
			}
			S.push(curr);
		}
	}

	cout << n;

	return 0;
}