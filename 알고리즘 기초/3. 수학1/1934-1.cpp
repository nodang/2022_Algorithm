#include <iostream>
using namespace std;

int gcb(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcb(b, a % b);
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int a, b;
		cin >> a >> b;

		long long g = gcb(a, b);
		long long l = a * b / g;

		cout << l << '\n';
	}

	return 0;
}