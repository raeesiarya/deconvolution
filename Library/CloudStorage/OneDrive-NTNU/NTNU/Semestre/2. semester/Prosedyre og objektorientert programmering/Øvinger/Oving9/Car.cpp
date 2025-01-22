#include "Car.h"
#include <iostream>

//Car(int fs) : freeSeats{fs} {}
//Person(std::string n, std::string e, std::unique_ptr<Car>& c) : name{n}, email{e}, car{std::move(c)} {}

bool Car::hasFreeSeats() const{
    if(freeSeats == 0){
        return false;
    }
    return true;
    
};

void Car::reserveFreeSeat(){
    freeSeats--;
}

void Person::set(std::string em) {
    email = em;
}

std::string Person::getName() {
    return name;
}

std::string Person::getEmail() {
    return email;
}

bool Person::hasAvailableSeats() {
    if(car==nullptr) {
        return false;
    }
    return car->hasFreeSeats();
    //return Car::hasFreeSeats();
}

std::ostream& operator<<(std::ostream os, const Person& p) {
    os << p.name << std::endl;
    os << p.email << std::endl;
    os << p.car << std::endl;
    return os;
}