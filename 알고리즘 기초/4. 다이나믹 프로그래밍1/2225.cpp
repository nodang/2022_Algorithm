/*
K개의 공간을 중복하여 N번 선택하여 숫자를 1씩 넣는 문제로 해석가능

N + (K - 1)개의 공간에 순서없이 (K - 1)개의 칸막이를 놓는 문제 

for (ULL i = N + 1; i <= N + K - 1; i++)
	result = (result * i / (i - N)) % MOD;

해당 식은 "/ (i - N)"에 의해 나머지가 생길 수 있기 때문에 성립할 수 없음

해당 식을 1씩 낮추어 N = 1, K = 0일 때부터 생각해보자
H{1, K} 부터 H{1, 1} 까지 더하면 K(K + 1)/2 이다
H{2, K} 가 K(K + 1)/2 이므로 H{N, K} 은 H{N - 1, K} 부터 H{N - 1, 1} 까지 더한 것인데
매번 더하는 것은 시간 복잡도가 높다 -> 어떻게 해결하지? -> H{N, K - 1} 은 H{N - 1, K - 1} 부터 H{N - 1, 1} 까지 더한 것

그러면 H{N, K} 은 H{N - 1, K} + H{N, K - 1} 일듯
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