#ifndef FACTORYWORKER_H
#define FACTORYWORKER_H

#include "Worker.h"

using namespace std;

class FactoryWorker : public Worker {
    public:
        FactoryWorker() : Worker() {}
        FactoryWorker(
            string _name, int _id, string _employmentDate,
            int _shift, double _payRate
        ) : Worker(_name, _id, _employmentDate), shift(_shift), payRate(_payRate) {};

        int getShift() { return shift; }
        void setShift(int val) { shift = val; }
        double getPayRate() { return payRate; }
        void setPayRate(double val) { payRate = val; }

        string getShiftName();

    private:
        int shift;
        double payRate;
};

#endif // FACTORYWORKER_H
