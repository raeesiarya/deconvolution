
#include "std_lib_facilities.h"
//------------------------------------------------------------------------------'

//Oppgave 2b
int MaxOfTwo(int a,int b) {
	if(a > b) {
		cout << "A is greater than B" << endl;
		return a;
		}
	else {
		cout << "B is greater than A" << endl;
        return b;
	}
}

//Oppgave 2c
int fibonacci(int n) {
    int a = 0;
    int b = 1;

    cout << "Fibonacci numbers: " << endl;
    for(int x = 1; x < n+1; x++) {
        cout << x << ", " << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "---" << endl;
    return b;
}

//Oppgave 2d
int squareNumberSum(int n) {
    int totalSum = 0;
    for(int i = 1 ; i < n+1; i++) {
        totalSum += i * i;
        cout << i*i << endl;
    }
    cout << totalSum << endl;
    return totalSum;
}

// Oppgave 2e
int triangleNumbersBelow(int n) { //Hvorfor funker ikke void her
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ": " << endl;
    while(acc < n) {
        cout << acc << endl;
        acc += num;
        num++;
        return acc;
    }
}

// Oppgave 2f
bool isPrime(int n) {
    for(int j = 2 ; j <= n/2 ; ++j) {
        if(n % j == 0) {
            return false;
        }
    }
    return true;
}

// Oppgave 2g
void naivePrimeNumberSearch(int n) {
    for(int numbers = 2 ; numbers <= n ; numbers++) {
        if(isPrime(numbers) == 1) {
            cout << numbers << " is a prime" << endl;
        }
    }
}

// Oppgave 2h
int findGreatestDivisor(int n) {
    for(int divisor = n-1 ; divisor > 1 ; --divisor) {
        if(n % divisor == 0) {
            //cout << divisor << endl;
            return divisor;
        }
    }
    return 1;
}

int main() {
//Oppgave 2b
    cout << "Oppgave 2a)" << endl;
    cout << MaxOfTwo(5,6) << endl;

//Oppgave 2c
    cout << "----------" << endl;
    cout << fibonacci(5) << endl;

//Oppgave 2d
    cout << "----------" << endl;
    cout << squareNumberSum(5) << endl;

//Oppgave 2e
    cout << "----------" << endl;
    cout << triangleNumbersBelow(5) << endl;

//Oppgave 2f
    cout << "----------" << endl;
    cout << isPrime(2) << endl;

//Oppgave 2g
    cout << "----------" << endl;
    naivePrimeNumberSearch(14);

//Oppgave 2h
    cout << "----------" << endl;
    cout << findGreatestDivisor(14) << endl;
    cout << findGreatestDivisor(13) << endl;


return 0;

}