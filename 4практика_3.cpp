#include <iostream>

const int MAX_SIZE = 100;

int main() {
    setlocale(LC_ALL, "Russian");

    int numbers[MAX_SIZE];
    int count = 0;

    // Ввод элементов до нуля либо до заполнения массива
    std::cout << "Вводите числа (0 для завершения):" << std::endl;
    while (count < MAX_SIZE) {
        int num;
        std::cin >> num;
        if (num == 0) break;
        numbers[count] = num;
        count++;
    }

    if (count == 0) {
        std::cout << "Массив пуст" << std::endl;
        return 0;
    }

    if (count == MAX_SIZE) {
        std::cout << "Достигнута вместимость массива: " << MAX_SIZE << std::endl;
    }

    // Вывод содержимого
    std::cout << "\nМассив (" << count << " элементов): ";
    for (int i = 0; i < count; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Минимум, максимум и среднее значение
    int minVal = numbers[0];
    int maxVal = numbers[0];
    int sum = 0;
    for (int i = 0; i < count; i++) {
        if (numbers[i] < minVal) minVal = numbers[i];
        if (numbers[i] > maxVal) maxVal = numbers[i];
        sum += numbers[i];
    }
    double average = (double)sum / count;

    std::cout << "Минимум: " << minVal << std::endl;
    std::cout << "Максимум: " << maxVal << std::endl;
    std::cout << "Среднее: " << average << std::endl;

    // Линейный поиск
    int target;
    std::cout << "\nВведите искомое значение: ";
    std::cin >> target;

    int foundIndex = -1;
    for (int i = 0; i < count; i++) {
        if (numbers[i] == target) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        std::cout << "Элемент найден на позиции " << foundIndex << std::endl;
    }
    else {
        std::cout << "Элемент не найден" << std::endl;
    }

    // Удаление последнего элемента
    count--;
    std::cout << "\nПосле удаления последнего элемента: ";
    for (int i = 0; i < count; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
