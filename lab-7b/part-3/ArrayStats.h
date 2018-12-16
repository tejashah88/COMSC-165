#ifndef ARRAYSTATS_H
#define ARRAYSTATS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

class ArrayStats
{
    public:
        ArrayStats(int size);
        ~ArrayStats() { delete [] numbers; }

        void setNumber(float value, int index) { numbers[index] = value; };
        float getNumber(int index) const { return numbers[index]; };

        float getMax() const;
        float getMin() const;
        float getAverage() const;

    private:
        int size;
        float * numbers;
};

#endif // ARRAYSTATS_H
