#include "temp.h"

std::istream& operator>>(std::istream& is, const Temps& t) {
    std::filesystem::path temperatureFile{"temperatures.txt"};
   std::ifstream temp_file{temperatureFile};
    temp_file >> t;
    return is;
}

std::vector<double> Temps::readTemps(std::string fil) {
    std::ifstream file(fil);
    std::vector<double> vektor;
    std::string line;

    while(std::getline(file, line)) {
        //std::cout << line << std::endl;
        //vektor.push_back(double(line.substr(0,pos)));
        std::string st2 = line.substr(0, 4);
        std::string st3 = line.substr(4);

        double a = std::stod(st2);
        double b = std::stod(st3);

        vektor.push_back(a);
        vektor.push_back(b);


        //std::string st1 = line[0,pos];
        //std::string st2 = line.substr(pos+1);
        //std::cout << st1 << " " << st2 << std::endl;
        //std::cout << st2 << "                 " << st3 << std::endl;

    }
    return vektor;
}


void Temps::readTemps1() {
    std::ifstream file("temperatures.txt");
    std::vector<double> vektor;
    std::string line;

    while(std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

void Temps::tempStats(std::vector<double> vec) {
    double a = *std::max_element(vec.begin(),vec.end());
    double b = *std::min_element(vec.begin(),vec.end());
    int i = 0;
    int j = 0;

    while(vec.at(i) != a) {
        i++;
    }

    while(vec.at(j) != b) {
        j++;
    }

    if(i % 2 != 0) {
        i--;
    }

    if(j % 2 != 0) {
        j--;
    }

    double dagmax = i / 2;
    double dagmin = j / 2;

    std::cout << "Maksimal temperatur: " << a << " på dag: " << dagmax << std::endl;
    std::cout << "Minimal temperatur: " << b << " på dag: " << dagmin << std::endl;
    
}

