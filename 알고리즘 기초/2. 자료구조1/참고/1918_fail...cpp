#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <int> sn, sm, out;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
		sn.push(i);

	while (sn.size() != 0) {
		if (str.at(sn.top()) < 'A') {
			while (out.size() != 0) {
				sm.push(out.top());
				out.pop();
			}
			if (str.at(sm.top()) == '-' || str.at(sm.top()) == '+') {
				while (sm.size() != 0) {
					out.push(sm.top());
					sm.pop();
				}
				out.push(sn.top());
				sn.pop();
			}
			else {
				out.push(sn.top());
				sn.pop();
				while (sm.size() != 0) {
					out.push(sm.top());
					sm.pop();
				}
			}
		}
		else {
			out.push(sn.top());
			sn.pop();
		}
	}

	while (out.size() != 0) {
		cout << str.at(out.top());
		out.pop();
	}

	return 0;
}