#include <string>
#include <iostream>
#include <iomanip>
#include "stups.hpp"
#include <sstream>

using namespace std;

void getBeginCars(stup& li);
string IDtoName(const int & ID);

void toAnotherStup(stup& from, stup& to);
void allToAnotherStup(stup& from, stup& to);
bool whetherIntoStup(int i, stup& s);
bool stupToExit(stups& s, stup& exit);
stup& whichStupToIn(int i,  stups& s);


int main () {
	stup entry, exit;
    int carAmount = 0;
	// -1 for entry, -2 for exit
	entry.setID(-1);
	exit.setID(-2);
	getBeginCars(entry);
    carAmount = entry.m_railway.size();
    stups carBuff (entry.m_railway.size() - 1);

    // put all cars from entry to buff
    while (false == entry.m_railway.empty()) {
        int num = entry.m_railway.top();
        if (true == whetherIntoStup(num, exit)) {
            toAnotherStup(entry, exit);
            while (stupToExit(carBuff, exit)) {};
        } else {
            toAnotherStup(entry, whichStupToIn(num, carBuff));
        }
    }

    // put all cars from buff to exit
    while (carAmount != exit.m_railway.size()) {
        for (int i = 0; i < carBuff.getUsedStupAmount(); i++) {
            if (false == carBuff[i].m_railway.empty()) {
                if (true == whetherIntoStup(carBuff[i].m_railway.top(), exit)) {
                    allToAnotherStup(carBuff[i], exit);
                }
            }
        }
    }

    std::cout << "The amount of used stubs is: " << carBuff.getUsedStupAmount() << endl;
    return 0;
}

void getBeginCars(stup& li) {
	cout << "Please enter the number of cars: ";
	int n;
	cin >> n;
	cout << "Please enter the cars, separator by blank: " << endl;
	cout << "From the first car to the last car: " << endl;
	int hold;
    stack<int> tmp;
	while (n--) {
		cin >> hold;
		tmp.push(hold);
	}
    while (false == tmp.empty()) {
        li.m_railway.push(tmp.top());
        tmp.pop();
    }
}

string IDtoName(const int & ID) {
    if (-2 == ID) {
        return "Exit";
    } else if (-1 == ID) {
        return "Entry";
    } else {
        stringstream s;
        s << ID;
        return ("Stup " + s.str());
    }
}

void toAnotherStup(stup& from, stup& to) {
    if (false == from.m_railway.empty()) {
        to.m_railway.push(from.m_railway.top());
        cout << "car " <<setw(4) <<  left <<from.m_railway.top() << ": " 
            << IDtoName(from.getId()) << " -> " << IDtoName(to.getId()) << endl;
        from.m_railway.pop();
        to.setUsed();
    }
}
void allToAnotherStup(stup& from, stup& to) {
    while (false == from.m_railway.empty()) {
        toAnotherStup(from, to);
    }
}

bool whetherIntoStup(int num, stup& s) {
    // for buff
    if (-2 != s.getId()) {
        if (true == s.m_railway.empty()) {
            return true;
        } else if (num == s.m_railway.top() - 1) {
            return true;
        } else {
            return false;
        }
    // for exit
    } else {
        if (num == 1 && s.m_railway.empty()) {
            return true;
        } else if (num != 1 && s.m_railway.empty()){
            return false;
        } else {
            return (num == s.m_railway.top() + 1);
        }
    }
}

stup& whichStupToIn(int num, stups& s) {
    for (int i = 0; i < s.getStupAmount(); i++) {
        if (true == whetherIntoStup(num, s[i])) {
            return s[i];
        }
    }
    cout << "No stup to in!" << endl;
}

bool stupToExit(stups& carBuff, stup& exit) {
        for (int i = 0; i < carBuff.getUsedStupAmount(); i++) {
            if (false == carBuff[i].m_railway.empty()) {
                if (true == whetherIntoStup(carBuff[i].m_railway.top(), exit)) {
                    allToAnotherStup(carBuff[i], exit);
                    return true;
                }
            }
        }
        return false;
}