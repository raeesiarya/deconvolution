#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include "std_lib_facilities.h"


//1-------------------------------------
void writeFile() {
    std::string input;
    std::cout << "Skriv inn i fil: ";
    std::getline(std::cin, input);

    std::ofstream fileName{"myFile.txt"};

    fileName << input << std::endl;

    fileName.close();
    std::cout << input << " skrevet inn i fil";
}


void readFile() {
    std::ifstream fil("myFile.txt");
    std::ofstream fileName{"newFile.txt"};

    std::string line;

    while(std::getline(fil, line)) {
        fileName << line << std::endl;
        std::cout << line << " skrevet inn" << std::endl;
    }
}
//-------------------------------------

//2------------------------------------

void countLetters() {
    std::ifstream fil("grunnlov.txt");
    std::map<char, int> letterCount;
    char c;
    std::vector<char> tegn; 
    int tegnCount = 0;

    while(fil.get(c)) {
        tegn.push_back(c);
        tegnCount++;
    }

    for(char bokstav = 'a'; bokstav <= 'z'; bokstav++) {
        int k = 0;
        for(int i = 0 ; i < tegnCount; i++) {
            if(bokstav == tegn.at(i)) {
                k++;
            }
        }
        letterCount[bokstav] = k;

        std::cout << "Antall ganger " << bokstav << " er i teksten: " << letterCount[bokstav] << std::endl;
    }

    std::cout << "Antall tegn i teksten: " << tegnCount << std::endl;

}


//-------------------------------------

int main() {
    //1------------------------------------

    //writeFile();
    //readFile();

    //-------------------------------------
    //-------------------------------------
    //-------------------------------------


    //2------------------------------------

    countLetters();

    //2b: problemet er funksjonen getCapital der capitalsMap er ikke gjenkjent fra før av,
    //    derfor må du sette en map i getCapital, og sette inn capitalsMap når du printer ut.
    //    (rart å bruke iostream og std_lib_facilities.h samtidig)

    //-------------------------------------
    //-------------------------------------
    //-------------------------------------


    //3------------------------------------



    //-------------------------------------
    //-------------------------------------
    //-------------------------------------



    return 0;
}
