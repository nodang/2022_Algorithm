#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str, st_str;
	cin >> str;
	int n, curcer = str.size();
	cin >> n;

	while (n--)
	{
		char ch, p_ch;
		cin >> ch;
		if (ch == 'L') {
			if (curcer == 0);
			else {
				st_str.push_back(str.at(--curcer));
				str.pop_back();
			}
		}
		else if (ch == 'D') {
			if (curcer == (str.size() + st_str.size()));
			else {
				str.push_back(st_str.back());
				st_str.pop_back();
				curcer++;
			}
		}
		else if (ch == 'B') {
			if (curcer == 0);
			else {
				str.pop_back();
				curcer--;
			}
		}
		else if (ch == 'P') {
			cin >> p_ch;
			str.push_back(p_ch);
			curcer++;
		}
	}
	while (st_str.empty() != 1)
	{
		str.push_back(st_str.back());
		st_str.pop_back();
	}

	cout << str;

	return 0;
}