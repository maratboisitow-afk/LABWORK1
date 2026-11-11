#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

const int MAX_DISHES = 100;

struct Dish {
    std::string name;
    double price;
};

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "СИСТЕМА УЧЕТА ЦЕН ШКОЛЬНОЙ СТОЛОВОЙ" << std::endl;

    Dish menu[MAX_DISHES]; 
    int count = 0;         

    std::cout << "Вводите названия блюд и их цены (пустое название для завершения):" << std::endl;

    while (count < MAX_DISHES) {
        std::string inputName;
        std::cout << "Название блюда: ";
        std::getline(std::cin, inputName);

        if (inputName.empty()) break; 

        double inputPrice;
        std::cout << "Цена (руб): ";

        
        while (!(std::cin >> inputPrice)) {
            std::cout << "Ошибка! Введите число: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        menu[count].name = inputName;
        menu[count].price = inputPrice;
        count++;
    }

    if (count == 0) {
        std::cout << "Список блюд пуст. Завершение работы." << std::endl;
        return 0;
    }

    
    std::cout << "\nТЕКУЩЕЕ МЕНЮ" << std::endl;
    std::cout << std::left << std::setw(20) << "Блюдо" << std::right << std::setw(10) << "Цена" << std::endl;
    std::cout << std::string(30, '-') << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << std::left << std::setw(20) << menu[i].name
            << std::right << std::setw(10) << std::fixed << std::setprecision(2) << menu[i].price << " руб." << std::endl;
    }

    double minPrice = menu[0].price;
    double maxPrice = menu[0].price;
    double sum = 0;

    for (int i = 0; i < count; i++) {
        if (menu[i].price < minPrice) minPrice = menu[i].price;
        if (menu[i].price > maxPrice) maxPrice = menu[i].price;
        sum += menu[i].price;
    }
    double avgPrice = sum / count;

    std::cout << "\n СТАТИСТИКА ЦЕН" << std::endl;
    std::cout << "Минимальная цена: " << minPrice << " руб." << std::endl;
    std::cout << "Максимальная цена: " << maxPrice << " руб." << std::endl;
    std::cout << "Средняя цена: " << avgPrice << " руб." << std::endl;

    std::cout << "\nБЛЮДА ДОРОЖЕ СРЕДНЕЙ ЦЕНЫ (" << avgPrice << " руб.)" << std::endl;
    bool foundAboveAvg = false;
    for (int i = 0; i < count; i++) {
        if (menu[i].price > avgPrice) {
            std::cout << "- " << menu[i].name << " (" << menu[i].price << " руб.)" << std::endl;
            foundAboveAvg = true;
        }
    }
    if (!foundAboveAvg) {
        std::cout << "Нет блюд дороже средней цены." << std::endl;
    }

    std::cout << "\nПОИСК БЛЮДА" << std::endl;
    std::cout << "Введите название блюда для поиска (или часть названия): ";
    std::string searchQuery;
    std::getline(std::cin, searchQuery);

    bool found = false;
    std::cout << "Результаты поиска:" << std::endl;
    for (int i = 0; i < count; i++) {
        if (menu[i].name.find(searchQuery) != std::string::npos) {
            std::cout << "- " << menu[i].name << " — " << menu[i].price << " руб." << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Блюда с таким названием не найдено." << std::endl;
    }

    return 0;
}