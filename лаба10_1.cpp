#include <iostream>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

using namespace std;

const int SIZE = 20;

void fillArray(int arr[], int size) {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (50 - (-50) + 1) + (-50);
    }
}

void printArray(const int arr[], int size) {
    cout << "Массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int calcSum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

double calcAverage(const int arr[], int size) {
    if (size == 0) return 0.0;
    return static_cast<double>(calcSum(arr, size)) / size;
}

int calcMax(const int arr[], int size) {
    if (size == 0) return 0;
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}

int calcMin(const int arr[], int size) {
    if (size == 0) return 0;
    int minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) minVal = arr[i];
    }
    return minVal;
}

void countElements(const int arr[], int size, int& posCount, int& negCount, int& zeroCount) {
    posCount = 0;
    negCount = 0;
    zeroCount = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            posCount++;
        }
        else if (arr[i] < 0) {
            negCount++;
        }
        else {
            zeroCount++;
        }
    }
}

int findFirstAboveAverage(const int arr[], int size, double average) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] > average) {
            return i;
        }
    }
    return -1; 
}

int main() {
    setlocale(LC_ALL, "Russian");

    int numbers[SIZE];

    fillArray(numbers, SIZE);

    printArray(numbers, SIZE);

    int sum = calcSum(numbers, SIZE);
    double average = calcAverage(numbers, SIZE);
    int maxVal = calcMax(numbers, SIZE);
    int minVal = calcMin(numbers, SIZE);

    cout << "\n--- Статистика ---" << endl;
    cout << "Сумма: " << sum << endl;
    cout << "Среднее арифметическое: " << average << endl;
    cout << "Максимум: " << maxVal << endl;
    cout << "Минимум: " << minVal << endl;

    int pos = 0, neg = 0, zero = 0;
    countElements(numbers, SIZE, pos, neg, zero);

    cout << "\n--- Количество элементов ---" << endl;
    cout << "Положительных: " << pos << endl;
    cout << "Отрицательных: " << neg << endl;
    cout << "Нулевых: " << zero << endl;

    int index = findFirstAboveAverage(numbers, SIZE, average);

    cout << "\nИндекс первого элемента > среднего (" << average << "): ";
    if (index != -1) {
        cout << index << " (значение: " << numbers[index] << ")" << endl;
    }
    else {
        cout << "не найден" << endl;
    }

    return 0;
}
