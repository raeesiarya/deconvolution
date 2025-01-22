#include "dynamiskminne.h"

void fillInFibonacciNumbers(int* result, int length) {
    int a = 0;
    int b = 1;
    for(int i = 0; i < length; i++) {
        result[i] = a;
        int c = a + b;
        a = b;
        b = c;
    }
}

void printArray(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}

void createFibonacci() {
    cout << "Hvor mange tall skal genereres? ";
    int tall;
    int a = 0;
    int b = 1;
    cin >> tall;
    int *fibTall = new int[tall];
    for(int i = 0; i < tall; i++) {
        fibTall[i] = a;
        int c = a+b;
        a = b;
        b = c;
        cout << fibTall[i] << endl;
    }
    delete[] fibTall;
}