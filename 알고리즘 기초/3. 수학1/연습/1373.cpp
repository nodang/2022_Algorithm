#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	string line;
	getline(cin, line);

	int size = line.size();
	int first_computing = size % 3;

	int i = 0, sum = 0;
	for (i = 0; i < first_computing; i++) {
		int curr = line.at(i) - 48;
		sum += curr * pow(2, first_computing - 1 - i);
	}
	if (sum != 0 || size == 1)
		cout << (char)(sum + 48);
	while (i < size) {
		sum = 0;
		for (int j = i; j < i + 3; j++) {
			int curr = line.at(j) - 48;
			sum += curr * pow(2, i + 2 - j);
		}
		i += 3;
		cout << (char)(sum + 48);
	}
	cout << '\n';

	return 0;
}