#include <iostream>
#include "Random.hpp"

using namespace std;

int main() {
	double sum = 0;
 	double hold = 0;
	Random v;
	for (int i = 0; i < 10000; i++) {
		hold =  v.poisson(0.1);
		sum += hold;
		cout << hold << ' ';
	}
	cout << endl << sum << endl;
	return 0;
}