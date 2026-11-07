#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[5] = { 10, 20, 30, 40, 50 };
    int* ptr = arr;

    std::cout << "=== УКАЗАТЕЛИ И МАССИВЫ ===" << std::endl;

    // Обход массива с использованием указателя
    std::cout << "Обход массива через указатель:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "  ptr[" << i << "] = " << ptr[i]
            << ", *(ptr + " << i << ") = " << *(ptr + i)
            << ", адрес: " << (ptr + i) << std::endl;
    }
    std::cout << std::endl;

    // Демонстрация арифметики указателей
    std::cout << "Арифметика указателей:" << std::endl;
    std::cout << "  ptr = " << ptr << " (*ptr = " << *ptr << ")" << std::endl;

    ptr++;
    std::cout << "  После ptr++: ptr = " << ptr << " (*ptr = " << *ptr << ")" << std::endl;

    ptr += 2;
    std::cout << "  После ptr += 2: ptr = " << ptr << " (*ptr = " << *ptr << ")" << std::endl;

    ptr--;
    std::cout << "  После ptr--: ptr = " << ptr << " (*ptr = " << *ptr << ")" << std::endl;
    std::cout << std::endl;

    // Вычисление разницы указателей
    int* start = arr;
    int* end = arr + 4;
    std::cout << "Разница указателей:" << std::endl;
    std::cout << "  end - start = " << (end - start) << " элементов" << std::endl;

    return 0;
}