#include "std_lib_facilities.h"
#include "utilities.h"

int randomWithLimits(int ogrense,int ngrense) {
    default_random_engine tilfeldiggenerator;
    cout << tilfeldiggenerator.min() << " " << tilfeldiggenerator.max() << endl;
    return tilfeldiggenerator.min();

}