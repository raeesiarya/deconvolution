#pragma once
#include <iostream>
#include <vector>
#include "Car.h"


enum class Campus {
    Trondheim, Alesund, Gjovik
};

std::ostream& operator<<(std::ostream os, Campus campus);


class Meeting {
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    const std::shared_ptr<Person> leader;
    std::vector<std::shared_ptr<Person>> participants;
public:
    int getDay();
    int getStartTime();
    int getEndTime();
    Campus getLocation();
    std::string getSubject();
    const std::shared_ptr<Person> getLeader();
    std::vector<std::shared_ptr<Person>> addParticipants(std::shared_ptr<Person> p);

    Meeting(int d, int sT, int eT, Campus l, std::string sub, const std::shared_ptr<Person> le)
     : day{d}, startTime{sT}, endTime{eT}, location{l}, subject{sub}, leader{le} {};

    std::vector<std::string> getParticipantList();


    std::vector<std::shared_ptr<Person>> findPotentialCoDriving(const Meeting m) const;
};

std::ostream& operator<<(std::ostream& os, Meeting& m);