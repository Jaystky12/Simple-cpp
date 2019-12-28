#include <iostream>
#include "stack.h"

bool Stack::isEmpty(){
    bool is;
    if (!elements.empty()){
        is = false;
    }
    else{
        is = true;
    }
    return is;
}

int Stack::peek (){
    return elements.back();
}

int Stack::pop (){
    elements.pop_back();
    return 0;
}

void Stack::push (int x){
    elements.push_back(x);

}

void Stack::remaining(){
    int z;
    if (elements.empty())
        std::cout << "The stack is empty";

    for (int z : elements)
        std::cout << z << " ";
}