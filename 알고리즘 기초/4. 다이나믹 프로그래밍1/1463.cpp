/*

최단 패스를 찾는 문제
모든 경우의 수 중 가장 작게 도착하는 경우를 구한다. 뭘로? 배열로
이전에 계산했던 경우를 그대로 가져다가 비교해서 이번 배열에 사용한다.

해당 문제는 X를 1로 만드는 문제이지만 반대로 1을 X로 만드는 문제로도 볼 수 있다.
1를 X로 만들 때 각 숫자에 도착할 때의 최소의 경우의 수만을 저장하면서 숫자를 X까지 만들면 된다!

*/

#include <iostream>
using namespace std;

#define N 1000000

int d[N] = { 0, };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int x, i = 0;
	cin >> x;

	for (i = 2; i <= x; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2])
			d[i] = d[i / 2] + 1;
		if (i % 3 == 0 && d[i] > d[i / 3])
			d[i] = d[i / 3] + 1;
	}

	cout << d[x];
	
	return 0;
}