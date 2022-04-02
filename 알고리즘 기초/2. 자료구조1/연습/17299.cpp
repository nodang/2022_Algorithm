#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <int> s1;

int d[1000001];
int cnt[1000001];
int out[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> d[i];
		cnt[d[i]]++;
	}

	s1.push(0);
	for (int i = 0; i < n; i++) {
		while (!s1.empty() && cnt[d[s1.top()]] < cnt[d[i]]) {
			out[s1.top()] = d[i];
			s1.pop();
		}
		s1.push(i);
	}

	while (s1.size() != 0) {
		out[s1.top()] = -1;
		s1.pop();
	}

	for (int i = 0; i < n - 1; i++)
		cout << out[i] << ' ';
	cout << out[n - 1];

	return 0;
}