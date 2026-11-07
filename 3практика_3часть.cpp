#include <iostream>
#include <iomanip>  
#include <cmath>    
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double start = -2.0;  
    double end = 2.0;     
    double step = 0.5;    

    double minVal = 1e9;
    double maxVal = -1e9;

    int signChanges = 0;   
    double prevY = 0;      
    bool isFirst = true;  

    cout << "-----------------------" << endl;
    cout << setw(10) << "X" << " | " << setw(10) << "Y(x)" << endl;
    cout << "-----------------------" << endl;

    for (double x = start; x <= end + 1e-9; x += step) { 

        double y = x * x - 1;

        cout << fixed << setprecision(2)
            << setw(10) << x << " | "
            << setw(10) << y << endl;

        if (y < minVal) minVal = y;
        if (y > maxVal) maxVal = y;

        if (!isFirst && y != 0 && prevY != 0) {
            if ((prevY > 0 && y < 0) || (prevY < 0 && y > 0)) {
                signChanges++;
            }
        }

        prevY = y;
        isFirst = false;
    }

    cout << "-----------------------" << endl;

    cout << "Наибольшее значение: " << maxVal << endl;
    cout << "Наименьшее значение: " << minVal << endl;
    cout << "Смена знака произошла: " << signChanges << " раз(а)." << endl;

    return 0;
}