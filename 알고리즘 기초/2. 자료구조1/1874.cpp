#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> st;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string str;
	int n = 0, num = 1, goal = 0, err = 0;
	cin >> n;

	while (n--)
	{
		cin >> goal;

		while (num <= goal) {
			st.push(num++);
			str += "+\n";
		}
		if (st.top() == goal) {
			st.pop();
			str += "-\n";
		}
		else if (st.top() > goal)
			err = -1;
	}
	if (err != 0)
		cout << "NO\n";
	else
		cout << str;

	return 0;
}