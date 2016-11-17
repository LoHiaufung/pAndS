#include <iostream>
#include "graph1.h"
#include "graph2.h"
#include <string>

using namespace std;

class graphManager {
private:
/*graph1*/
	graph1* g1 = NULL; 
/*graph2*/
	graph2* g2 = NULL; 
	void createEdge();
	void dfs();
	void bfs();
public:
	graphManager();
	~graphManager();
	void operate(string option);
};


void graphManager::dfs() {
	cout << "test DFS: " << endl;
	cout << "input the begin vec of DFS, end with -1" << endl;
	int begin;
	do {
		cin >> begin;
		cout << endl << "result: ";
		g1 -> dfs(begin);
		cout << endl;
	} while (begin != -1);
}


void graphManager::bfs() {
	int begin = -1;
	cout << "test BFS: " << endl;
	cout << "input the begin vec of BFS, end with -1" << endl;
	do {
		cin >> begin;
		cout << endl << "result: ";
		g2 -> bfs(begin);
		cout << endl;
	} while (begin != -1);
}

graphManager::graphManager() {
    cout << "---create the gragh---" << endl;
	int size = 0;
	do {
	cout << "input the size of graph: "; 
	cin >> size;
	}while(size < 1);
	g1 = new graph1(size);
	g2 = new graph2(size);
}
graphManager::~graphManager() {
	delete g1;
	delete g2;
}

void graphManager::createEdge() {
	int beginVer, endVer, weight;
	cout << "input edge with format[begin Vector] [end Vector] [weight]" << endl;
	cout << "end with -1, weight should > 0" << endl;
	do {
		cin >> beginVer;
		if (beginVer == -1) break;
		cin	>> endVer >> weight;
		g1->createEdge(beginVer, endVer, weight);
		g2->createEdge(beginVer, endVer);
	} while (true);
}

void graphManager::operate(string op) {
	if (op == "cd") {
		createEdge();
	} else if(op == "bfs") {
		bfs();
	} else if (op == "dfs") {
		dfs();
	}
}