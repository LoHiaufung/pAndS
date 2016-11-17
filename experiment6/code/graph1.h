// storaged by adjacent matrix
// traversed by dfs
#include <iostream>
#include <cstring>

using namespace std;

class graph1 {
 private:
	 int** adjacentMatrix;
	 int m_size;
	 bool*  isOutput;
	 bool isValid(int i);
	 void realDFS(int x);
 public:
	graph1(int x);
	~graph1();
	void createEdge(int i, int j, int w); 
	void dfs(int begin);
};

graph1::graph1(int x) {
	m_size = x;
	adjacentMatrix = new int*[x];
	for (int i = 0; i < x; i++) {
		adjacentMatrix[i] = new int[x];
		memset(adjacentMatrix[i], 0, sizeof(adjacentMatrix[0][0]) * x);
	}
	isOutput = new bool[m_size];
}

graph1::~graph1() {
	if (NULL != adjacentMatrix) {
		for (int i = 0; i < m_size; i++) {
			delete[] adjacentMatrix[i];
		}
		delete[] adjacentMatrix;
		delete[] isOutput;
	}
}

void graph1::createEdge(int i, int j, int w){
	if ( isValid(i)&& isValid(j)&& w > 0) {
		adjacentMatrix[i][j] = w;
	}
}

bool graph1::isValid(int i) {return (i >= 0 && i < m_size);}

void graph1::dfs(int begin) {
	if (isValid(begin)) {
		memset(isOutput, false, sizeof(bool)*m_size);
		realDFS(begin);
	} else {
		cout << "The begin point " << begin <<" is out of range!" << endl;
	}
}

void graph1::realDFS(int begin) {
	if (false == isOutput[begin]) { 
		cout << begin << ' ' ;
		isOutput[begin] = true;
	}
	for (int i = 0; i < m_size; i++) {
		if ( adjacentMatrix[begin][i] > 0 && begin != i) realDFS(i);
	}
}