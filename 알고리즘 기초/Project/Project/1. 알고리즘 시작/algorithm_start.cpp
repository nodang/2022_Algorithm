/*
C++ 입출력

1. C++의 경우에는 scanf/printf,cin/cout을 사용할 수 있다.

2. cin/cout은 scanf/printf보다 느리기 때문에, 입/출력이 많은 문제의 경우에는 scanf/printf를 사용하는 것이 좋다.

3. cin/cout의 경우 아래 세 줄을 추가하면 scanf/printf만큼 빨라진다.
ios_base::sync_with_stdio(false);
cin.tie(NULL);		//cin.tie(nullptr);
//cout.tie(NULL);		위 두 개만 추가해도 충분히 빨라진다.

4. 이 경우에는 cin/cout와 scanf/printf을 섞어 쓰면 안된다. 즉, cin/cout만 써야 한다.
*/
//A + B -3 문제
/*
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	int a[100], b[100], n;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		cin >> b[i];
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] + b[i] << '\n';
	}
	
	return 0;
}
*/
//A + B -4 문제
/*
#include <iostream>
using namespace std;

int main(void)
{
	int a, b;

	while (cin >> a >> b)
	{
		cout << a + b << '\n';
	}

	return 0;
}
*/
//A + B -2 문제
/*
#include <iostream>
using namespace std;

int main(void)
{
	int a, b;

	cin >> a;
	cin >> b;

	cout << a + b;

	return 0;
}
*/
//A + B -5 문제
/*
#include <iostream>
using namespace std;

int main(void)
{
	int a, b;

	while (cin >> a >> b)
	{
		if ((a == 0) && (b == 0))	break;

		cout << a + b << '\n';
	}

	return 0;
}
*/
//A + B -6 문제
/*
#include <iostream>
using namespace std;

int main(void)
{
	int a, b, n;
	char c;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> c >> b;

		cout << a + b << '\n';
	}

	return 0;
}
*/
//A + B -7 문제
/*
#include <iostream>
using namespace std;

int main(void)
{
	int a, b, n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		cout << "Case #" << i + 1 << ": " << a + b << '\n';
	}

	return 0;
}
*/
//A + B -8 문제
#include <iostream>
using namespace std;

int main(void)
{
	int a, b, n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		cout << "Case #" << i + 1 << ": " << a << " + "  << b << " = " << a + b << '\n';
	}

	return 0;
}