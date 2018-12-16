#include "FactoryWorker.h"

string FactoryWorker::getShiftName() {
    if (shift == 1)
        return "Day";
    else if (shift == 2)
        return "Night";
    else
        return "Invalid";
}
