#include "opg3.h"


void CourseCatalog::addCourse() {
    course.insert({"TDT4110","Informasjonsteknologi grunnkurs"});
    course.insert({"TDT4102","Prosedyre- og objektorientert programmering"});
    course.insert({"TMA4100","Matematikk 1"});
    //course.insert({"TDT4102","Prosedyre- og objektorientert programmering"}); oppdaterer ikke
    course["TDT4102"] = "C++"; //oppdaterer
}

void CourseCatalog::removeCourse() {
    course.erase("TDT4102");
}


std::string CourseCatalog::getCourse() {
    std::string kurs = course["TDT4110"];
    //std::string kurs = course.at("TDT4110"); samme faen
    return kurs;
}

std::ostream& operator<<(std::ostream& os, const CourseCatalog& c) {
    for(auto const& element : c.course) {
        std::cout << "Fag: " << element.first << ", emnekode: " << element.second << std::endl;
    }
    return os;
}


void CourseCatalog::wFile() {
    std::ofstream fileName{"fag.txt"};

    for(auto const& element : course) {
        fileName << "Fag: " << element.first << ", emnekode: " << element.second << std::endl;
    }
}

void CourseCatalog::rFile() {
    std::ifstream fil("fag.txt");
    std::string line;

    while(std::getline(fil, line)) {
        std::cout << line << std::endl;
    }

}