#include "cannonball.h"
#include "std_lib_facilities.h"
#include <vector>
#include <string>
#include "utilities.cpp"


double acclY() {
    return -9.81;
};

double velY(double a, double b, double initVelocityY, double time) {
    double fartY = initVelocityY + acclY() * time;
    return fartY;
}

double posX(int initPosition, double initVelocity, double time) {
    double PositionX = initPosition + initVelocity*time+((0*pow(time,2.0))/2);
    return PositionX;
};

double posY(int initPosition, double initVelocity, double time) {
    double PositionY = initPosition + initVelocity*time+((acclY()*pow(time,2.0))/2);
    return PositionY;
};

void printTime(int time) {
    double timer = time / 3600;
    double min = (time / 60) % 60;
    double sekund = time % 60;
    cout << timer << " timer, " << min << " minutter og " << sekund << " sekunder" << endl;
};

double flightTime(double initVelocityY) {
    double Tid = (-2*initVelocityY)/acclY();
    return Tid;
};

void testDeviation(double compareOperand, double toOperand,double maxError, string name) {
    if (static_cast<int>(compareOperand) - static_cast<int>(toOperand) <= maxError) {
        cout << "Nice" << endl;
    }
    else {
        cout << "Ikke nice" << endl;
    }
};

double getUserInputTheta() {
    double vinkel;
    cout << "Oppgi vinkel: ";
    cin >> vinkel;
    return vinkel;
};

double getUserInputAbsVelocity() {
    double absfart;
    cout << "Oppgi absoluttfart: ";
    cin >> absfart;
    return absfart;
};

double degToRad(double deg) {
    double pi = 3.1415926;
    double rad = deg * (180/pi);
    return rad;
};

double getVelocityX(double theta, double absVelocity) {
    double fartX = absVelocity * cos(theta);
    return fartX;
};

double getVelocityY(double theta, double absVelocity) {
    double fartY = absVelocity * sin(theta);
    return fartY;
};

vector<double> getVelocityVector(double theta, double absVelocity) {
    vector<double> fartsvec;
    fartsvec.push_back(getVelocityX(theta,absVelocity));
    fartsvec.push_back(getVelocityY(theta,absVelocity));
    return fartsvec;
};

double getDistanceTraveled(double velocityX, double velocityY) {
    double flytid = flightTime(velocityY);
    double avstand = velocityX * flytid;
    return avstand;
};

double targetPractice(double distanceToTarget,double velocityX,double velocityY) {
    double kastavstand = getDistanceTraveled(velocityX,velocityY);
    double avvik = abs(distanceToTarget - kastavstand);
    return avvik;
};

//bool checkIfDistanceToTargetIsCorrect() {
//double error = targetPractice(0,0,0);
//if(error == 0) return true;
//}

//4e: ingen klammeparantes --> error: non-void function does not return a value in all control paths [-Werror,-Wreturn-type]



void playTargetPractice() {
    random_device rd;
    default_random_engine tilfeldiggenerator(rd());
    uniform_real_distribution<double> distribution(100,1000);
    double avstand = distribution(tilfeldiggenerator);

    //cout << avstand << endl;
    cout << " " << endl;

    double vinkel;
    double fart;

    int n = 0;

    for(int i = 0; i < 10; i++) {
        cout << "Velg vinkel: ";
        cin >> vinkel;
        cout << "Velg fart: ";
        cin >> fart;

        double skuddavstand = getDistanceTraveled(getVelocityX(vinkel, fart), getVelocityY(vinkel, fart));
        double skuddtid = flightTime(sin(vinkel)*fart);

        double avvik = (skuddavstand-avstand);
        cout << "Avstandsforskjell: " << avvik << " ---- " << "Tid brukt: " << skuddtid << endl;

        if(avvik <= 5) {
            n += 1;
        }

    }
    cout << " " << endl;

    if(n >= 1) {
        cout << "Grattis" << endl;
    }
    
    else {
        cout << "Du klarer det neste gang tjommi" << endl;
    }

};