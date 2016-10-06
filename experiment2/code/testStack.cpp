#include <iostream>
#include <string>
#include "stack.hpp"

using namespace std;

stack<char> stk;

int main() {
	string str = "computer";
	stk.createStake();
	cout << "test stack:" << endl;
	cout << "	test push:";
	for (int i = 0; i < str.length(); i++) {
		cout << str[i] << ' ' ;
		stk.push(str[i]);
	}
	cout << endl;

	cout << "	test pull: ";
	while (false == stk.empty()) {
		cout << stk.top() << ' ';
		stk.pop();
	}
	cout << endl;

	cout << "	test overflow: ";
	if (false == stk.pop()) {
		cout << "the stack is empty!" << endl;
	} else {
		cout << "the stack overflow!" << endl;
	}

	return 0;
}
