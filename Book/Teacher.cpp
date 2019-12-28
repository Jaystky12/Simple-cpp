#include <iostream>
#include <string>
#include "Teacher.h"

Teacher::Teacher(){
    Tname = "aaaa";
    Troom = "aaaa";
}
std::string Teacher::getname(){
    return Tname;
}
std::string Teacher::getroom(){
    return Troom;
}
std::string Teacher::moveroom (std::string room){
    Troom = room;
    return Troom;
}
std::string Teacher::movename (std::string name){
    Tname = name;
    return Tname;
}
