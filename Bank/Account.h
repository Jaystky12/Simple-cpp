#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

//simple account class which store balance, type and name of the owner
class Account{
    private:
        double accountBalance;
        char accountType;
        string accountName;
    public:
        Account (string name, char type); //constructor
        double balance(); //return the balance of the account
        double transactions ( double money); //perform transaction 
        string getaccountNames(); //get name of the account
        char getaccountType(); //return type of account, either credit or debit
};

#endif // ACCOUNT_H_INCLUDED
