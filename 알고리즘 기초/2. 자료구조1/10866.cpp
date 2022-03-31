#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> Q;
int D[10001];

struct Deque {
	int* adrs;
	void push_front(int x)	{
		int i;
		for (i = 0; adrs[i] != 0; i++)
			Q.push(adrs[i]);
		adrs[0] = x;
		for (i = 1; Q.size() != 0; i++) {
			adrs[i] = Q.front();
			Q.pop();
		}
	}
	void push_back(int x) {
		int i;
		for (i = 0; adrs[i] != 0; i++);
		adrs[i] = x;
	}
	int pop_front(void) {
		int rtn = front();
		if (rtn == -1)
			return -1;
		adrs[0] = 0;
		for (int i = 1; adrs[i] != 0; i++) {
			Q.push(adrs[i]);
			adrs[i] = 0;
		}
		for (int i = 0; Q.size() != 0; i++) {
			adrs[i] = Q.front();
			Q.pop();
		}
		return rtn;
	}
	int pop_back(void) {
		int rtn = front();
		if (rtn == -1)
			return -1;
		int i;
		for (i = 0; adrs[i] != 0; i++);
		rtn = adrs[--i];
		adrs[i] = 0;
		return rtn;
	}
	int size(void) {
		int i;
		for (i = 0; adrs[i] != 0; i++);
		return i;
	}
	int empty(void) {
		if (adrs[0] == 0)
			return 1;
		else
			return 0;
	}
	int front(void) {
		if (adrs[0] == 0)
			return -1;
		else
			return adrs[0];
	}
	int back(void) {
		if (adrs[0] == 0)
			return -1;
		int i;
		for (i = 0; adrs[i] != 0; i++);
		return adrs[--i];
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	Deque DQ;
	DQ.adrs = D;

	while (n--)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			int x;
			cin >> x;
			DQ.push_front(x);
		}
		else if (cmd == "push_back") {
			int x;
			cin >> x;
			DQ.push_back(x);
		}
		else if (cmd == "pop_front") {
			int rtn = DQ.pop_front();
			cout << rtn << '\n';
		}
		else if (cmd == "pop_back") {
			int rtn = DQ.pop_back();
			cout << rtn << '\n';
		}
		else if (cmd == "size") {
			int rtn = DQ.size();
			cout << rtn << '\n';
		}
		else if (cmd == "empty") {
			int rtn = DQ.empty();
			cout << rtn << '\n';
		}
		else if (cmd == "front") {
			int rtn = DQ.front();
			cout << rtn << '\n';
		}
		else {
			int rtn = DQ.back();
			cout << rtn << '\n';
		}
	}

	return 0;
}