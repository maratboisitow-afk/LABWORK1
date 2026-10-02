// student_form.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string firstName;    // Имя
    std::string lastName;     // Фамилия
    int age;                  // Возраст
    double height;            // Рост в метрах
    double weight;            // Вес в килограммах
    int course;               // Курс обучения


    std::cout << "=== АНКЕТА СТУДЕНТА ===" << std::endl;
    std::cout << std::endl;

    std::cout << "Введите имя: ";
    std::cin >> firstName;

    std::cout << "Введите фамилию: ";
    std::cin >> lastName;

    std::cout << "Введите возраст: ";
    std::cin >> age;

    std::cout << "Введите рост (в метрах, например 1.75): ";
    std::cin >> height;

    std::cout << "Введите вес (в кг): ";
    std::cin >> weight;

    std::cout << "Введите курс обучения (1-4): ";
    std::cin >> course;

    double bmi = weight / (height * height);
    
    std::cout << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << "         КАРТОЧКА СТУДЕНТА" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;

    std::cout << std::setfill(' ');  // Возврат пробела в качестве заполнителя

    std::cout << std::left << std::setw(15) << "Фамилия:"
        << std::right << std::setw(20) << lastName << std::endl;

    std::cout << std::left << std::setw(15) << "Имя:"
        << std::right << std::setw(20) << firstName << std::endl;

    std::cout << std::left << std::setw(15) << "Возраст:"
        << std::right << std::setw(17) << age << " лет" << std::endl;

    std::cout << std::left << std::setw(15) << "Курс:"
        << std::right << std::setw(20) << course << std::endl;

    std::cout << std::left << std::setw(15) << "Рост:"
        << std::right << std::setw(17)
        << std::fixed << std::setprecision(2) << height << " м" << std::endl;

    std::cout << std::left << std::setw(15) << "Вес:"
        << std::right << std::setw(16)
        << std::fixed << std::setprecision(1) << weight << " кг" << std::endl;

    std::cout << std::left << std::setw(15) << "ИМТ:"
        << std::right << std::setw(20)
        << std::fixed << std::setprecision(1) << bmi << std::endl;

    std::cout << std::setfill('-') << std::setw(40) << "" << std::endl;
    std::cout << "Категория: ";
    if (bmi < 18.5) {
        std::cout << "Недостаточный вес" << std::endl;
    }
    else if (bmi >= 18.5 && bmi <= 24.9) {
        std::cout << "Норма" << std::endl;
    }
    else if (bmi >= 25.0 && bmi <= 29.9) {
        std::cout << "Избыточный вес" << std::endl;
    }
    else {
       
        std::cout << "Ожирение" << std::endl;
    }

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
