#include <iostream>
#include <cstring> // Для проверки результатов (strlen, strcmp)

using namespace std;

// --- Часть 1: Собственные функции ---

// 1. Длина строки
int myStrLen(const char s[]) {
    int len = 0;
    // Идем по массиву, пока не встретим нулевой символ конца строки
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

// 2. Копирование строки
void myStrCopy(char dst[], const char src[]) {
    int i = 0;
    // Копируем символы, пока не дойдем до '\0'
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    // Обязательно добавляем нулевой символ в конец
    dst[i] = '\0';
}

// 3. Сравнение на равенство
bool myStrEqual(const char a[], const char b[]) {
    int i = 0;
    // Идем по строкам, пока символы равны и не конец
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return false; // Нашли различие
        }
        i++;
    }
    // Если цикл закончился, проверяем, что обе строки закончились одновременно
    // (на случай, если одна строка является префиксом другой)
    return a[i] == b[i];
}

// 4. Разворот строки на месте
void myStrReverse(char s[]) {
    int len = myStrLen(s); // Используем нашу функцию для получения длины
    int left = 0;
    int right = len - 1;

    // Меняем местами символы с начала и с конца, двигаясь к центру
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

// --- Функция для демонстрации ---

int main() {
    // Размер буфера задан константой
    const int SIZE = 100;
    char str1[SIZE];
    char str2[SIZE];
    char strCopy[SIZE];

    cout << "Введите первую строку: ";
    cin >> str1; // Ввод с ограничением размера (до пробела)

    cout << "Введите вторую строку: ";
    cin >> str2;

    cout << "\n--- Проверка ---\n";

    // 1. Проверка длины
    int myLen = myStrLen(str1);
    int stdLen = strlen(str1);
    cout << "Длина \"" << str1 << "\": my=" << myLen << ", std=" << stdLen
        << (myLen == stdLen ? " (OK)" : " (FAIL)") << endl;

    // 2. Проверка копирования
    myStrCopy(strCopy, str1);
    cout << "Копия строки: " << strCopy << endl;
    // Сравниваем через стандартную функцию, так как наша myStrEqual еще проверяется
    if (strcmp(strCopy, str1) == 0) {
        cout << "Копирование корректно (OK)" << endl;
    }
    else {
        cout << "Копирование с ошибкой (FAIL)" << endl;
    }

    // 3. Проверка сравнения
    bool myEq = myStrEqual(str1, str2);
    bool stdEq = (strcmp(str1, str2) == 0);
    cout << "Строки равны? my=" << boolalpha << myEq
        << ", std=" << stdEq
        << (myEq == stdEq ? " (OK)" : " (FAIL)") << endl;

    // 4. Проверка разворота
    // Скопируем str1, чтобы не испортить её, и развернем копию
    char strRev[SIZE];
    myStrCopy(strRev, str1);

    myStrReverse(strRev);
    cout << "Развернутая строка: " << strRev << endl;

    // Проверка разворота (можно проверить визуально или написав доп. логику)
    // Для проверки стандартом можно было бы использовать std::reverse, 
    // но здесь мы просто выводим результат.

    return 0;
}
