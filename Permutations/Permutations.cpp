#include <iostream>

using namespace std;
//method uised to calculate permutation of two given numbers
int P (int a, int b){

    //variables
    int p;
    int i = 1;
    int x = (a - (b));
    int factorial1 = 1;
    int factorial2 = 1;

    for (i=1; i <= a; i++){
        factorial1*=i;
    }
    for (i=1; i <= x;i++){
        factorial2*=i;
    }
    p = factorial1  / factorial2;
    return p;
}
//method used to calculate combination of two fiven numbers
int C (int a, int b){

    //variables
    int i = 1;
    int c;
    int factorial2 = 1;
    int permutation;

    permutation = P (a , b);

    for (i=1; i <= b; i++){
        factorial2*=i;
    }
    c = permutation / factorial2;
    return c;
}

int main(){
    try{

        //variables
        int a;
        int b;
        int combination;
        int permutation;
        char decision;

        //ask the user to input two numbers and check if the input is correct, else throw error
        cout << "Enter two integers, a & b: ";
        cin >> a >> b;
        if (!cin){
            throw runtime_error ("number required");
        }
        else if (a < 0){
            throw runtime_error ("operation cannot be performed on negative numbers");
        }
        else if (b < 0){
            throw runtime_error ("operation cannot be performed on negative numbers");
        }
        else if (a < b){
            throw runtime_error ("please enter a >= b >= 0");
        }
        //if everything is fine ask the user what he/she wants, calculate it and display the result
        else{
            cout << "Please enter 'p for permutation or 'c for combination: ";
            cin >> decision;

            if (decision == 'p'){
                permutation = P (a , b);
                cout << "permutation of " << a << " and " << b << " is " << permutation << endl;
            }
            else if (decision == 'c'){
                combination = C (a , b);
                cout << "combination of " << a << " and " << b << " is " << combination << endl;
            }
            else{
                throw runtime_error ("'p' or 'c' expected");
            }
        }
    }catch (runtime_error& e){
        cerr << "error: " << e.what() << endl;
    }
    return 0;
}
