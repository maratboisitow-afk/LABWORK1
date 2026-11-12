#include <iostream>
#include <cstring> // Для strlen в main (для удобства), но в функциях — свои реализации
#include <limits>  // Для очистки потока ввода

using namespace std;

// 1. Размер буфера задан константой
const int MAX_SIZE = 256;

// --- Вспомогательные функции (свои аналоги) ---

// Своя реализация длины строки
int my_strlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Своя реализация копирования (для создания копий, если нужно)
void my_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// --- Функции Части 3 ---

// 1. Приведение к верхнему и нижнему регистру
// Возвращает новую строку (верхний регистр), исходную не меняет (const)
void toUpperCase(const char* src, char* dest) {
    int i = 0;
    while (src[i] != '\0') {
        if (src[i] >= 'a' && src[i] <= 'z') {
            dest[i] = src[i] - 32; // Преобразование ASCII
        }
        else {
            dest[i] = src[i];
        }
        i++;
    }
    dest[i] = '\0';
}

void toLowerCase(const char* src, char* dest) {
    int i = 0;
    while (src[i] != '\0') {
        if (src[i] >= 'A' && src[i] <= 'Z') {
            dest[i] = src[i] + 32; // Преобразование ASCII
        }
        else {
            dest[i] = src[i];
        }
        i++;
    }
    dest[i] = '\0';
}

// 2. Удаление лишних пробелов
// Модифицирует строку на месте
void removeExtraSpaces(char* str) {
    int len = my_strlen(str);
    int writeIdx = 0;
    bool lastWasSpace = true; // true, чтобы удалить пробелы в начале

    for (int readIdx = 0; readIdx < len; readIdx++) {
        if (str[readIdx] != ' ') {
            str[writeIdx++] = str[readIdx];
            lastWasSpace = false;
        }
        else {
            if (!lastWasSpace) {
                str[writeIdx++] = ' ';
                lastWasSpace = true;
            }
        }
    }

    // Удаляем пробел в конце, если он остался
    if (writeIdx > 0 && str[writeIdx - 1] == ' ') {
        writeIdx--;
    }
    str[writeIdx] = '\0';
}

// 3. Замена символа
void replaceChar(char* str, char oldChar, char newChar) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
        i++;
    }
}

// 4. Проверка на палиндром (без учета регистра и пробелов)
bool isPalindrome(const char* str) {
    int left = 0;
    int right = my_strlen(str) - 1;

    while (left < right) {
        // Пропускаем пробелы слева
        while (str[left] == ' ' && left < right) left++;
        // Пропускаем пробелы справа
        while (str[right] == ' ' && left < right) right--;

        // Приводим к нижнему регистру для сравнения
        char cLeft = str[left];
        char cRight = str[right];

        if (cLeft >= 'A' && cLeft <= 'Z') cLeft += 32;
        if (cRight >= 'A' && cRight <= 'Z') cRight += 32;

        if (cLeft != cRight) return false;

        left++;
        right--;
    }
    return true;
}

// Вспомогательная функция для вывода (принимает const)
void printString(const char* str) {
    cout << str << endl;
}

int main() {
    // Установка локали для корректной работы с кириллицей (опционально, 
    // но полезно, если нужно обрабатывать русские буквы. 
    // В рамках strict C++ без стандартных функций это сложнее, 
    // поэтому код выше ориентирован на ASCII/латиницу).

    char buffer[MAX_SIZE];
    char resultBuffer[MAX_SIZE];

    cout << "Введите строку (макс " << MAX_SIZE - 1 << " символов): ";
    // Ввод с ограничением длины
    cin.getline(buffer, MAX_SIZE);

    // Очистка потока на случай, если ввели больше символов
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nИсходная строка: ";
    printString(buffer);

    // --- Задание 1 ---
    toUpperCase(buffer, resultBuffer);
    cout << "1. Верхний регистр: ";
    printString(resultBuffer);

    toLowerCase(buffer, resultBuffer);
    cout << "   Нижний регистр:  ";
    printString(resultBuffer);

    // --- Задание 2 ---
    // Работаем с копией, чтобы не портить оригинал для других тестов
    char tempStr[MAX_SIZE];
    my_strcpy(tempStr, buffer);
    removeExtraSpaces(tempStr);
    cout << "2. Без лишних пробелов: ";
    printString(tempStr);

    // --- Задание 3 ---
    // Пример: заменим 'a' на 'o' (или любой другой символ)
    // Скопируем заново, так как removeExtraSpaces испортил tempStr
    my_strcpy(tempStr, buffer);
    cout << "3. Замена (например, 'a' -> 'A'): ";
    replaceChar(tempStr, 'a', 'A');
    printString(tempStr);

    // --- Задание 4 ---
    // Проверка палиндрома на исходной строке
    if (isPalindrome(buffer)) {
        cout << "4. Строка является палиндромом." << endl;
    }
    else {
        cout << "4. Строка НЕ является палиндромом." << endl;
    }

    return 0;
}
