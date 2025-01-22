#include "std_lib_facilities.h"


const map<string, string> capitalsMap {
    {"Norway", "Oslo"},
    {"Sweden", "Stockholm"},
    {"Denmark", "Copenhagen"}
};


string getCapital(const string& country, map<string, string> land) {
    return land[country];
}


int main() {
    std::cout << "Capitals:" << std::endl;
    for (pair<const string, const string> elem : capitalsMap) {
    cout << getCapital(elem.first,capitalsMap) << std::endl;
}
}