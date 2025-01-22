#include "Meeting.h"


//3a---------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, Campus campus) {
    switch (campus)
    {
    case Campus::Trondheim:
        os << "Trondheim";
        break;
    case Campus::Alesund:
        os << "Alesund";
        break;
    case Campus::Gjovik:
        os << "Gjovik";
        break;
    }
    return os;
}


//3b---------------------------------------------------------------
int Meeting::getDay() {
    return day;
}

int Meeting::getStartTime() {
    return startTime;
}

int Meeting::getEndTime() {
    return endTime;
}

Campus Meeting::getLocation() {
    return location;
}

std::string Meeting::getSubject() {
    return subject;
}

const std::shared_ptr<Person> Meeting::getLeader() {
    return leader;
}


//3c---------------------------------------------------------------

std::vector<std::shared_ptr<Person>> Meeting::addParticipants(std::shared_ptr<Person> p) {
    participants.push_back(p);
    return participants;
}

//3d---------------------------------------------------------------

/*3e: variabler som defineres inne i objektet (int, string...) blir lagret på stacken,
mens variablene som blir lagd ved hjelp av "new" (f.eks const std::shared_ptr<Person> getLeader()
og std::vector<std::shared_ptr<Person>> getParticipants(std::shared_ptr<Person> p)) lagret på heapen.
Variablene i objeket slettes automatisk mens variablene i heapen må slettes med "delete".
*/

//3f---------------------------------------------------------------

std::vector<std::string> Meeting::getParticipantList() {
    std::vector<std::string> vec;
    for(int i = 0; i < participants.size(); i++) {
        std::string s = participants.at(i)->getName();
        std::cout << s << std::endl;
        vec.push_back(s);
    }
    return vec;
}

//3g---------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, Meeting& m) {
    os << "Subject: " << m.getSubject() << "\n";
    //os << "Location: " << m.getLocation() << "\n"; //Hvafaen
    os << "Start time: " << m.getStartTime() << "\n";
    os << "End time: " << m.getEndTime() << "\n";
    os << "Leader: " << m.getLeader()->getName() << "\n";

    return os;
}

//3h---------------------------------------------------------------

std::vector<std::shared_ptr<Person>> findPotentialCoDriving(Meeting meet) const {
    std::vector<std::shared_ptr<Person>> output;
    if(meet.getLocation() == l)
}