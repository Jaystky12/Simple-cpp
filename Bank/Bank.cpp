#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Account.cpp"

using namespace std;

int main(){

    //variables
    int number_of_lines = 0;
    int x = 0;
    int i = 0;
    double money;
    double checkbalance;
    char operation;
    char type;
    bool user_exist;
    string name;
    string line;
    vector <Account> allAccounts;
    Account acc (name, type);

    //read text file from input stream
    ifstream myfile ("records.txt");
    
    //calculate the number of lines
    while (getline(myfile, line))
        number_of_lines++;


    cout << number_of_lines;
    cout << endl;

    do{
        try{
            cin >> operation >> name;

            //creation of an account
            if (operation == 'c'){
                std::cin >> type;

                user_exist = false;
                for (i = 0; i < allAccounts.size(); i++){
                    if (allAccounts[i].getaccountNames() == name){
                        user_exist = true;
                    }
                }
                if (!user_exist){
                    Account acc (name, type);
                    allAccounts.push_back(acc);
                }
                else if (user_exist){
                    throw runtime_error ("account already exists");
                }
            }
            //transaction on given account
            else if (operation == 't'){
                cin >> money;

                user_exist = false;

                for (i = 0; i < allAccounts.size(); i++){
                    if (allAccounts[i].getaccountNames() == name){
                        user_exist = true;

                        checkbalance = allAccounts[i].balance() + money;

                        if (allAccounts[i].getaccountType() != 'y' && checkbalance < 0){
                            throw runtime_error ("account cannot hold negative balance");
                        }
                        else {
                            allAccounts[i].transactions(money);
                        }
                    }
                }

                if(!user_exist){
                    throw runtime_error ("account does not exist");
                }
            }
            //removal of given account
            else if (operation == 'r'){

                user_exist = false;

                for (i = 0; i < allAccounts.size(); i++){
                    if (allAccounts[i].getaccountNames() == name){

                        user_exist = true;

                        if (allAccounts[i].balance() < 0 ){
                            throw runtime_error ("account hold negative balance");
                        }
                        else {
                            allAccounts.erase(allAccounts.begin()+i);
                        }
                    }
                }
                if(!user_exist){
                    throw runtime_error ("user does not exist");
                }
            }
        }catch (runtime_error& s){
            cerr << "error on line " << x + 1 << " " << s.what() << endl;
        }
        x++;
    }while (x < number_of_lines);

    cout << endl;

    //display the final amount of money each account holds
    for (i = 0; i < allAccounts.size(); i++){
        if (allAccounts[i].balance() < 0){
            cout << allAccounts[i].getaccountNames() << " owes " << -(allAccounts[i].balance()) << endl;
        }
        else{
            cout << allAccounts[i].getaccountNames() << " owns " << allAccounts[i].balance() << endl;
        }
    }

    return 0;
}
