#include <iostream>
#include "intRow.cpp"

using namespace std;

int main (){

    //variables
    int size;
    int index;
    int i = 0;
    int value;
    int n =1;
    IntRow row;

    cout << "Please enter the number of iterations: ";
    cin >> size;

    cout << "Which term would you like to know: ";
    cin >> index;

    //calculate the sequence and push it to row of intagers
    for (i = 0; i < size; i++){
        value = (2 * n) - 3;
        row.push_back (value);
        n++;
    }

    index--;
    cout << "The value of term " << index + 1 << " is " << row.at(index) << endl;
    cout << "The entire sequence up to " << row.length() << " terms is: ";
    index = 0;

    for (i = 1; i <= row.length(); i++){
        cout << row.at(index) << " ";
        index++;
    }

    cout << endl;
    return 0;
}
