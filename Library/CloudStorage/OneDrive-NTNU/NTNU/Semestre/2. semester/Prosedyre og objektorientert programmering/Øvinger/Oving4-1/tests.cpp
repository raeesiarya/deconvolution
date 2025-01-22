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

char randomizeString(char a, char b) {
    char bokstav = randomWithLimits(a,b);
    return bokstav;
}

void testString() {
    string grades;
    vector<int> gj;

    char a = 'A';
    char b = 'F';

    for(int i = 0; i < 6; i++) {
    char bokstav = randomWithLimits(a,b);

    int tall = abs(int(bokstav) - 70);
    gj.push_back(tall);
    }

    double summ = 0;
    for(int j = 0; j < gj.size(); j++) {
        summ += gj.at(j);

    }
    cout << summ/gj.size() << endl;
}
