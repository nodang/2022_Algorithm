#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	cin >> n;

	while (n--)
	{
		char ch[52] = { 0, };
		cin >> ch;
		int cnt1 = 0, cnt2 = 0, right = 0;
		for (int i = 0; ch[i] != '\0'; i++)
		{
			if (ch[i] == '(') {
				cnt1++;
				right++;
			}
			else if (ch[i] == ')') {
				cnt2++;
				if(right > 0)
					right--;
			}
		}

		if (cnt1 == cnt2 && right == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}