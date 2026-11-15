#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 6;

int main() {
    int matrix[ROWS][COLS] = {
        {0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 4},
        {0, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {7, 0, 0, 0, 2, 0}
    };

    cout << "Original matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }

    int sparse[ROWS * COLS + 1][3];

    sparse[0][0] = ROWS;
    sparse[0][1] = COLS;
    sparse[0][2] = count;

    int k = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    cout << "\nSparse matrix (triplet form):" << endl;
    cout << "Row\tCol\tValue" << endl;
    for (int i = 0; i <= count; i++) {
        cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << endl;
    }

    cout << "\nNormal matrix uses  " << ROWS * COLS << " spaces." << endl;
    cout << "Triplet form uses   " << (count + 1) * 3 << " spaces." << endl;

    return 0;
}
