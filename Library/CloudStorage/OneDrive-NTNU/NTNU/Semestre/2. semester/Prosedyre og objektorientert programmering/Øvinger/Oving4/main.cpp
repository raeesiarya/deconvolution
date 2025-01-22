#include "std_lib_facilities.h"
#include "tests.cpp"

//1a
//v0: 5 increment: 2 iterations: 10 result: 25

int main() {
    int oppgave;
    cout << "Velg oppgave: ";
    cin >> oppgave;

    switch(oppgave) {
        case 1:
            //Oppgave 1
            testCallByValue();
            testCallByReference();
            swapNumbers(5, 8);

            break;
            //--------------------

        case 2:
            //Oppgave 2
            printStudent();
            cout << isInProgram() << endl;

            //2e: inkludering av header-fil i en annen header-fil fører til feil.
            break;

        case 3:
            //Oppgave 3

            cout << randomizeString() << endl;
            testString();
            cout << readInputToString() << endl;
            break;
    }
    return 0;
}

//------------------------------------------------------------------------------
