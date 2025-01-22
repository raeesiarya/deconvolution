#pragma once
//#include "std_lib_facilities.h"
#include <iostream>
#include <ostream>
#include <memory>

class Car{

private:
    int freeSeats;

public:
    Car(int f_s) : freeSeats{f_s} {};
    bool hasFreeSeats() const;
    void reserveFreeSeat();
    // ~Car(){
    //     delete freeSeats;
    // };

};

class Person {
private:
    std::string name;
    std::string email;
    std::unique_ptr<Car> car = nullptr;
public:
    Person(std::string n, std::string e, std::unique_ptr<Car> &c) : name{n}, email{e}, car{std::move(c)} {};
    void set(std::string em);
    std::string getName();
    std::string getEmail();
    bool hasAvailableSeats();
    friend std::ostream& operator<<(std::ostream os, const Person& p);
};