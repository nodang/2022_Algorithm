#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> Q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		Q.push(i);

	cout << '<';
	while (Q.size() != 0)
	{
		for (int i = k; i != 1; i--)
		{
			Q.push(Q.front());
			Q.pop();
		}
		if (Q.size() != 1)
			cout << Q.front() << ", ";
		else
			cout << Q.front() << '>';
		Q.pop();
	}

	return 0;
}