#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack <char> st;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	string input, output;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		int curr = input.at(i) -48, rmd = 0;
		for(int j = 0; j < 3; j++) {
			rmd = curr % 2;
			if (curr / 2 == 0)
				st.push(curr + 48);
			else
				st.push(rmd + 48);
			curr /= 2;
		}
		while (!st.empty()) {
			output += st.top();
			st.pop();
		}
	}
	if (output.at(0) != '1') {
		if (output.at(1) != '1')
			output = output.substr(2);
		else
			output = output.substr(1);
	}
	cout << output;

	return 0;
}