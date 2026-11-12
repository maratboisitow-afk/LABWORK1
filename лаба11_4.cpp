#include <iostream>
#include <cstring> // Нужен только для ввода/вывода, не для обработки строк

// 1. Размер буфера задан константой
const int MAX_LEN = 256;

// Класс для управления строкой без использования std::string
class MyString {
private:
    char data[MAX_LEN];

public:
    // Конструктор по умолчанию
    MyString() {
        data[0] = '\0';
    }

    // Ввод строки с ограничением длины
    void input() {
        std::cout << "Введите строку (макс. " << MAX_LEN - 1 << " символов): ";
        // Используем std::cin.getline для безопасного ввода в char массив
        std::cin.getline(data, MAX_LEN);
    }

    // Получение доступа к данным (только чтение)
    const char* getRaw() const {
        return data;
    }

    // Получение доступа к данным (для записи)
    char* getRawMutable() {
        return data;
    }

    // Собственная функция длины строки
    int my_strlen(const char* str) const {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }
};

// --- Вспомогательные функции (без стандартных аналогов) ---

// Проверка, является ли символ разделителем (пробел, таб, новая строка)
bool isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Копирование части строки
void my_strncpy(char* dest, const char* src, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[n] = '\0';
}

// --- Функции из Части 4 ---

// 1. Разбейте строку на слова и выведите каждое с новой строки.
// (Также выводит слова в обратном порядке, если передать reverse=true)
void printWords(const char* str, bool reverse = false) {
    // Сначала найдем начало и конец каждого слова
    // Так как мы не можем использовать векторы, мы будем проходить строку дважды 
    // или использовать рекурсию/вспомогательные буферы.
    // Для простоты и соблюдения требований, мы выделим слова вручную в буферы.

    // Внимание: Для "обратного порядка" без std::string сложнее всего сохранить слова.
    // Мы создадим массив указателей на начала слов внутри исходной строки (модифицируя её нельзя, 
    // поэтому будем использовать подход с индексами или копированием).

    if (!reverse) {
        int i = 0;
        while (str[i] != '\0') {
            // Пропускаем пробелы
            if (isSpace(str[i])) {
                i++;
                continue;
            }
            // Начало слова
            int start = i;
            while (str[i] != '\0' && !isSpace(str[i])) {
                i++;
            }
            // Конец слова (i)
            // Выводим слово
            for (int k = start; k < i; k++) {
                std::cout << str[k];
            }
            std::cout << std::endl;
        }
    }
    else {
        // Для обратного порядка: собираем индексы начал и длин слов
        // Так как нельзя использовать std::vector, используем статические массивы
        const int MAX_WORDS = 128;
        int starts[MAX_WORDS];
        int lengths[MAX_WORDS];
        int wordCount = 0;

        int i = 0;
        while (str[i] != '\0') {
            if (isSpace(str[i])) {
                i++;
                continue;
            }
            int start = i;
            while (str[i] != '\0' && !isSpace(str[i])) {
                i++;
            }
            if (wordCount < MAX_WORDS) {
                starts[wordCount] = start;
                lengths[wordCount] = i - start;
                wordCount++;
            }
        }

        // Вывод в обратном порядке
        for (int w = wordCount - 1; w >= 0; w--) {
            for (int k = 0; k < lengths[w]; k++) {
                std::cout << str[starts[w] + k];
            }
            std::cout << std::endl;
        }
    }
}

// 2. Найти слова, начинающиеся с заданной буквы.
void findWordsStartingWith(const char* str, char targetChar) {
    std::cout << "Слова на букву '" << targetChar << "':" << std::endl;
    int i = 0;
    bool found = false;
    while (str[i] != '\0') {
        if (isSpace(str[i])) {
            i++;
            continue;
        }
        // Начало слова
        int start = i;
        while (str[i] != '\0' && !isSpace(str[i])) {
            i++;
        }

        // Проверяем первую букву
        if (str[start] == targetChar) {
            for (int k = start; k < i; k++) {
                std::cout << str[k];
            }
            std::cout << std::endl;
            found = true;
        }
    }
    if (!found) std::cout << "(не найдено)" << std::endl;
}

// 3. Подсчитать количество слов заданной длины.
int countWordsOfLength(const char* str, int targetLen) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (isSpace(str[i])) {
            i++;
            continue;
        }
        int start = i;
        while (str[i] != '\0' && !isSpace(str[i])) {
            i++;
        }
        int currentLen = i - start;
        if (currentLen == targetLen) {
            count++;
        }
    }
    return count;
}

// --- Главная функция ---
int main() {
    MyString myStr;
    myStr.input();

    const char* rawStr = myStr.getRaw();

    // Проверка на пустую строку
    if (myStr.my_strlen(rawStr) == 0) {
        std::cout << "Строка пуста." << std::endl;
        return 0;
    }

    std::cout << "\n--- 1. Слова с новой строки ---" << std::endl;
    printWords(rawStr, false);

    std::cout << "\n--- 2. Слова в обратном порядке ---" << std::endl;
    printWords(rawStr, true);

    std::cout << "\n--- 3. Поиск слов по первой букве ---" << std::endl;
    char searchChar;
    std::cout << "Введите букву для поиска: ";
    std::cin >> searchChar;
    // Очистка буфера ввода после cin
    std::cin.ignore(10000, '\n');
    findWordsStartingWith(rawStr, searchChar);

    std::cout << "\n--- 4. Подсчет слов заданной длины ---" << std::endl;
    int lenToFind;
    std::cout << "Введите длину слова для поиска: ";
    std::cin >> lenToFind;
    int count = countWordsOfLength(rawStr, lenToFind);
    std::cout << "Найдено слов длины " << lenToFind << ": " << count << std::endl;

    return 0;
}