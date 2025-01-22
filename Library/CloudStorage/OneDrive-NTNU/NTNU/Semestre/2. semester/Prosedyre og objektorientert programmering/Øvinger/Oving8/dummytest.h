#pragma once
#include <iostream>
#include <utility>

using namespace std;

// 3a: Vetsj

class Dummy {
public:
    int *num;

    Dummy() {
        num = new int{0};
    }

    Dummy(const Dummy& rhs) : num{nullptr} {
        this->num = new int{};
        *num = *rhs.num;
    }

    Dummy& operator=(Dummy rhs) {
        swap(this->num, rhs.num);
        cout << "sverg tjommi" << endl;
        return *this;
    }

    ~Dummy() {
        delete num;
    }
};

void dummyTest();
