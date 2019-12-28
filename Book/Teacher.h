#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED
#include <iostream>
#include <string>

//our teacher class consists of name and room in which given teacher is
class Teacher {
    private:
        std::string Tname;
        std::string Troom;
    public:
        Teacher();
        std::string getname(); //return name of the teacher
        std::string getroom(); //return room in which teacher is
        std::string moveroom (std::string room); //change room
        std::string movename (std::string name); //set up name
};

#endif // TEACHER_H_INCLUDED
