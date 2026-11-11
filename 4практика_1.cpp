#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 10;
    int arr[SIZE];

    // Ввод элементов
    std::cout << "Введите " << SIZE << " целых чисел:" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }

    // Вывод массива
    std::cout << "\nМассив: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Поиск минимума и максимума
    int min = arr[0], max = arr[0];
    int minIdx = 0, maxIdx = 0;

    for (int i = 1; i < SIZE; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIdx = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            maxIdx = i;
        }
    }

    std::cout << "Минимум: " << min << " (индекс " << minIdx << ")" << std::endl;
    std::cout << "Максимум: " << max << " (индекс " << maxIdx << ")" << std::endl;

    // Сумма и среднее арифметическое
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    double avg = static_cast<double>(sum) / SIZE;
    std::cout << "Сумма: " << sum << std::endl;
    std::cout << "Среднее: " << avg << std::endl;

    // Подсчёт положительных, отрицательных и нулевых элементов
    int positive = 0, negative = 0, zeros = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > 0) positive++;
        else if (arr[i] < 0) negative++;
        else zeros++;
    }
    std::cout << "Положительных: " << positive << std::endl;
    std::cout << "Отрицательных: " << negative << std::endl;
    std::cout << "Нулей: " << zeros << std::endl;

    return 0;
}