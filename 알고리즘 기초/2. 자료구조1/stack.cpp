/*
stack
push : �ڷḦ �ִ´�
pop : �ڷḦ ����

�ڷᱸ���� �ϳ��� ������� �ְ� ���� �׿��ִ� ������� ����.


*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Stack {
	int data[10000];
	int size;
	Stack()	{
		size = 0;
	}
	void push(int num) {
		data[size] = num;
		size += 1;
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			size -= 1;
			return data[size];
		}
	}
	int size() {
		if (empty()) {
			return -1;
		}
		else {
			return size;
		}
	}
	bool empty() {
		if (size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	int top() {
		if (empty()) {
			return -1;
		}
		else {
			return data[size - 1];
		}
	}
};

int main(void)
{
	int keyword_num = 0;
	char keyword_char[8] = { 0, };

	cin >> keyword_num;

	for (int i = 0; i < keyword_num; i++)
	{
		cin >> keyword_char;

		if (keyword_char == "push")
		{
		}
		else if (keyword_char == "pop")
		{
		}
		else if (keyword_char == "size")
		{
		}
		else if (keyword_char == "empty")
		{
		}
		else if (keyword_char == "top")
		{
		}
		else;
	}



	return 0;
}