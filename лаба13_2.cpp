#include <iostream>
#include <string>
#include <limits> // для очистки потока ввода
#include <windows.h>

// --- Прототипы функций ---

// Перегруженные функции расширения массивов (grow)
void grow(std::string*& arr, int size, int newCapacity);
void grow(int*& arr, int size, int newCapacity);
void grow(double*& arr, int size, int newCapacity);

// Добавление записи
void addDish(std::string*& names, int*& portions, double*& prices,
    int& size, int& capacity,
    const std::string& name, int portion, double price);

// Вывод всех записей
void printDishes(const std::string* names, const int* portions, const double* prices, int size);

// Поиск по названию (возвращает индекс или -1)
int findByName(const std::string* names, int size, const std::string& targetName);

// Удаление записи по индексу со сдвигом
void removeDish(std::string* names, int* portions, double* prices, int& size, int index);

// Вычисление среднего и максимального значения для числового поля (цена)
void calculatePriceStats(const double* prices, int size, double& avg, double& maxVal);

// Вспомогательная функция для безопасного ввода числа
void clearInput();

// --- Основная программа ---

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Начальная ёмкость по условию = 2
    int capacity = 2;
    int size = 0;

    // Выделение памяти под параллельные массивы
    std::string* names = new std::string[capacity];
    int* portions = new int[capacity];
    double* prices = new double[capacity];

    std::cout << "=== ШКОЛЬНАЯ СТОЛОВАЯ (Вариант 37) ===" << std::endl;

    int choice;
    do {
        std::cout << "\nМеню:" << std::endl;
        std::cout << "1. Добавить блюдо" << std::endl;
        std::cout << "2. Вывести все блюда" << std::endl;
        std::cout << "3. Найти блюдо по названию" << std::endl;
        std::cout << "4. Удалить блюдо по индексу" << std::endl;
        std::cout << "5. Статистика цен (средняя и макс.)" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            clearInput();
            std::cout << "Ошибка ввода. Попробуйте снова." << std::endl;
            continue;
        }

        switch (choice) {
        case 1: {
            std::string name;
            int portion;
            double price;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера
            std::cout << "Введите название блюда: ";
            std::getline(std::cin, name);

            std::cout << "Введите порцию (г/мл): ";
            std::cin >> portion;
            if (std::cin.fail()) {
                clearInput();
                std::cout << "Некорректная порция." << std::endl;
                break;
            }

            std::cout << "Введите цену: ";
            std::cin >> price;
            if (std::cin.fail()) {
                clearInput();
                std::cout << "Некорректная цена." << std::endl;
                break;
            }

            addDish(names, portions, prices, size, capacity, name, portion, price);
            std::cout << "Блюдо добавлено. Текущий размер: " << size << ", ёмкость: " << capacity << std::endl;
            break;
        }
        case 2:
            printDishes(names, portions, prices, size);
            break;
        case 3: {
            std::string searchName;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введите название для поиска: ";
            std::getline(std::cin, searchName);

            int idx = findByName(names, size, searchName);
            if (idx != -1) {
                std::cout << "Найдено: " << names[idx] << ", порция: " << portions[idx]
                    << ", цена: " << prices[idx] << std::endl;
            }
            else {
                std::cout << "Блюдо не найдено." << std::endl;
            }
            break;
        }
        case 4: {
            if (size == 0) {
                std::cout << "Список пуст." << std::endl;
                break;
            }
            int idx;
            std::cout << "Введите индекс для удаления (0.." << size - 1 << "): ";
            std::cin >> idx;
            if (std::cin.fail() || idx < 0 || idx >= size) {
                clearInput();
                std::cout << "Некорректный индекс." << std::endl;
            }
            else {
                removeDish(names, portions, prices, size, idx);
                std::cout << "Блюдо удалено." << std::endl;
            }
            break;
        }
        case 5: {
            if (size == 0) {
                std::cout << "Нет данных для статистики." << std::endl;
            }
            else {
                double avg, maxVal;
                calculatePriceStats(prices, size, avg, maxVal);
                std::cout << "Средняя цена: " << avg << std::endl;
                std::cout << "Максимальная цена: " << maxVal << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "Выход..." << std::endl;
            break;
        default:
            std::cout << "Неверный пункт меню." << std::endl;
        }
    } while (choice != 0);

    // --- Освобождение памяти ---
    // Проверка на nullptr перед удалением (хотя new[] вернул валидный указатель)
    if (names != nullptr) {
        delete[] names;
        names = nullptr;
    }
    if (portions != nullptr) {
        delete[] portions;
        portions = nullptr;
    }
    if (prices != nullptr) {
        delete[] prices;
        prices = nullptr;
    }

    std::cout << "Память освобождена. Программа завершена." << std::endl;
    return 0;
}

// --- Реализация функций ---

// Перегрузка для string
void grow(std::string*& arr, int size, int newCapacity) {
    std::string* newArr = new std::string[newCapacity];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

// Перегрузка для int
void grow(int*& arr, int size, int newCapacity) {
    int* newArr = new int[newCapacity];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

// Перегрузка для double
void grow(double*& arr, int size, int newCapacity) {
    double* newArr = new double[newCapacity];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

void addDish(std::string*& names, int*& portions, double*& prices,
    int& size, int& capacity,
    const std::string& name, int portion, double price) {
    // Если места нет, увеличиваем ёмкость в 2 раза
    if (size >= capacity) {
        int newCapacity = capacity * 2;
        grow(names, size, newCapacity);
        grow(portions, size, newCapacity);
        grow(prices, size, newCapacity);
        capacity = newCapacity;
    }

    // Добавление элемента
    names[size] = name;
    portions[size] = portion;
    prices[size] = price;
    size++;
}

void printDishes(const std::string* names, const int* portions, const double* prices, int size) {
    if (size == 0) {
        std::cout << "Список блюд пуст." << std::endl;
        return;
    }
    std::cout << "\n--- Список блюд ---" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << i << ". " << names[i]
            << " | Порция: " << portions[i] << " г"
            << " | Цена: " << prices[i] << " руб." << std::endl;
    }
}

int findByName(const std::string* names, int size, const std::string& targetName) {
    for (int i = 0; i < size; ++i) {
        if (names[i] == targetName) {
            return i;
        }
    }
    return -1;
}

void removeDish(std::string* names, int* portions, double* prices, int& size, int index) {
    if (index < 0 || index >= size) return;

    // Сдвиг элементов влево, начиная с удаляемого
    for (int i = index; i < size - 1; ++i) {
        names[i] = names[i + 1];
        portions[i] = portions[i + 1];
        prices[i] = prices[i + 1];
    }
    size--;
}

void calculatePriceStats(const double* prices, int size, double& avg, double& maxVal) {
    if (size == 0) return;

    double sum = 0.0;
    maxVal = prices[0];

    for (int i = 0; i < size; ++i) {
        sum += prices[i];
        if (prices[i] > maxVal) {
            maxVal = prices[i];
        }
    }
    avg = sum / size;
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
