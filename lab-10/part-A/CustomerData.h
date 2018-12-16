#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h"


class CustomerData : public PersonData
{
    public:
        CustomerData() : PersonData(), customerNumber(0), mailingList(false) {};
        CustomerData(string _firstName, string _lastName, string _address,
                     string _city, string _state, string _zip,
                     int _custNumber, bool _mailList
                     ) : PersonData(_firstName, _lastName, _address, _city, _state, _zip),
                        customerNumber(_custNumber), mailingList(_mailList) {};

        int getCustomerNumber() { return customerNumber; }
        void setCustomerNumber(int val) { customerNumber = val; }

        bool getMailingList() { return mailingList; }
        void setMailingList(bool val) { mailingList = val; }

    private:
        int customerNumber;
        bool mailingList;
};

#endif // CUSTOMERDATA_H
