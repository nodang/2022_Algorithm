/*
DP������ DP�� Ǯ��� ���� ��Ȯ��

�ش� ������ ������ Ǯ �� �ִµ�
�� ���̽����� ���� ���ٰ� ���η� ������ ���� ����� ���� ����

a(n) = a(n-2) + a(n-1) �� ��ȭ���� �����ϴ� ������
n��° ���̽��� n-1��° ���̽��� ���� ������ �߰��ϴ� �Ͱ�
n-2��° ���̽����� ���� �� ���� �߰��ϴ� ���� ���� �����ϱ� ����
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