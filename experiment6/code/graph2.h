// storaged by adjacent list
// traversed by dfs
#include <iostream>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

class graph2 {
 private:
	 list<int>** adjacentList;
	 int m_size;
	 bool*  isOutput;
	 queue<int> q;
	 bool isValid(int i);
	 void realBFS();
 public:
	graph2(int x);
	~graph2();
	void createEdge(int i, int j); 
	void bfs(int begin);
};

graph2::graph2(int x) {
	m_size = x;
	adjacentList = new list<int>*;
	for (int i = 0; i < x; i++) {
		adjacentList[i] = new list<int>;
	}
	isOutput = new bool[m_size];
}

graph2::~graph2() {
	if (NULL != adjacentList) {
		for (int i = 0; i < m_size; i++) {
			delete adjacentList[i];
		}
		delete[] adjacentList;
		delete[] isOutput;
	}
}

void graph2::createEdge(int i, int j){
	if ( isValid(i)&& isValid(j)) {
		adjacentList[i] -> push_back(j);
	}
}

bool graph2::isValid(int i) {return (i >= 0 && i < m_size);}

void graph2::bfs(int begin) {
	if (isValid(begin)) {
		memset(isOutput, false, sizeof(bool)*m_size);
		q.push(begin);
		realBFS();
	} else {
		cout << "The begin point " << begin <<" is out of range!" << endl;
	}
}

void graph2::realBFS() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		isOutput[cur] = true;
		cout << cur << ' ';

		for (list<int>::iterator i = adjacentList[cur] -> begin(); i != adjacentList[cur] -> end(); i++) {
			if (false == isOutput[*i]) {
				q.push(*i);
			}
		}
	}
}