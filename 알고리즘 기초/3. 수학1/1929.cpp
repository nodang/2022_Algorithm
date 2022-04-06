#include <iostream>
#include <queue>
using namespace std;

queue <int> q, out;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = n; i <= m; i++) {
		if(i != 1)
			q.push(i);
	}
	
	int i = 2;
	int size = q.size();
	while (q.size() != 0 && i <= 1000) {
		size = q.size();
		while (size--) {
			if (q.front() <= i) {
				cout << q.front() << '\n';
				q.pop();
			}
			else {
				if (q.front() % i != 0)
					q.push(q.front());
				q.pop();
			}
		}
		i++;
	}

	while (q.size() != 0) {
		cout << q.front() << '\n';
		q.pop();
	}

	return 0;
}