#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define CNT 1000000

stack <int> S;

int D[CNT];
int PRINT[CNT];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> D[i];

	for (int i = 0; i < n; i++) {
		if (S.size() == 0)
			S.push(i);
		while (S.size() != 0) {
			if (D[S.top()] < D[i]) {
				PRINT[S.top()] = D[i];
				S.pop();
			}
			else {
				PRINT[S.top()] = -1;
				break;
			}
		}
		S.push(i);
	}
	PRINT[n - 1] = -1;

	for (int i = 0; i < n; i++)
		cout << PRINT[i] << " ";
	cout << '\n';

	return 0;
}