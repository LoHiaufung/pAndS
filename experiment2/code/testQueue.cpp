#include <iostream>
#include <string>
#include "queue.hpp"

using namespace std;


queue<char> que;

int main() {
	string str = "computer";
	que.createQueue(7);
	cout << "queue length: 7" << endl;
	cout << "test queue:" << endl;
	cout << "	test push:";
	for (int i = 0; i < str.length(); i++) {
		cout << str[i] << ' ' ;
		if (false == que.push(str[i])) {
			cout << endl << "		push " << str[i] << " fail, the queue is full!" << endl;
		}
	}
	cout << endl;

	cout << "	test pull: ";
	while (false == que.empty()) {
		cout << que.front() << ' ';
		que.pop();
	}
	cout << endl;

	cout << "	test overflow: ";
	if (false == que.pop()) {
		cout << "the queue is empty!" << endl;
	} else {
		cout << "the queue overflow!" << endl;
	}

	
	return 0;
}

