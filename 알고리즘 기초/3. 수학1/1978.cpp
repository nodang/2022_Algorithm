#include <iostream>
#include <stack>
using namespace std;

stack <int> s, ss;

int d[100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, cnt = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		s.push(i);
	}

	for (int i = 2; s.size() != 0;) {
		if (d[s.top()] != 1) {
			while (s.size() != 0) {
				if (d[s.top()] % i == 0) {
					if (d[s.top()] <= i) {
						s.pop();
						cnt++;
					}
					else
						s.pop();
				}
				else {
					ss.push(s.top());
					s.pop();
				}
			}
			if (ss.size() != 0) {
				while (ss.size() != 0) {
					s.push(ss.top());
					ss.pop();
				}
				i++;
			}
		}
		else
			s.pop();
	}

	cout << cnt;

	return 0;
}