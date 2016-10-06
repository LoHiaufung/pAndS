#ifndef STUPS_HPP
#define STUPS_HPP
#include <vector>
#include <stack>
#include <iostream>

// Here is the declaration and definition
// of class stups and class stup

class stup {
public:
	stup();
	void setID(int n);
	int getId();
	void setUsed();
	bool getUsed();
	bool spare();
// members
	std::stack<int> m_railway;
 private:
	bool used;
	int ID;
};


class stups {
public:
	stups(int n);
	~stups();
	int getUsedStupAmount();
	int getStupAmount();
	stup& operator[] (int n);
// members
	
 private:
	int stupAmount;
	stup* m_stup;
};

/*stups member definition*/

stups::stups(int n) {
	m_stup = new stup[n];
	stupAmount = n;
	for (int i = 0; i < n; i++) {
		m_stup[i].setID(i);
	}
}

stups::~stups() {
	delete[] m_stup;
}

int stups::getUsedStupAmount() {
	int counter = 0;
	for (int i = 0; i < stupAmount; i++) {
		if (true == m_stup[i].getUsed()) {
			counter++;
		}
	}
	return counter;
}

int stups::getStupAmount() {return stupAmount;}


stup& stups::operator[] (int n) {
	return m_stup[n];
}

/*stup member definition*/
stup::stup() {
	used = false;
	ID = -1;
}
void stup::setUsed() {used = true;}
bool stup::getUsed() {return used;}
bool stup::spare() {return m_railway.empty();}
void stup::setID(int i) {ID = i;}
int stup::getId() {return ID;}

#endif