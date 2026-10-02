// user_profile1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // === ОБЪЯВЛЕНИЕ ПЕРЕМЕННЫХ ===

    // Личные данные (заполнить собственными данными)
    std::string firstName = "Марат";     // Имя
    std::string lastName = "Боязитов";      // Фамилия
    int age = 18;                    // Возраст (целое число)
    char gender = 'M ';              // Пол ('M' или 'F')
    double height = 1.80;            // Рост в метрах
    double weight = 76;            // Вес в килограммах

    // Учебные данные
    std::string group = "ИСПкр-252";         // Номер группы
    int course = 2;                 // Курс (1-4)
    double averageGrade = 4.9;      // Средний балл
    bool hasScholarship = true;    // Наличие стипендии

    // Контактные данные
    std::string email = "maratboisitow@gmail.com";         // Адрес электронной почты
    std::string phone = "79023114432";         // Номер телефона

    // === ВЫВОД ИНФОРМАЦИИ ===

    std::cout << "==============================" << std::endl;
    std::cout << "     ПРОФИЛЬ ПОЛЬЗОВАТЕЛЯ     " << std::endl;
    std::cout << "==============================" << std::endl;

    std::cout << std::endl;
    std::cout << "--- Личные данные ---" << std::endl;
    std::cout << "Имя:" << firstName << std::endl;
    std::cout << "Фамилия:" << lastName << std::endl;
    std::cout << "Возраст:" << age << " лет" << std::endl;
    std::cout << "Пол: " << gender << std::endl;
    std::cout << "Рост:" << height << " м" << std::endl;
    std::cout << "Вес:  " << weight << " кг" << std::endl;

    std::cout << std::endl;
    std::cout << "--- Учебные данные ---" << std::endl;
    std::cout << "Группа:" << group << std::endl;
    std::cout << "Курс: " << course << std::endl;
    std::cout << "Средний балл:" << averageGrade << std::endl;
    std::cout << "Стипендия:" << (hasScholarship ? "Да" : "Нет") << std::endl;

    std::cout << std::endl;
    std::cout << "--- Контактные данные ---" << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Телефон: " << phone << std::endl;

    std::cout << std::endl;
    std::cout << "==============================" << std::endl;

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
