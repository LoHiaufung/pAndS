#include <iostream>
#include <math.h>
#include <vector>

std::vector<int> ThunderNumber;
bool NumberExist(int num);
bool is(int num);

int main() {
    for (int i = 11; i < 100000000; i++) {
        if (true == is(i) && false == NumberExist(i)) {
            std::cout << i << std::endl;
        }
    }
    std::cout << "total ThunderNumber amount: " << ThunderNumber.size() << std::endl;
    return 0;
}

bool is(int num) {
    int left, right;
    int zeros;
    for (int i = 1; i < 8; i++) {
            zeros = pow(10, i);
            left = num / zeros;
            right = num % zeros;
            if (left != 0) {
                if ((left + right) * (left + right) == num) {
                    return true;
                }
            } else {
                break;
            }
    }
    return false;
}

bool NumberExist(int num) {
    if (true == ThunderNumber.empty()) {
        ThunderNumber.push_back(num);
        return false;
    } else {
        for (std::vector<int>::iterator i = ThunderNumber.begin(); i != ThunderNumber.end(); i++) {
            if (*i == num) {
                return true;
            }
        }
       
        ThunderNumber.push_back(num);
        return false;
    }
}