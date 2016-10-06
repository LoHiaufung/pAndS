#include <iostream>
#include <string>
#include "stack.hpp"
#include "queue.hpp"

using namespace std;

stack<string> stk;
queue<string> que;

void operate(string ope);
void printInfo(string type, string info);
int main() {
	
	string choice;
	do {
		cout << endl << "--------------------Queue and Stack--------------------" << endl;
		cout << "stack:" << endl;
		cout << "	cs  - create a new stack" << endl;
		cout << "	pis - push a element into stack" << endl;
		cout << "	pos - pull a element out of stack" << endl;
		cout << "	pas - pull all element(s) out of stack" << endl;
		cout << "queue:" << endl;
		cout << "	cq - create a new queue" << endl;
		cout << "	piq - push a element intn queue" << endl;
		cout << "	poq - pull a element out of queue" << endl;
		cout << "	paq - pull all element(s) out of queue" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "your choice: ";
		cin >> choice;
		if ("q" != choice) {
			operate(choice);
		}
	} while(choice != "q");

	return 0;
}

void printInfo(string type, string info) {
	cout << '[' << type << ']' << ' ' << info << endl; 
}

void operate(string ope) {
	string in;
	if (ope == "cs") {
			if (true == stk.createStake()) {
				printInfo("Success", "");
			} else {
				printInfo("Error", "stack exist!");
			}
	} else if (ope == "pis") {
        if (true == stk.exist()) {
            cout << "Entry the char: ";
            cin >> in;
            if (true == stk.push(in)) {
                printInfo("Success", "");
            } else {
                printInfo("Error", "stack full!");
            }
        } else {
            printInfo("Error", "stack not build!");
        }
	} else if (ope == "pos") {
			if (false == stk.exist() || false == stk.empty()) {
				cout << stk.top() << endl;
				stk.pop();
			} else {
                printInfo("Error", "empty stack or stack not build!");
			}
	} else if (ope == "pas") {
			if (false == stk.exist() || false == stk.empty()) {
				while (false == stk.empty()) {
					cout << stk.top() << ' ';
					stk.pop();
				}
				cout << endl;
			} else {
                printInfo("Error", "empty stack or stack not build!");
			}
	} else if (ope == "cq") {
        int len = 0;
        cout << "Enter the length: ";
        cin >> len;
			if (true == que.createQueue(len)) {
				printInfo("success!", "");
			} else {
				printInfo("Error", "queue exist!");
			}
	} else if (ope == "piq") {
        if (true == que.exist()) {
        	string in;
            cout << "Entry the char: ";
            cin >> in;
            if (true == que.push(in)) {
                printInfo("Success", "");
            } else {
                printInfo("Error", "queue full!");
            }
        } else {
            printInfo("Error", "queue not build!");
        }
	} else if (ope == "poq") {
			if (false == que.exist() || false == que.empty()) {
				cout << que.front() << endl;
				que.pop();
			} else {
                printInfo("Error", "empty stack or stack not build!");
			}
	} else if (ope == "paq") {
			if (false == que.exist() || false == que.empty()) {
				while(false == que.empty()) {
					cout << que.front() << " ";
					que.pop();
				}
				cout << endl;
			} else {
                printInfo("Error", "empty queue or queue not build!");
			}
    } else {

    }
}