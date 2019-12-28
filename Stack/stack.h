#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#include <vector>

class Stack{
    private:
        std::vector<int> elements;
    public:
        bool isEmpty(); //check if the stack is empty
        int peek(); //print top element on the stack
        int pop(); //print top element on the stack and remove it 
        void push(int x); //push new int on the stacj
        void remaining(); //list all remaining elements on the stack
};

#endif