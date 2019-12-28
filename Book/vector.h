#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>
#include <string>
 
//our custom vector class can store variables of type teacher and can dynamically enlarge and shrink
class vector {
    private:
        int size1 = 0;
        Teacher *elements;
        friend class Teacher;
    public:
        vector(); //constructor
        ~vector(); //deconstructor
        Teacher& at(int i); //return element at index i
        void push_back (Teacher ta); //simple push operation which increases size of vector
        int size(); //return the size
        void remove (int i); //remove element from the vector and reduce it size
        void clear(); //clear the vector, vector must be empty and size equal 0
        void sort(); //simple sorting algorithm 
};

#endif // VECTOR_H_INCLUDED
