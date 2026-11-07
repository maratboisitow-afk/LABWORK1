#include <iostream>
#include<windows.h>

// Функция обмена значений через указатели
void swapPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция обмена значений через ссылки
void swapReferences(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция, возвращающая ссылку на элемент массива
int& getElement(int arr[], int index) {
    return arr[index];
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "=== ССЫЛКИ ===" << std::endl;

    int x = 10, y = 20;

    // Базовое использование ссылок
    int& ref = x;
    std::cout << "x = " << x << ", ref = " << ref << std::endl;

    ref = 100;
    std::cout << "После ref = 100: x = " << x << std::endl;
    std::cout << std::endl;

    // Обмен значений через указатели
    x = 10; y = 20;
    std::cout << "Обмен через указатели:" << std::endl;
    std::cout << "  До обмена:    x = " << x << ", y = " << y << std::endl;
    swapPointers(&x, &y);
    std::cout << "  После обмена: x = " << x << ", y = " << y << std::endl;
    std::cout << std::endl;

    // Обмен значений через ссылки
    x = 10; y = 20;
    std::cout << "Обмен через ссылки:" << std::endl;
    std::cout << "  До обмена:    x = " << x << ", y = " << y << std::endl;
    swapReferences(x, y);
    std::cout << "  После обмена: x = " << x << ", y = " << y << std::endl;
    std::cout << std::endl;

    // Возврат ссылки из функции
    int arr[3] = { 1, 2, 3 };
    std::cout << "Массив до изменения: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    getElement(arr, 1) = 100;  // Изменение элемента через возвращаемую ссылку

    std::cout << "Массив после getElement(arr, 1) = 100: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
