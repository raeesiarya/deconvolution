#include "animal.h"

string Animal::toString() {
    return "Animal: " + name + ", " + to_string(age);
}

string Dog::toString() {
    return "Dog: " + name + ", " + to_string(age);
}

string Cat::toString() {
    return "Cat: " + name + ", " + to_string(age);
}