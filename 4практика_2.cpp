#include <iostream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "Russian");

    const int ROWS = 3;
    const int COLS = 4;
    int matrix[ROWS][COLS];

    // Заполнение матрицы
    std::cout << "Введите матрицу " << ROWS << "x" << COLS << ":" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << "matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }

    // Вывод матрицы
    std::cout << "\nМатрица:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    // Сумма элементов каждой строки
    std::cout << "\nСуммы строк:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        int rowSum = 0;
        for (int j = 0; j < COLS; j++) {
            rowSum += matrix[i][j];
        }
        std::cout << "Строка " << i << ": " << rowSum << std::endl;
    }

    // Сумма элементов каждого столбца
    std::cout << "\nСуммы столбцов:" << std::endl;
    for (int j = 0; j < COLS; j++) {
        int colSum = 0;
        for (int i = 0; i < ROWS; i++) {
            colSum += matrix[i][j];
        }
        std::cout << "Столбец " << j << ": " << colSum << std::endl;
    }

    // Поиск максимального элемента матрицы
    int maxVal = matrix[0][0];
    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    std::cout << "\nМаксимум: " << maxVal << " в позиции [" << maxRow << "][" << maxCol << "]" << std::endl;

    return 0;
}