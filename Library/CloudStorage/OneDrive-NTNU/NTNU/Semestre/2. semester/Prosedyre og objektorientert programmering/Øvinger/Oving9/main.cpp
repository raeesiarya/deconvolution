#include <iostream>
#include "Car.h"
#include "Meeting.h"

int main() {
    std::unique_ptr<Car> myCar = std::make_unique<Car>(5);
    std::unique_ptr<Car> myCar1 = std::make_unique<Car>(4);
    std::unique_ptr<Car> myCar2 = std::make_unique<Car>(0);
    std::unique_ptr<Car> myCar3 = std::make_unique<Car>(1);

    Person Arya("Arya", "aryaraeesi@blinkweb.no", myCar);    
    Person Atle("Atle", "atlesund@blinkweb.no", myCar1);    
    Person Isak("Isak", "isaksjoberg@blinkweb.no", myCar2);    
    Person Erik("Erik", "erikstandal@blinkweb.no", myCar3);    
    
    Arya.set("vann@mann.com");
    std::cout << Arya.getName() << std::endl;
    std::cout << Arya.getEmail() << std::endl;


    std::cout << Arya.hasAvailableSeats() << std::endl;
    std::cout << Atle.hasAvailableSeats() << std::endl;
    std::cout << Isak.hasAvailableSeats() << std::endl;
    std::cout << Erik.hasAvailableSeats() << std::endl;


    std::shared_ptr<Person> Arya1 = std::make_shared<Person>("Arya", "aryaraeesi@blinkweb.no", myCar);
    std::shared_ptr<Person> Atle1 = std::make_shared<Person>("Atle", "atlesund@blinkweb.no", myCar1);
    std::shared_ptr<Person> Isak1 = std::make_shared<Person>("Isak", "isaksjoberg@blinkweb.no", myCar2);
    std::shared_ptr<Person> Erik1 = std::make_shared<Person>("Erik", "erikstandal@blinkweb.no", myCar3);

    Meeting m(3, 1330, 1530, Campus::Trondheim, "Matematikk", Arya1);
    m.addParticipants(Arya1);
    m.addParticipants(Atle1);
    m.addParticipants(Isak1);
    m.addParticipants(Erik1);

    std::cout << m << std::endl;

    //for(int k = 0; k < Meeting::getParticipantList().size())

    //return 0;
}