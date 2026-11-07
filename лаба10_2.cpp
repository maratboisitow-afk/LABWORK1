// лаба10_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
    if (size == 0) {
        cout << "Массив пуст." << endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int calcSum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) sum += arr[i];
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
    posCount = 0; negCount = 0; zeroCount = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) posCount++;
        else if (arr[i] < 0) negCount++;
        else zeroCount++;
    }
}

int findFirstAboveAverage(const int arr[], int size, double average) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] > average) return i;
    }
    return -1;
}


void replaceNegativesWithZero(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            arr[i] = 0;
        }
    }
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void cyclicShiftRight(int arr[], int size) {
    if (size <= 1) return; 

    int lastElement = arr[size - 1];
    for (int i = size - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = lastElement;
}

void removeElementByIndex(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: некорректный индекс для удаления!" << endl;
        return;
    }
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size--; 
}

int main() {
    setlocale(LC_ALL, "Russian");

    int numbers[SIZE];

    int currentSize = SIZE;

    cout << "--- ЧАСТЬ 1: ОДНОМЕРНЫЙ МАССИВ ---" << endl;

    fillArray(numbers, currentSize);

    cout << "Исходный массив: ";
    printArray(numbers, currentSize);

    int sum = calcSum(numbers, currentSize);
    double average = calcAverage(numbers, currentSize);
    int maxVal = calcMax(numbers, currentSize);
    int minVal = calcMin(numbers, currentSize);

    cout << "\nСтатистика:" << endl;
    cout << "Сумма: " << sum << endl;
    cout << "Среднее арифметическое: " << average << endl;
    cout << "Максимум: " << maxVal << endl;
    cout << "Минимум: " << minVal << endl;

    int pos = 0, neg = 0, zero = 0;
    countElements(numbers, currentSize, pos, neg, zero);
    cout << "\nКоличество элементов:" << endl;
    cout << "Положительных: " << pos << endl;
    cout << "Отрицательных: " << neg << endl;
    cout << "Нулевых: " << zero << endl;

    int index = findFirstAboveAverage(numbers, currentSize, average);
    cout << "\nИндекс первого элемента > среднего (" << average << "): ";
    if (index != -1) {
        cout << index << " (значение: " << numbers[index] << ")" << endl;
    }
    else {
        cout << "не найден" << endl;
    }

    cout << "\n--- ЧАСТЬ 2: ПРЕОБРАЗОВАНИЯ МАССИВА ---" << endl;

    replaceNegativesWithZero(numbers, currentSize);
    cout << "1. После замены отрицательных нулями: ";
    printArray(numbers, currentSize);

    reverseArray(numbers, currentSize);
    cout << "2. После перестановки в обратном порядке: ";
    printArray(numbers, currentSize);

    cyclicShiftRight(numbers, currentSize);
    cout << "3. После циклического сдвига вправо: ";
    printArray(numbers, currentSize);

    int indexToRemove = 3;
    cout << "4. Удаление элемента с индексом " << indexToRemove << "..." << endl;
    removeElementByIndex(numbers, currentSize, indexToRemove);
    cout << "   Массив после удаления: ";
    printArray(numbers, currentSize);
    cout << "   Новый размер массива: " << currentSize << endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
