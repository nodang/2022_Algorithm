/*
K���� ������ �ߺ��Ͽ� N�� �����Ͽ� ���ڸ� 1�� �ִ� ������ �ؼ�����

N + (K - 1)���� ������ �������� (K - 1)���� ĭ���̸� ���� ���� 

for (ULL i = N + 1; i <= N + K - 1; i++)
	result = (result * i / (i - N)) % MOD;

�ش� ���� "/ (i - N)"�� ���� �������� ���� �� �ֱ� ������ ������ �� ����

�ش� ���� 1�� ���߾� N = 1, K = 0�� ������ �����غ���
H{1, K} ���� H{1, 1} ���� ���ϸ� K(K + 1)/2 �̴�
H{2, K} �� K(K + 1)/2 �̹Ƿ� H{N, K} �� H{N - 1, K} ���� H{N - 1, 1} ���� ���� ���ε�
�Ź� ���ϴ� ���� �ð� ���⵵�� ���� -> ��� �ذ�����? -> H{N, K - 1} �� H{N - 1, K - 1} ���� H{N - 1, 1} ���� ���� ��

�׷��� H{N, K} �� H{N - 1, K} + H{N, K - 1} �ϵ�
*/

#include <iostream>
using namespace std;

#define MOD 1000000000
#define ULL	unsigned long long

int main(void)
{
	int N, K;
	cin >> N >> K;

	ULL arr[201][201] = {0,};

	ULL result = 1;

	for (int i = 1; i <= K; i++)
		arr[1][i] = i;

	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= K; j++)
			arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % MOD;

	cout << arr[N][K];

	return 0;
}