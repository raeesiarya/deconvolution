#include "std_lib_facilities.h"
#include "utilities.h"

//Oppgave 1
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void swapNumbers(int a, int b) {
    a = a - 1;
    b = b +1;

    cout << a << " " << b << endl;
}
//-------------------

//Oppgave 2

void printStudent() {
    Student student;
    student.name = "Arya";
    student.studyProgram = "Elsys";
    student.age = 19;

    cout << "Navn:   " << student.name << endl;
    cout << "Studie: " << student.studyProgram << endl;
    cout << "Alder:  " << student.age << endl;
};

bool isInProgram() {
    string studie = "Indok";
    Student student;
    student.name = "Arya";
    student.studyProgram = "Elsys";
    student.age = 19;

    if(studie==student.studyProgram) {
        return true;
    }
    else {
        return false;
    }
}

//-------------------

//Oppgave 3

int randomWithLimits(int ngrense,int ogrense) {
    random_device rd;
    default_random_engine tilfeldiggenerator(rd());
    int lengde = abs(ogrense-ngrense);
    uniform_real_distribution<double> distribution(1,lengde);

    double number = distribution(tilfeldiggenerator);
    return 'A' + number-1;
}

int readInputToString() {
    char a;
    char b;
    cout << "Velg nedre grense (bokstav): ";
    cin >> a;
    cout << "Velg øvre grense (bokstav): ";
    cin >> b;
    int iterasjoner = abs(b-a);

    string streng;
    for(int i = 0; i < iterasjoner; i++) {
        char bokstav = (randomWithLimits(a,b));
        streng += bokstav;
    }

    //return streng; gikk ikke??
    cout << streng << endl;
    return 1;

};

string readInputToString1(char a, char b, int iterasjoner) {
    string streng;
    int b1 = char(b - 2);
    char b2 = char(b1);
    cout << "Velg bokstaver mellom " << a << " og " << b2 << endl;
    for(int i = 0; i < iterasjoner; i++) {
        //char bokstav = (randomWithLimits(a,b));
        char bokstav;
        cout << "Velg bokstav: ";
        cin >> bokstav;
        streng += toupper(bokstav);
    }
    return streng;

}

int countChar(char bokstav, string streng) {
    int count = 0;
    for(int i = 0; i < streng.size(); i++) {
        if(bokstav == streng[i]) {
            count++;
        }
    }
    return count;
};