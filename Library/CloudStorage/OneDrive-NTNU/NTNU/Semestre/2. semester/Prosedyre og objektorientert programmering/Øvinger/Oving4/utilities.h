#pragma once

//Oppgave 1
int incrementByValueNumTimes(int startValue, int increment, int numTimes);
int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
//----------------

//Oppgave 2
struct Student {
    string name;
    string studyProgram;
    int age;
};

void printStudent();

bool isInProgram();
//----------------


//Oppgave 3
int randomWithLimits(int ngrense,int ogrense);

int readInputToString();

int countChar(char bokstav, string streng);