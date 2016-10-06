#include <iostream>

bool isArray(int rows, int** ptr);
bool isSumEqual(int rows, int** ptr);

int main() {
	int rows;
	std::cout << "Please type in the rows: ";
	std::cin >> rows;
	std::cout << std::endl;

	if (rows > 1) {
		int** magicSquare = new int* [rows];
        for (int i = 0; i < rows; i++) {
            magicSquare[i] = new int[rows];
        }


		std::cout << "Please type in the magic square: " << std::endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				std::cin >> magicSquare[i][j];
			}
		} 

        if (true == isArray(rows, magicSquare) && true == isSumEqual(rows, magicSquare)) {
            std::cout << "Magic square is true!" << std::endl;
        } else {
            std::cout << "Magic square is false!" << std::endl;
        }

        for (int i = 0; i < rows; i++) {
            delete[] magicSquare[i];
        }
        delete[] magicSquare;
	} else {
		std::cout << "Rows mush be greater than 1 " << std::endl;
	}
	return 0;
}

bool isArray(int rows, int** ptr) {
	bool found = false;
	for (int i = 1; i <= rows* rows; i++) {
		found = false;
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < rows; k++) {
				if (i == ptr[j][k]) {
					found = true;
					break;
				}
			}
			if (true == found) {
				break;
			}
		}
		if (false == found) {
			return false;
		}
	}
	return true;
}

bool isSumEqual(int rows, int** ptr) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		sum += ptr[i][i];
	}
	// diagonal
	int sum_to_cmp = 0;
	for (int i = 0; i < rows; i++) {
		sum_to_cmp += ptr[i][rows - 1- i];
	}
	if (sum != sum_to_cmp) {return false;}

	// rows
	for (int i = 0; i < rows; i++) {
		sum_to_cmp = 0;
		for (int j = 0; j < rows; j++) {
			sum_to_cmp += ptr[i][j];
		}
		if (sum != sum_to_cmp) {return false;}
	}

	// columns
	for (int i = 0; i < rows; i++) {
		sum_to_cmp = 0;
		for (int j = 0; j < rows; j++) {
			sum_to_cmp += ptr[j][i];
		}
		if (sum != sum_to_cmp) {return false;}
	}

	return true;
}
