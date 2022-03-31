#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> S;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	getline(cin, str);
	str += '\0';

	int i = 0;
	while (str[i] != '\0') {
		for (; str[i] != '<' && str[i] != '\0' && str[i] != ' '; i++) 
			S.push(str[i]);
		while (S.size() != 0) {
			cout << (char)S.top();
			S.pop();
		}
		if (str[i] == '<') {
			while (str[i] != '>')
				cout << str[i++];
			cout << str[i++];
		}
		else if (str[i] == ' ')
			cout << str[i++];
	}

	return 0;
}