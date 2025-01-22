#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.cpp"

//Oppgave 1
void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}
//---------------

//Oppgave 2

//---------------

//Oppgave 3

char randomizeString() {
    char a = 'E';
    char b = 'X';

    for(int i = 0; i < 10; i++) {
    char bokstav = randomWithLimits(a,b);
    cout << bokstav;
    }
    return 1;
}

void testString() {
    string grades;
    vector<int> gj;

    for(int i = 0; i < 6; i++) {
        char karakter = randomWithLimits('B','F');
        if(karakter='A') {
        cout << karakter << endl;
    }
    cout << "" << endl;
}
