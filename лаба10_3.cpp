#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <iomanip> 

using namespace std;

const int ROWS = 5;
const int COLS = 5;


void fillMatrix(int matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(const int matrix[ROWS][COLS], int rows, int cols) {
    cout << "Матрица:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printRowsAndColsSums(const int matrix[ROWS][COLS], int rows, int cols) {
    cout << "Суммы по строкам:" << endl;
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
        cout << "Строка " << i + 1 << ": " << sum << endl;
    }

    cout << "\nСуммы по столбцам:" << endl;
    for (int j = 0; j < cols; ++j) {
        int sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += matrix[i][j];
        }
        cout << "Столбец " << j + 1 << ": " << sum << endl;
    }
    cout << endl;
}

void printDiagonalsSums(const int matrix[ROWS][COLS], int rows, int cols) {
    int mainDiagSum = 0;
    int secondaryDiagSum = 0;

    for (int i = 0; i < rows; ++i) {
        mainDiagSum += matrix[i][i];             
        secondaryDiagSum += matrix[i][cols - 1 - i]; 
    }

    cout << "Сумма главной диагонали: " << mainDiagSum << endl;
    cout << "Сумма побочной диагонали: " << secondaryDiagSum << endl << endl;
}

void findMaxElement(const int matrix[ROWS][COLS], int rows, int cols) {
    int maxVal = matrix[0][0];
    int maxRow = 0;
    int maxCol = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    cout << "Максимальный элемент: " << maxVal << endl;
    cout << "Его позиция: строка " << maxRow + 1 << ", столбец " << maxCol + 1 << endl << endl;
}

void transposeMatrix(int matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = i + 1; j < cols; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int matrix[ROWS][COLS];

    fillMatrix(matrix, ROWS, COLS);
    printMatrix(matrix, ROWS, COLS);

    printRowsAndColsSums(matrix, ROWS, COLS);

    printDiagonalsSums(matrix, ROWS, COLS);

    findMaxElement(matrix, ROWS, COLS);

    cout << "Транспонирование" << endl;
    transposeMatrix(matrix, ROWS, COLS);
    printMatrix(matrix, ROWS, COLS);

    return 0;
}