#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <double> s;

double d[26];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string str;
	cin >> str;

	for (int i = 0; i < n; i++)
		cin >> d[i];

	for (int i = 0; i < str.size(); i++) {
		char curr = str.at(i);
		if (curr <= 'Z' && curr >= 'A')
			s.push(d[curr - 'A']);
		else {
			double b = s.top();
			s.pop();
			double a = s.top();
			s.pop();
			double result;
			if (curr == '+')
				result = a + b;
			else if (curr == '-')
				result = a - b;
			else if (curr == '*')
				result = a * b;
			else //if (curr == '/')
				result = a / b;

			s.push(result);
		}
	}

	printf("%.2lf", (double)s.top());

	return 0;
}