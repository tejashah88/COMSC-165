#ifndef TIMEOFF_H
#define TIMEOFF_H

#include <string>
#include "NumDays.h"

using namespace std;

class TimeOff {
    public:
        TimeOff(string _name, int _id) : name(_name), id(_id) {};

        NumDays getMaxSickDays() const { return maxSickDays; };
        void setMaxSickDays(NumDays &val) { maxSickDays = val; };

        NumDays getSickTaken() const { return sickTaken; };
        void setSickTaken(NumDays &val) { sickTaken = val; };

        NumDays getMaxVacation() const { return maxVacation; };
        void setMaxVacation(NumDays &val) { maxVacation = val; };

        NumDays getVacTaken() const { return vacTaken; };
        void setVacTaken(NumDays &val) { vacTaken = val; };

        NumDays getMaxUnpaid() const { return maxUnpaid; };
        void setMaxUnpaid(NumDays &val) { maxUnpaid = val; };

        NumDays getUnpaidTaken() const { return unpaidTaken; };
        void setUnpaidTaken(NumDays &val) { unpaidTaken = val; };

        void printInfo();


    private:
        NumDays maxSickDays;
        NumDays sickTaken;
        NumDays maxVacation;
        NumDays vacTaken;
        NumDays maxUnpaid;
        NumDays unpaidTaken;

        string name;
        int id;
};

#endif // TIMEOFF_H
