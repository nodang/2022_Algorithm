// 27분 42초
// DP문제인듯

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[16], P[16];
int price[16];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];

	int M = 0;
	for (int i = 1; i <= N; i++)
	{
		price[i] += P[i];
		for(int j = i + T[i]; j <= N; j++)
			price[j] = max(price[j], price[i]);
		
		if(i + T[i] <= N + 1)
			M = max(price[i], M);
	}
	
	cout << M;

	return 0;
}