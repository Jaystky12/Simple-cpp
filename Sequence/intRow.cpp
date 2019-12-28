#include <iostream>
#include <new>
#include "intRow.h"

using namespace std;

IntRow::IntRow (){
    size;
    elements = new int[size];
}

IntRow::~IntRow () {
    delete[] elements;
}

int IntRow::at(int index){
    return elements[index];
}

void IntRow::push_back (int value){

    size++;
    int* temp = new int[size];
    std::copy (elements, (elements + size), temp);
    delete [] elements;
    elements = temp;
    elements [size - 1] = value;

}

int IntRow::length(){
    return size;
}
