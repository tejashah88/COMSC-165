#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <string>

using namespace std;

class PersonData
{
    public:
        PersonData() : firstName(""), lastName(""), address(""), city(""), state(""), zip("") {};
        PersonData(string _firstName, string _lastName, string _address, string _city, string _state, string _zip)
            : firstName(_firstName), lastName(_lastName), address(_address), city(_city), state(_state), zip(_zip) {};

        string getFirstName() { return firstName; }
        void setFirstName(string val) { firstName = val; }

        string getLastName() { return lastName; }
        void setLastName(string val) { lastName = val; }

        string getAddress() { return address; }
        void setAddress(string val) { address = val; }

        string getCity() { return city; }
        void setCity(string val) { city = val; }

        string getState() { return state; }
        void setState(string val) { state = val; }

        string getZip() { return zip; }
        void setZip(string val) { zip = val; }

    private:
        string firstName, lastName, address, city, state, zip;
};

#endif // PERSONDATA_H
