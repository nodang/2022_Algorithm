/*

소수 구하기
두 개의 for문에서 각각의 개수의 곱은 소수가 아님

*/

#include <iostream>
#include <cmath>
using namespace std;

#define NUM 1000000

int prime[NUM] = { 0, };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n;
	cin >> n;

	prime[0] = -1;
	prime[1] = -1;
	for (int i = 2; i < sqrt(NUM); i++)
		for (int j = i; j * i < NUM; j++)
			prime[i * j] = -1;

	while (n--) {
		int number, partition_cnt = 0;
		cin >> number;

		for (int i = 2; i <= number / 2; i++) {
			if (prime[i] != -1 && prime[number - i] != -1)
				partition_cnt++;
		}

		cout << partition_cnt << '\n';
	}

	return 0;
}