/*
	38% Time Over
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <int> S;

int D[1000000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> D[i];

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (D[i] < D[j]) {
				S.push(D[j]);
				break;
			}
		}
		if (S.size() != 0) {
			cout << S.top() << ' ';
			S.pop();
		}
		else
			cout << "-1 ";
	}

	return 0;
}