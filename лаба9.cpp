// лаба9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    // Переменные для общей статистики за всё время работы программы
    int totalStudents = 0;
    int totalBeneficiaries = 0;
    double totalRevenue = 0.0;

    do {
        std::cout << "\n=== СИСТЕМА ШКОЛЬНОЙ СТОЛОВОЙ ===" << std::endl;
        std::cout << "1. Выбрать обед и ввести данные" << std::endl;
        std::cout << "2. Показать статистику" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // 1. Выбор обеда
            int lunchChoice;
            double lunchPrice = 0.0;
            std::string lunchName = "";

            std::cout << "\n--- ВЫБОР ОБЕДА ---" << std::endl;
            std::cout << "1. Стандартный (150 руб.)" << std::endl;
            std::cout << "2. Диетический (180 руб.)" << std::endl;
            std::cout << "3. Усиленный (200 руб.)" << std::endl;
            std::cout << "Выберите обед: ";
            std::cin >> lunchChoice;

            switch (lunchChoice) {
            case 1: lunchPrice = 150.0; lunchName = "Стандартный"; break;
            case 2: lunchPrice = 180.0; lunchName = "Диетический"; break;
            case 3: lunchPrice = 200.0; lunchName = "Усиленный"; break;
            default:
                std::cout << "Ошибка: неверный выбор обеда" << std::endl;
                break;
            }

            // Если обед выбран неверно, выходим из case 1
            if (lunchPrice == 0.0) break;

            // 2. Ввод количества учеников
            int numStudents;
            std::cout << "\nСколько учеников добавить? ";
            std::cin >> numStudents;

            if (numStudents <= 0) {
                std::cout << "Ошибка: количество должно быть положительным" << std::endl;
                break;
            }

            // Переменные для статистики текущей партии учеников
            int batchBeneficiaries = 0;
            double batchRevenue = 0.0;

            // 3. Цикл for для ввода данных по каждому ученику
            for (int i = 1; i <= numStudents; i++) {
                std::cout << "\n--- Ученик " << i << " ---" << std::endl;

                // Валидация класса
                int classNumber;
                do {
                    std::cout << "Класс (1-11): ";
                    std::cin >> classNumber;
                    if (classNumber < 1 || classNumber > 11) {
                        std::cout << "Ошибка: введите число от 1 до 11" << std::endl;
                    }
                } while (classNumber < 1 || classNumber > 11);

                // Ввод льготы
                char isBeneficiaryChar;
                std::cout << "Льгота (y/n): ";
                std::cin >> isBeneficiaryChar;

                // Валидация льготы
                while (isBeneficiaryChar != 'y' && isBeneficiaryChar != 'Y' &&
                    isBeneficiaryChar != 'n' && isBeneficiaryChar != 'N') {
                    std::cout << "Ошибка: введите y или n: ";
                    std::cin >> isBeneficiaryChar;
                }

                bool isBeneficiary = (isBeneficiaryChar == 'y' || isBeneficiaryChar == 'Y');

                // 4. Подсчёт статистических данных с использованием if/else
                double currentCost = lunchPrice;
                if (isBeneficiary) {
                    currentCost = lunchPrice * 0.5; // 50% скидка
                    batchBeneficiaries++;
                    totalBeneficiaries++;
                }

                batchRevenue += currentCost;
                totalRevenue += currentCost;
                totalStudents++;
            }

            // 5. Формирование отчёта по текущей партии
            std::cout << "\n=== ОТЧЕТ ===" << std::endl;
            std::cout << "Тип обеда: " << lunchName << std::endl;
            std::cout << "Добавлено учеников: " << numStudents << std::endl;
            std::cout << "Из них льготников: " << batchBeneficiaries << std::endl;
            std::cout << "Выручка за партию: " << std::fixed << std::setprecision(2) << batchRevenue << " руб." << std::endl;

            break;
        }

        case 2: {
            // 6. Формирование общего отчета с условной логикой
            if (totalStudents == 0) {
                std::cout << "Нет данных для отображения" << std::endl;
                break;
            }

            double beneficiaryRate = (double)totalBeneficiaries / totalStudents * 100;

            std::cout << "\n=== ОБЩАЯ СТАТИСТИКА ===" << std::endl;
            std::cout << "Всего учеников обслужено: " << totalStudents << std::endl;
            std::cout << "Из них льготников: " << totalBeneficiaries;
            std::cout << " (" << std::fixed << std::setprecision(1) << beneficiaryRate << "%)" << std::endl;
            std::cout << "Общая выручка: " << std::fixed << std::setprecision(2) << totalRevenue << " руб." << std::endl;

            // Условная логика для оценки работы столовой
            std::string status;
            if (totalRevenue > 5000) {
                status = "ВЫСОКАЯ ПРИБЫЛЬ";
            }
            else if (beneficiaryRate > 50) {
                status = "БОЛЬШОЕ КОЛИЧЕСТВО ЛЬГОТНИКОВ";
            }
            else if (totalRevenue > 1000) {
                status = "СТАБИЛЬНАЯ РАБОТА";
            }
            else {
                status = "НИЗКАЯ НАГРУЗКА";
            }
            std::cout << "Статус: " << status << std::endl;
            break;
        }

        case 0:
            std::cout << "Завершение работы программы" << std::endl;
            break;

        default:
            std::cout << "Неверный выбор. Повторите ввод" << std::endl;
        }

    } while (choice != 0);

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
