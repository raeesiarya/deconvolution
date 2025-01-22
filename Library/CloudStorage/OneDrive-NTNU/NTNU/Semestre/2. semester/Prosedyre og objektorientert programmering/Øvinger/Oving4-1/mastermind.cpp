#include "std_lib_facilities.h"
#include "mastermind.h"
#include "tests.cpp"


//Oppgave 4

int checkCharactersAndPosition(string a, string b) {
    int xlike = 0;
    for(int i = 0; i < a.length(); i++) {
        if(a.at(i) == b.at(i)) {
            xlike++;
        }
    }

    return xlike;
}

int checkCharacters(string a, string b) {
    int xlike = 0;
    int s = 0;
    for(int i = 0; i < b.length(); i++) {

        for(int j = 0; j < b.length(); j++) {
            if(b.at(j) == a.at(s)) {
                //cout << "Gammel a: " << a << ", Gammel b: " << b << endl;
                xlike++;
                int x1 = a.find(a.at(s));
                int x2 = b.find(b.at(j));

                a.replace(x1,1,"");
                b.replace(x2,1,"");
                //cout << "Ny a: " << a << ", Ny b: " << b << endl;
            }
        }
        s++;
    }
    return xlike;
};

void playMastermind() {
    constexpr int size = 4;
    constexpr int letters = 8;

    //Bruker constexpr og ikke const her siden constexpr blir definert med en gang koden kompileres,
    //mens const kompilerer først når det kjøres. Det ville vært bedre å bruke const når...

    int k = 0;
    string code;
    string guess;

    for(int i = 0; i < size; i++) {
        code += randomizeString('A', 'A'+letters-1);
    }

    while(guess < code and k < 6) {
        guess = readInputToString1('A', 'A'+letters-1, size);
        cout << "Feil, prøv igjen" << endl;
        cout << " " << endl;
        k++;
    }

    if(k == 6) {
        cout << "Synd det, riktig svar var " << code << endl;
    }
    else if(k != 5) {
        cout << "Riktig svar! Koden er " << code << endl;
    }
    //cout << code << endl;
    //cout << guess << endl;
    //cout << "Antall riktige gjettet: " << checkCharactersAndPosition(code, guess) << endl;
    //cout << "Antall riktige gjettet uavhengig av posisjon: " << checkCharacters(code, guess) << endl;

}