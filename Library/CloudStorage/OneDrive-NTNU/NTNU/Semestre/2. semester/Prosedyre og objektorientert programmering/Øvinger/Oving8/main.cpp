#include <iostream>
#include "dynamiskminne.h"
#include "matrix.h"
#include "dummytest.h"

int main() {

    //string vann = "Heei ";
    //vann.operator+= ("Yallah");
    //cout << vann << endl;

//1----------------------------------------
    /*
    int len = 10;
    int fibNumbers[len];
    fillInFibonacciNumbers(fibNumbers, len);
    printArray(fibNumbers,len);
    */
    //createFibonacci();


//-----------------------------------------

//2----------------------------------------
    Matrix A(2,2);
    A.set(1,1,1.0);
    A.set(1,2,2.0);
    A.set(2,1,3.0);
    A.set(2,2,4.0);

    Matrix B(2,2);
    B.set(1,1,4.0);
    B.set(1,2,3.0);
    B.set(2,1,2.0);
    B.set(2,2,1.0);

    Matrix C(2,2);
    C.set(1,1,1.0);
    C.set(1,2,3.0);
    C.set(2,1,1.5);
    C.set(2,2,2.0);

    A += B + C;

    cout << A << endl;


//-----------------------------------------

    return 0;
}