/*
�ִ밪 ������ DP ������ �������

���� ī�尡 i���� ������
i���� ���� j���� ī���� �ϳ��� i - j���� ���� ���� �ִ� ������ �� �� �ִ밪�� ã��
i�� �����Կ� ���� i���� �۰� �̾��� ���� �ִ� ������ ��������� DP ������ �� �� ����
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