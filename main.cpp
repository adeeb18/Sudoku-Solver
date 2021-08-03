#include <vector>
#include <iostream>
using namespace std;

#define UNASSIGNED 0
#define N 9

bool checkFull(int board[N][N], int& row, int& col);
bool checkValid(int b[N][N], int row, int col, int num);


bool Solver(int b[N][N]) {

    int row;
    int col;

    if (checkFull(b, row, col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        cout << endl;
        cout << row << " " << col << endl;
        if (checkValid(b, row, col, num)) {
            b[row][col] = num;
            if (Solver(b)) {
                return true;
            }
            cout << row << " " << col << endl;
            b[row][col] = 0;
        }
    }
}

bool checkFull(int board[N][N], int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                return false;
            }
        }
    }
    cout << "done";
    return true;
}

bool checkValid(int b[N][N], int row, int col, int num) {
   
    bool rowValid = true;
    bool colValid = true;
    bool boxValid = true;

    //Check Row
    for (int j = 0; j < N; j++) {
        if (b[row][j] == num) {
            rowValid = false;
        }
    }

    //Check Col
    for (int i = 0; i < N; i++) {
        if (b[i][col] == num) {
            rowValid = false;
        }
    }

    //Check box

    int boxRow = ((row) / 3) * 3;
    int boxCol = ((col) / 3) * 3;

    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (b[i][j] == num) {
                boxValid = false;
            }
        }
    }

    //Check all

    return (rowValid && colValid && boxValid && (b[row][col] == 0));

}

void printBoard(int b[N][N]) {
    for (unsigned int i = 0; i < N; i++) {
        for (unsigned int j = 0; j < N; j++) {
            if (j != 0) {
                cout << " ";
            }
            cout << b[i][j];
        }
        cout << endl;
    }
}


int main() {
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printBoard(board);

    cout << endl;

    if (Solver(board)) {
        printBoard(board);
    }
    else {
        cout << "No Solution" << endl;
    }

    return 0;
};
