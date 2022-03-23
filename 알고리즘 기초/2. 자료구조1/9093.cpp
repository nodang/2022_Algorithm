#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string str;

	cin >> n;
	cin.ignore();

	while (n--)
	{
		getline(cin, str);		//띄어쓰기를 지우지 않고 포함
		int size = str.size();
		char ch[1000] = { 0 , };
		int hold = 0;
		for (int i = 0; i < size; i++)
		{
			if (str[i] == ' ') {
				for (int j = i - 1; hold <= j; j--)
					strncat(ch, &str[j], 1);
				char space = ' ';
				strncat(ch, &space, 1);
				hold = i + 1;
			}
		}
		for (int j = size - 1; hold <= j; j--)
			strncat(ch, &str[j], 1);


		cout << ch << '\n';

	}

	return 0;
}