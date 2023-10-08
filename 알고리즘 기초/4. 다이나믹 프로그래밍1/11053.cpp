// 1시간 10분 6초
// 정석적인 bfs. deque로 구현하면 메모리 초과됨
// 최소한의 함수 호출로 구현해야하므로 배열에 최대값을 저장하면서 bfs를 진행함

#include <iostream>
using namespace std;

int N;
int arr[1000];
int check[1000];

void func(int ind, int cnt)
{
	for (int i = 1; i < N - ind; i++)
		if (arr[ind] < arr[ind + i])
			check[ind + i] = cnt + 1 > check[ind + i] ? cnt + 1 : check[ind + i];
} 

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i = 0; i < N; i++)
		func(i, check[i]);

	int rtn = 0;
	for (int i = 0; i < N; i++)
		rtn = rtn > check[i] ? rtn : check[i];

	cout << rtn + 1;

	return 0;
}