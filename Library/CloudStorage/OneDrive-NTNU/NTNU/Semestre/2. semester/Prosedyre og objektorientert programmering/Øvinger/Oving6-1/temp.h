#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <vector>

class Temps {
private:
    std::map<double, double> temp;
public:
    //Temps(std::map<double, double> tempMap) : temp(tempMap) {};
    Temps() {};
    //friend std::istream& operator>>(std::istream& is, const Temps& t);
    std::vector<double> readTemps(std::string fil);
    void readTemps1();
    void tempStats(std::vector<double> vec);
};