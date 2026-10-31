#include <string>
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int main(); {
        int n, i;

        // Ввод числа с проверкой корректности (цикл do-while)
        do {
            std::cout << "Введите число (1-10): ";
            std::cin >> n;
        } while (n < 1 || n > 10);

        // Вывод таблицы умножения (цикл for)
        std::cout << "Таблица умножения для числа " << n << ":" << std::endl;
        for (int i = 1; i <= 10; i++) {
            std::cout << n << "*" << i << "=" << n * i << std::endl;// Код студента
        }
    }
    return 0;
}