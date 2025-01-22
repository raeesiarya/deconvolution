#pragma once

double acclY();
double velY(double a, double b, double initVelocityY, double time);

double posX(int initPosition, double initVelocity, double time);
double posY(int initPosition, double initVelocity, double time);

void printTime(double time);
double flightTime(double initVelocityY);

void testDeviation(double compareOperand, double toOperand,double maxError,string name);

double getUserInputTheta();
double getUserInputAbsVelocity();
double degToRad(double deg);
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

vector<double> getVelocityVector(double theta, double absVelocity);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget,double velocityX,double velocityY);

//4e
//bool checkIfDistanceToTargetIsCorrect();

void playTargetPractice();