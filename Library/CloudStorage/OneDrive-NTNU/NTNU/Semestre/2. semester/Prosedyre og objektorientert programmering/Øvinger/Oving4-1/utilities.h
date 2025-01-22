#pragma once
#include "std_lib_facilities.h"

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
string readInputToString1(char a, char b, int iterasjoner);

int countChar(char bokstav, string streng);