#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "=== ДИНАМИЧЕСКАЯ ПАМЯТЬ ===" << std::endl;

    // Работа с одиночным объектом
    std::cout << "\n--- Одиночный объект ---" << std::endl;
    int* p = new int;
    *p = 42;
    std::cout << "Адрес: " << p << ", значение: " << *p << std::endl;
    delete p;
    p = nullptr;  // Рекомендуемая практика

    // Выделение памяти с инициализацией
    int* p2 = new int(100);
    std::cout << "С инициализацией: " << *p2 << std::endl;
    delete p2;

    // Создание динамического массива
    std::cout << "\n--- Динамический массив ---" << std::endl;
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];

    // Заполнение массива
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;
    }

    // Вывод содержимого массива
    std::cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Вычисление суммы элементов
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    std::cout << "Сумма элементов: " << sum << std::endl;

    delete[] arr;  // Освобождение памяти массива

    // Создание двумерного динамического массива
    std::cout << "\n--- Двумерный массив ---" << std::endl;
    int rows = 3, cols = 4;

    // Выделение памяти
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Заполнение матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }

    // Вывод матрицы
    std::cout << "Матрица " << rows << "x" << cols << ":" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    std::cout << "\nПамять успешно освобождена" << std::endl;

    return 0;
}