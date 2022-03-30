#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int D[10001] = { 0, };

struct Queue {
	int* adrs;
	void push(int x) {
		int* curr = adrs;
		while (*curr != 0) curr++;
		*curr = x;
	}
	int pop(void) {
		int* curr = adrs;
		while (*curr == -1) curr++;
		int rtn = *curr;
		if (rtn == 0) {
			memset((void*)adrs, 0x00, sizeof(int) * 10001);
			return -1;
		}
		else {
			*curr = -1;
			return rtn;
		}
	}
	int size(void) {
		int* curr = adrs;
		int s = 0;
		while (*curr != 0) {
			curr++;
			s++;
		}
		curr = adrs;
		while (*curr == -1) {
			curr++;
			s--;
		}
		return s;
	}
	int empty(void) {
		int rtn = size();
		if (rtn == 0)
			return 1;
		else
			return 0;
	}
	int front(void) {
		int* curr = adrs;
		while (*curr == -1)	curr++;
		if (*curr == 0)
			return -1;
		else
			return *curr;
	}
	int back(void) {
		int* curr = adrs;
		while (*curr == -1)	curr++;
		while (*curr != 0) curr++;
		if (curr != adrs) {
			curr--;
			if (*curr == -1)
				return -1;
			else
				return *curr;
		}
		else
			return -1;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Queue Q;
	Q.adrs = D;

	int n;
	cin >> n;
	cin.ignore();

	while (n--)
	{
		string word;
		cin >> word;
		if(word == "push")	{
			int num;
			cin >> num;
			Q.push(num);
		}
		else if (word == "pop")
			cout << Q.pop() << '\n';
		else if (word == "size")
			cout << Q.size() << '\n';
		else if (word == "empty")
			cout << Q.empty() << '\n';
		else if (word == "front")
			cout << Q.front() << '\n';
		else
			cout << Q.back() << '\n';
	}

	return 0;
}