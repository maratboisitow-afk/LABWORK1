#include <iostream>
#include <iomanip> // Для вывода частоты букв (setw, left)
#include <cctype>  // Для isalpha, isdigit, tolower

const int MAX_LEN = 1024; // Константа размера буфера

// Функция для безопасного ввода строки с ограничением длины
void inputString(char* buffer, int maxLen) {
    std::cout << "Введите текст (до " << maxLen - 1 << " символов):\n";
    std::cin.getline(buffer, maxLen);
}

// 1. Количество символов, слов и предложений
void analyzeBasicStats(const char* text, int& chars, int& words, int& sentences) {
    chars = 0;
    words = 0;
    sentences = 0;
    bool inWord = false;

    for (int i = 0; text[i] != '\0'; ++i) {
        chars++;
        char c = text[i];

        // Проверка на конец предложения
        if (c == '.' || c == '!' || c == '?') {
            sentences++;
        }

        // Проверка на слово (разделитель - пробел, согласно заданию)
        if (c == ' ') {
            inWord = false;
        }
        else if (!inWord) {
            inWord = true;
            words++;
        }
    }
}

// 2. Количество букв, цифр и пробелов
void countCharacters(const char* text, int& letters, int& digits, int& spaces) {
    letters = 0;
    digits = 0;
    spaces = 0;

    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];
        if (isalpha((unsigned char)c)) {
            letters++;
        }
        else if (isdigit((unsigned char)c)) {
            digits++;
        }
        else if (c == ' ') {
            spaces++;
        }
    }
}

// 3. Самое длинное слово (выводит копию слова в буфер result)
void findLongestWord(const char* text, char* result) {
    int maxLen = 0;
    int currentLen = 0;
    int startIdx = -1;
    int maxStartIdx = -1;

    for (int i = 0; ; ++i) {
        char c = text[i];

        // Слово заканчивается на пробеле или конце строки
        if (c == ' ' || c == '\0') {
            if (currentLen > maxLen) {
                maxLen = currentLen;
                maxStartIdx = startIdx;
            }
            currentLen = 0;
            startIdx = -1;
        }
        else {
            if (currentLen == 0) {
                startIdx = i;
            }
            currentLen++;
        }

        if (c == '\0') break;
    }

    // Копируем найденное слово в result вручную
    if (maxStartIdx != -1) {
        for (int i = 0; i < maxLen; ++i) {
            result[i] = text[maxStartIdx + i];
        }
        result[maxLen] = '\0';
    }
    else {
        result[0] = '\0'; // Если слов нет
    }
}

// 4. Количество вхождений заданного символа
int countCharOccurrences(const char* text, char target) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] == target) {
            count++;
        }
    }
    return count;
}

// 5. Частота каждой буквы (для латиницы)
void printLetterFrequency(const char* text) {
    int freq[26] = { 0 }; // Массив для букв 'a'-'z'

    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];
        if (isalpha((unsigned char)c)) {
            // Приводим к нижнему регистру и считаем индекс
            char lowerC = tolower((unsigned char)c);
            if (lowerC >= 'a' && lowerC <= 'z') {
                freq[lowerC - 'a']++;
            }
        }
    }

    std::cout << "\nЧастота латинских букв:\n";
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            char letter = 'a' + i;
            std::cout << letter << " : " << freq[i] << "\n";
        }
    }
}

int main() {
    char text[MAX_LEN];
    inputString(text, MAX_LEN);

    // 1
    int chars = 0, words = 0, sentences = 0;
    analyzeBasicStats(text, chars, words, sentences);
    std::cout << "\n1. Символов: " << chars << ", Слов: " << words << ", Предложений: " << sentences << "\n";

    // 2
    int letters = 0, digits = 0, spaces = 0;
    countCharacters(text, letters, digits, spaces);
    std::cout << "2. Букв: " << letters << ", Цифр: " << digits << ", Пробелов: " << spaces << "\n";

    // 3
    char longestWord[MAX_LEN] = { 0 };
    findLongestWord(text, longestWord);
    std::cout << "3. Самое длинное слово: " << longestWord << "\n";

    // 4
    char targetChar;
    std::cout << "4. Введите символ для поиска вхождений: ";
    std::cin >> targetChar;
    std::cout << "   Количество вхождений '" << targetChar << "': " << countCharOccurrences(text, targetChar) << "\n";

    // 5
    printLetterFrequency(text);

    return 0;
}