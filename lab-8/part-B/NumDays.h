#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {
    public:
        NumDays(int _hours) : hours(_hours) { calculateDays(); };

        int getHours() const { return hours; };
        void setHours(int _hours) { hours = _hours; };

        float getDays() const { return days; };
        void setDays(int _days) { days = _days; };

        NumDays operator+ (const NumDays &other) const { return NumDays(hours + other.hours); };
        NumDays operator- (const NumDays &other) const { return NumDays(abs(hours - other.hours)); };

        NumDays& operator++ () { hours++; calculateDays(); return *this; };
        NumDays operator++ (int) { NumDays temp = *this; ++*this; return temp; };

        NumDays& operator-- () { hours--; calculateDays(); return *this; };
        NumDays operator-- (int) { NumDays temp = *this; --*this; return temp; };

    private:
        int hours;
        float days;

        void calculateDays() { days = hours / 8.0f; }
};

#endif // NUMDAYS_H
