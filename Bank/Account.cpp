#include <iostream>
#include <string>
#include <vector>
#include "Account.h"


Account::Account (string name, char type)
        : accountName ("aaaa"),
        accountType  ('g'),
        accountBalance (0)
        {
            accountName = name;
            accountType = type;
            accountBalance = 0;
}
double Account::transactions (double money){
    accountBalance = accountBalance + money;
    return accountBalance;
}
double Account::balance (){
    return accountBalance;
}
string Account::getaccountNames(){
    return accountName;
}
char Account::getaccountType(){
    return accountType;
}
