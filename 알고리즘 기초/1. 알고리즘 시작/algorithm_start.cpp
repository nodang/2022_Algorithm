/*
C++ �����

1. C++�� ��쿡�� scanf/printf,cin/cout�� ����� �� �ִ�.

2. cin/cout�� scanf/printf���� ������ ������, ��/����� ���� ������ ��쿡�� scanf/printf�� ����ϴ� ���� ����.

3. cin/cout�� ��� �Ʒ� �� ���� �߰��ϸ� scanf/printf��ŭ ��������.
ios_base::sync_with_stdio(false);
cin.tie(NULL);		//cin.tie(nullptr);
//cout.tie(NULL);		�� �� ���� �߰��ص� ����� ��������.

4. �� ��쿡�� cin/cout�� scanf/printf�� ���� ���� �ȵȴ�. ��, cin/cout�� ��� �Ѵ�.
*/
//A + B -3 ����
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
//A + B -4 ����
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
//A + B -2 ����
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
//A + B -5 ����
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
//A + B -6 ����
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
//A + B -7 ����
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
//A + B -8 ����
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