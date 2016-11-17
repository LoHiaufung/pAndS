/*graph1.h用邻接矩阵实现，并有dfs实现。graph2.h用领接表，并有bfs实现。然后一个graphManager.h类来管理它们。*/
#include <iostream>
#include <string>
#include "graphManager.h"

using namespace std;

int main() {
	graphManager* p;
	string choice;
	p = new graphManager();
	do {
		cout << endl << "--------------------graph--------------------" << endl;
        cout << "option:" << endl;
		cout << "	cd  - create edge" << endl;
		cout << "	bfs - BFS traverse" << endl;
		cout << "	dfs - DFS traverse" << endl;
		cout << "other:" << endl;
		cout <<	"	q   - quit" << endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << "your choice: ";
		cin >> choice;
		if ("q" != choice) {
			p -> operate(choice);
		}
	} while(choice != "q");

	return 0;
}