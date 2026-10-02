// types_research.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // 1. Размеры типов
    std::cout << "=== РАЗМЕРЫ ТИПОВ ===" << std::endl;
    std::cout << "bool:        " << sizeof(bool) << " байт" << std::endl;
    std::cout << "char:        " << sizeof(char) << " байт" << std::endl;
    std::cout << "short:       " << sizeof(short) << " байт" << std::endl;
    std::cout << "int:         " << sizeof(int) << " байт" << std::endl;
    std::cout << "long:        " << sizeof(long) << " байт" << std::endl;
    std::cout << "long long:   " << sizeof(long long) << " байт" << std::endl;
    std::cout << "float:       " << sizeof(float) << " байт" << std::endl;
    std::cout << "double:      " << sizeof(double) << " байт" << std::endl;

    std::cout << std::endl;

    // 2. Объявление переменных разных типов
    std::cout << "=== ПРИМЕРЫ ПЕРЕМЕННЫХ ===" << std::endl;

    int age = 20;
    std::cout << "int age = " << age << std::endl;

    double price = 149.99;
    std::cout << "double price = " << price << std::endl;

    char grade = 'A';
    std::cout << "char grade = " << grade << std::endl;

    bool isStudent = true;
    std::cout << "bool isStudent = " << isStudent << std::endl;

    std::string name = "Студент";
    std::cout << "string name = " << name << std::endl;

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
