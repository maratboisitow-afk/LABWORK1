// myproject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<string> 
#ifdef _WIN32
#include<windows.h>
#endif

int main() {
    setlocale(LC_ALL, "Russian")
        // Настройка кодировки консоли для Windows
#ifdef _WIN32
        ;SetConsoleCP(65001);
        SetConsoleOutputCP(65001);
#endif

        std::cout << "===ПРОДУКТОВЫЙ МАГАЗИН===" << std::endl;
        std::cout << std::endl;

        //Объявление переменный разных типов
        std::string storeName; //Название магазина
        std::string category;      // Категория товаров
            std::string productName;   // Название товара
            double price;              // Цена за единицу
            int quantity;              // Количество товара
            double weight;             // Вес товара (кг)
            bool isPerishable;         // Скоропортящийся ли товар (логический тип)

            // 2. Ввод данных от пользователя
            std::cout << "Введите название магазина: ";
            std::getline(std::cin, storeName);

            std::cout << "Введите категорию товаров: ";
            std::getline(std::cin, category);

            std::cout << "Введите название товара: ";
            std::getline(std::cin, productName);

            std::cout << "Введите цену за 1 кг (руб.): ";
            std::cin >> price;

            std::cout << "Введите вес товара (кг): ";
            std::cin >> weight;

            std::cout << "Введите количество единиц на складе: ";
            std::cin >> quantity;

            std::cout << "Товар скоропортящийся? (1 - Да, 0 - Нет): ";
            std::cin >> isPerishable;

            // 3. Выполнение простых вычислений
            double totalCost = price * weight;                 // Общая стоимость покупки
            double discount = totalCost * 0.05;                // Скидка 5% (например, по акции)
            double finalPrice = totalCost - discount;          // Итоговая цена со скидкой
            bool inStock = (quantity > 0);                     // Проверка наличия на складе

            // 4. Вывод информации в консоль
            std::cout << std::endl;
            std::cout << "=== ИНФОРМАЦИЯ О ПОКУПКЕ ===" << std::endl;
            std::cout << "Магазин:            " << storeName << std::endl;
            std::cout << "Категория:          " << category << std::endl;
            std::cout << "Товар:              " << productName << std::endl;
            std::cout << "Цена за кг:         " << price << " руб." << std::endl;
            std::cout << "Вес:                " << weight << " кг" << std::endl;
            std::cout << "Общая стоимость:    " << totalCost << " руб." << std::endl;
            std::cout << "Скидка (5%):        " << discount << " руб." << std::endl;
            std::cout << "Цена со скидкой:    " << finalPrice << " руб." << std::endl;
            std::cout << "На складе:          " << quantity << " шт." << std::endl;
            std::cout << "В наличии:          " << (inStock ? "Да" : "Нет") << std::endl;
            std::cout << "Скоропортящийся:    " << (isPerishable ? "Да" : "Нет") << std::endl;

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
