#include "std_lib_facilities.h"
#include "utilities.h"

int randomWithLimits(int ngrense,int ogrense) {
    random_device rd;
    default_random_engine tilfeldiggenerator(rd());
    uniform_real_distribution<double> distribution(1,100);

    for (int i = 0; i<10; i++){
        double number = distribution(tilfeldiggenerator);
        cout << number << '\n';
    }
    return 0;
}