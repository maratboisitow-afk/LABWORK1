#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int x = 42;
    int* ptr = &x;

    std::cout << "=== ОСНОВЫ УКАЗАТЕЛЕЙ ===" << std::endl;
    std::cout << "Переменная x:" << std::endl;
    std::cout << "  Значение: " << x << std::endl;
    std::cout << "  Адрес:    " << &x << std::endl;
    std::cout << std::endl;

    std::cout << "Указатель ptr:" << std::endl;
    std::cout << "  Значение ptr (адрес x): " << ptr << std::endl;
    std::cout << "  Значение *ptr:          " << *ptr << std::endl;
    std::cout << "  Адрес самого ptr:       " << &ptr << std::endl;
    std::cout << std::endl;

    // Изменение значения через указатель
    *ptr = 100;
    std::cout << "После выполнения *ptr = 100:" << std::endl;
    std::cout << "  x = " << x << std::endl;
    std::cout << "  *ptr = " << *ptr << std::endl;
    std::cout << std::endl;

    // Переназначение указателя
    int y = 200;
    ptr = &y;
    std::cout << "После выполнения ptr = &y:" << std::endl;
    std::cout << "  *ptr = " << *ptr << std::endl;
    std::cout << "  y = " << y << std::endl;

    return 0;
}
