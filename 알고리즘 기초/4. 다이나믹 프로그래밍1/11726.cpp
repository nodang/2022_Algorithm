/*
DP문제는 DP로 풀어야 쉽고 정확함

해당 문제는 순열로 풀 수 있는데
각 케이스에서 가로 한줄과 세로로 두줄을 놓는 경우의 수가 있음

a(n) = a(n-2) + a(n-1) 의 점화식을 만족하는 이유는
n번째 케이스는 n-1번째 케이스에 가로 한줄을 추가하는 것과
n-2번째 케이스에서 가로 두 줄을 추가하는 것의 합을 만족하기 때문
*/

#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n;
	cin >> n;

	int arr[1001] = { 0, };

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= n; i++)
		arr[i] = (arr[i - 2] + arr[i - 1]) % 10007;

	int result = arr[n];
	result %= 10007;

	cout << result;

	return 0;
}