#include <iostream>
#define MAX_SIZE 100


using namespace std;

int stack[MAX_SIZE];
int ptr;

// n :stack max size
// arr: the input numbers
// arrPtr: the current number
// sum: object sum
// curSum: current sum
void recursion(int n, const int* arr, int arrPtr, int sum, int curSum) {
	if (ptr <= n) {
		if (curSum + arr[arrPtr] == sum) {
			ptr++;
			stack[ptr] = arr[arrPtr];
			for (int i = 0; i <= ptr; i++) {
				cout << stack[i] << ' ';
			}
			cout << endl;
			ptr--;
			return;
		} else if (curSum + arr[arrPtr] < sum && ptr < n) {
			ptr++;
			stack[ptr] = arr[arrPtr];
			for (int i = arrPtr + 1; i < 10; i++) {
				recursion(n, arr, i, sum, curSum + arr[arrPtr]);
			}
			ptr--;
			return;
		} else {
			return;
		}
	}
}

int main () {
	ptr = -1;
	int n = 0;
	int arr [10] = {0};
	int t = 0;

	do {
	cout << "Enter the number of numbers: " << endl;
	cin >> n;
		if (n >= MAX_SIZE) {
			cout << "the number shuold not greater than " << MAX_SIZE << endl;
		}
	} while (n < 0 || n > MAX_SIZE);
	cout << "Enter the numbers: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Enter the sum you wan" << endl;
	cin >> t;
	
	for (int i = 0; i < n; i++) {
		ptr = -1;
		recursion(n - i, arr, i, t, 0);
	}
	return 0;
}