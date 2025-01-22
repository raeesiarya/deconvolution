#include "std_lib_facilities.h"
#include "cannonball.cpp"
//#include "utilities.cpp"

int main() {
    cout << acclY() << endl;
    cout << velY(0, 0, 25, 2.5) << endl;
    cout << posX(0, 50, 5) << endl;
    cout << posY(0, 25, 2.5) << endl;
    printTime(4500);
    cout << flightTime(20) << endl;
    vector<double> getVelocityVector(27.5, 15.64);
    cout << getDistanceTraveled(27.5, 15.64) << endl;
    cout << targetPractice(20, 27.5, 15.64) << endl;
    //cout << randomWithLimits(0,5) << endl;
    //4e
    //cout << checkIfDistanceToTargetIsCorrect() << endl;


    testDeviation(posX(0.0,50.0,5.0), 250.0, 0.0001, "posX(0.0,50.0,5.0)");
    testDeviation(posY(0.0, 25.0, 2.5), 31.84, 0.0000001, "posY(0.0,25.0,2.5)");
    testDeviation(velY(0, 0, 25, 5), -24.05, 0.0000001, "velY(0, 0, 25, 5)");
    testDeviation(acclY(), -9.81, 0.01, "acclY()");

    return 0;
}