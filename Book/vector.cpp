#include <iostream>
#include <new>
#include <algorithm>
#include "vector.h"

vector::vector (){
    size1 = 0;
    elements = new Teacher[0];
}

vector::~vector (){
    delete [] elements;
}

Teacher& vector::at(int i){
    return elements[i];
}

void vector::push_back (Teacher ta){
    size1++;
    Teacher* temp = new Teacher [size1];
    std::copy (elements, (elements + (size1 - 1)), temp);
    delete [] elements;
    elements = temp;
    elements [size1 - 1] = ta;
}

int vector::size(){
    return size1;
}

void vector::remove(int i){
    int a = size1 - 1;
    if (elements[i].getname() != elements[a].getname()){
        std::swap(elements[i],elements[a]);
    }
    size1--;
    a = size1;
    Teacher* temp = new Teacher [size1];
    std::copy_n (elements, a, temp);
    delete [] elements;
    elements = temp;
}

void vector::clear(){
    size1 = 0;
    Teacher *temp = new Teacher[0];
    delete [] elements;
    elements = temp;
}

void vector::sort(){
    int i = 0;
    bool sorting = false;
    if(size1 > 1){
        for (i = 0; i < size1; i++){
            while (!sorting){
                for (i = 0; i < size1 - 1; i++){

                    std::string temp_room1 = elements[i].getroom();
                    std::string temp_room2 = elements[i + 1].getroom();
                    std::string temp_name1 = elements[i].getname();
                    std::string temp_name2 = elements[i + 1].getname();

                    if (temp_room2.at(0) < temp_room1.at(0)){
                        std::swap (elements[i], elements[i + 1]);
                        sorting = true;
                    }
                    else if (temp_room2.at(0) == temp_room1.at(0) || temp_room2.at(1) < temp_room1.at(1)){
                        std::swap (elements[i], elements[i + 1]);
                        sorting = true;
                    }
                    else if (temp_room2.at(0) == temp_room1.at(0) || temp_room2.at(1) == temp_room1.at(1) ||
                             temp_room2.at(2) < temp_room1.at(2)){
                        std::swap (elements[i], elements[i + 1]);
                        sorting = true;
                    }
                    else if (temp_room2.at(0) == temp_room1.at(0) || temp_room2.at(1) == temp_room1.at(1) ||
                             temp_room2.at(2) == temp_room1.at(2) || temp_room2.at(3) < temp_room1.at(3)){
                        std::swap (elements[i], elements[i + 1]);
                        sorting = true;
                    }
                    else if (temp_room1.compare(temp_room2) == 0 || temp_name1.at(0) < temp_name2.at(0)){
                        std::swap (elements[i], elements[i + 1]);
                        sorting = true;
                    }
                    else if (temp_room1.compare(temp_room2) == 0 || temp_name1.at(0) == temp_name2.at(0) ||
                             temp_name1.at(1) < temp_name2.at(1)){
                        std::swap (elements[i], elements[i + 1]);
                        sorting = true;
                    }
                    else if (temp_room1.compare(temp_room2) == 0 || temp_name1.at(0) == temp_name2.at(0) ||
                             temp_name1.at(1) == temp_name2.at(1) || temp_name1.at(2) < temp_name2.at(2)){
                        std::swap (elements[i], elements[i + 1]);
                        sorting = true;
                    }
                }
            }
        }
    }
}
