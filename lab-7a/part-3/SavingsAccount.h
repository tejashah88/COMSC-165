#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
    private:
        int dollars;
        int cents;
        void normalizeValues();

    public:
        void open(int, int);
        void deposit(int, int);
        void withdraw(int, int);
        void showBalance();
};

#endif // SAVINGSACCOUNT_H
