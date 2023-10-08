#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int arr[9] = { 0, };
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	
	sort(arr, arr + 9);

	int check[7] = { 0, };
	for (int i = 0; i < 7; i++)
		check[i] = i;
	while (1)
	{
		int sum = 0;
		
		for(int i = 0; i < 7; i++)
			sum += arr[check[i]];

		if (sum == 100)
			break;

		for (int i = 0; i < 7; i++)
		{
			if (check[6 - i] != 8 - i)
			{
				check[6 - i]++;

				for(int j = 6 - i + 1; j < 7; j++)
					check[j] = check[j - 1] + 1;

				break;
			}
		}
	}
	
	for (int i = 0; i < 7; i++)
		cout << arr[check[i]] << '\n';

	return 0;
}