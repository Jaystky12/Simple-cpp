#ifndef INTROW_H_INCLUDED
#define INTROW_H_INCLUDED
#include <iostream>

using namespace std;

class IntRow {
    private:
        int *elements;
        int size = 0;

    public:
        IntRow(); // constructor
        ~IntRow(); // destructor
        int at(int index); // returns the element at position index
        void push_back (int value); // adds value to this IntRow
        int length(); // returns the amount of elements in this IntRow
};


#endif // INTROW_H_INCLUDED
