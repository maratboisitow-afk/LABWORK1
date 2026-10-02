// age_calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Константы
    const int CURRENT_YEAR = 2026;
    const int RETIREMENT_AGE = 65;
    const int ADULT_AGE = 18;
    const int DRIVING_AGE = 18;

    // Данные пользователя (указать собственный год рождения)
    int birthYear = 2008;

    // Вычисления
    int age = CURRENT_YEAR - birthYear;
    int yearsToRetirement = RETIREMENT_AGE - age;
    bool isAdult = (age >= ADULT_AGE);
    bool canDrive = (age >= DRIVING_AGE);
    int ageInMonths = age * 12;
    int ageInDays = age * 365;

    // Вывод результатов
    std::cout << "=== КАЛЬКУЛЯТОР ВОЗРАСТА ===" << std::endl;
    std::cout << std::endl;

    std::cout << "Год рождения:" << birthYear << std::endl;
    std::cout << "Текущий год: " << CURRENT_YEAR << std::endl;
    std::cout << "Ваш возраст: " << age << " лет" << std::endl;
    std::cout << "Возраст в месяцах: " << ageInMonths << "месяцев" << std::endl;
    std::cout << "Возраст в днях: " << ageInDays << "дней" << std::endl;
    std::cout << std::endl;

    std::cout << "Совершеннолетний: " << (isAdult ? "Да" : "Нет") << std::endl;
    std::cout << "Может водить: " << (canDrive ? "Да" : "Нет") << std::endl;
    std::cout << "До пенсии: " << yearsToRetirement << " лет" << std::endl;

    // Информация об используемой памяти
    std::cout << std::endl;
    std::cout << "--- Используемая память ---" << std::endl;
    std::cout << "birthYear (int): " << sizeof(birthYear) << " байт" << std::endl;
    std::cout << "age (int): " << sizeof(age) << " байт" << std::endl;
    std::cout << "isAdult (bool): " << sizeof(isAdult) << " байт" << std::endl;

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
