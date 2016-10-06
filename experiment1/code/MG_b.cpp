#include <iostream>
#include <iomanip>

using namespace std;

struct point {
    int x;
    int y;
    point(int x_, int y_) :x(x_), y(y_){}
    point operator=(const point pt) { 
        x = pt.x;
        y = pt.y;
        return *this;
    }
};

point goDia(point pt, int size);
point goDown(point pt, int size);
bool isEmpty(point pt, int** mg);
point nextPos(point pt, int** mg, int size);

int main() {
    int rows;
    cout << "Please enter the size: ";
    cin >> rows;
    cout << endl;
    if (rows > 1) {
        // apply space
        int** mg = new int*[rows];
        for (int i = 0; i < rows; i++) {
            mg[i] = new int[rows];
        }

        // initialize
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                mg[i][j] = -1;
            }
        }

        // begin construct mg
        point curPt(0, (rows - 1) / 2);
        for (int i = 1; i <= rows * rows; i++) {
            mg[curPt.x][curPt.y] = i;
            curPt = nextPos(curPt, mg, rows);
        }

        // output
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                cout<< setw(2) << setfill(' ') << mg[i][j] << ' '; 
            }
             cout << endl;
        }

        // free space
        for (int i = 0; i < rows; i++) {
            delete[] mg[i];
        }
        delete[] mg;
    } else {
        cout << "[error] Rows must be greater than 1! " << endl;
    }
    return 0;
}

point goDia(point pt, int size) {
    pt.x -= 1;
    pt.y += 1;
    if (pt.x == -1) { pt.x = size - 1; }
    if (pt.y == size) { pt.y = 0; }
    return pt;
}

point goDown(point pt, int size) {
    pt.x += 1;
    if (pt.x == size) { pt.x = 0; }
    return pt;
}

bool isEmpty(point pt, int** mg) {
    return -1 == mg[pt.x][pt.y];
}

point nextPos(point curPt, int** mg, int size) {
    point nextPt(-1, -1);
    if (true == isEmpty(goDia(curPt, size), mg)) {
        nextPt = goDia(curPt, size);
    } else if (true == isEmpty(goDown(curPt, size), mg)) {
        nextPt = goDown(curPt, size);
    }
    return nextPt;
}