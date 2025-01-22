#pragma once
#include <iostream>
#include <map>
#include <fstream>
//#include <ostream>

class CourseCatalog {
private:
    std::map<std::string, std::string> course;
public:
    CourseCatalog(std::map<std::string, std::string> course) : course{course} {};
    friend std::ostream& operator<<(std::ostream& os, const CourseCatalog& c);
    CourseCatalog() {}
    void addCourse();
    void removeCourse();
    std::string getCourse();
    void wFile();
    void rFile();
};