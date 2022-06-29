/*
최대값 문제라서 DP 적용이 어려웠음

뽑을 카드가 i개가 있을때
i보다 작은 j개의 카드팩 하나와 i - j개를 뽑을 때의 최대 가격의 합 중 최대값을 찾음
i가 증가함에 따라 i보다 작게 뽑았을 때의 최대 가격을 사용함으로 DP 문제라 볼 수 있음
*/

#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 	cout.tie(nullptr);

	int n;
	cin >> n;

	int arr[1001] = { 0, };
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int price[1001] = { 0, };
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			price[i] = price[i - j] + arr[j] > price[i] ? price[i - j] + arr[j] : price[i];

	cout << price[n];

	return 0;
}