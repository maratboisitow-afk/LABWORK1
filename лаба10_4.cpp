#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

const int SIZE = 6; 


void fillRandom(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = rand() % 41 - 20; 
        }
    }
}

void fillManual(int matrix[SIZE][SIZE]) {
    cout << "Введите элементы матрицы " << SIZE << "x" << SIZE << ":" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> matrix[i][j];
        }
    }
}


void printMatrix(const int matrix[SIZE][SIZE]) { 
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            
            if (matrix[i][j] >= 0 && matrix[i][j] < 10) cout << "  ";
            else if (matrix[i][j] < 0 && matrix[i][j] > -10) cout << " ";
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int getRowMax(const int matrix[SIZE][SIZE], int rowIndex) {
    int maxVal = matrix[rowIndex][0];
    for (int j = 1; j < SIZE; ++j) {
        if (matrix[rowIndex][j] > maxVal) {
            maxVal = matrix[rowIndex][j];
        }
    }
    return maxVal;
}


void processVariant6(int matrix[SIZE][SIZE]) {
    int rowMaxes[SIZE]; 

    for (int i = 0; i < SIZE; ++i) {
        rowMaxes[i] = getRowMax(matrix, i);
    }

    int minOfMaxs = rowMaxes[0];
    int targetRowIndex = 0;

    for (int i = 1; i < SIZE; ++i) {
        if (rowMaxes[i] < minOfMaxs) {
            minOfMaxs = rowMaxes[i];
            targetRowIndex = i;
        }
    }

    cout << "Номер строки с наименьшим максимумом: " << targetRowIndex + 1
        << " (значение максимума: " << minOfMaxs << ")" << endl;

    int lastRowIndex = SIZE - 1;
    if (targetRowIndex != lastRowIndex) {
        for (int j = 0; j < SIZE; ++j) {
            int temp = matrix[targetRowIndex][j];
            matrix[targetRowIndex][j] = matrix[lastRowIndex][j];
            matrix[lastRowIndex][j] = temp;
        }
        cout << "Строка " << targetRowIndex + 1 << " поменяна местами со строкой " << SIZE << "." << endl;
    }
    else {
        cout << "Искомая строка уже является последней, обмен не требуется." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); 
    srand(static_cast<unsigned int>(time(0))); 

    int matrix[SIZE][SIZE];
    int choice;

    cout << "Выберите способ заполнения матрицы:" << endl;
    cout << "1 - Случайными числами (-20 до 20)" << endl;
    cout << "2 - Вручную с клавиатуры" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    if (choice == 1) {
        fillRandom(matrix);
    }
    else if (choice == 2) {
        fillManual(matrix);
    }
    else {
        cout << "Неверный ввод. Используется случайное заполнение." << endl;
        fillRandom(matrix);
    }

    cout << "\nИсходная матрица:" << endl;
    printMatrix(matrix);

    cout << "--- Выполнение преобразования (Вариант 6) ---" << endl;
    processVariant6(matrix);

    cout << "\nМатрица после преобразования:" << endl;
    printMatrix(matrix);

    return 0;
}
