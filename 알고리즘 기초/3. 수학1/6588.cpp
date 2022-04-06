#include <iostream>
#include <queue>
using namespace std;

queue <int> Q,q;

int d[1000000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 5; i <= 1000000; i++) {
		if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
			Q.push(i);
	}

	int i = 2;
	while (1000 > i || !Q.size()) {
		if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0) {
			int size = Q.size();
			while (size--) {
				if (Q.front() <= i)
					q.push(Q.front());
				else
					if (Q.front() % i != 0)
						Q.push(Q.front());
				Q.pop();
			}
		}
		i++;
	}

	d[3] = 3; d[5] = 5; d[7] = 7;
	while(q.size() != 0) {
		d[q.front()] = q.front();
		q.pop();
	}
	while (Q.size() != 0) {
		d[Q.front()] = Q.front();
		Q.pop();
	}

	int num;
	do {
		cin >> num;
		if (num == 0)
			break;
		int out;
		for (int a = 0; a <= num; a++) {
			if(d[a] != 0 && d[num - a] != 0) {
				if (num == d[a] + d[num - a]) {
					cout << num << " = " << d[a] << " + " << d[num - a] << '\n';
					out = 1;
					break;
				}
			}
			if (out == 1)
				break;
			if (a == num) {
				cout << "Goldbach's conjecture is wrong.\n";
				break;
			}
		}

	} while (1);

	return 0;
}