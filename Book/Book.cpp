#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include "Teacher.cpp"
#include "vector.cpp"

int main (){
    //variables which will be used during the execution of the code
    //type of operation to be performed
    std::string operation;
    //name of the teacher
    std::string name = "aaaa";
    //room in which the teacher is
    std::string room = "x000";
    //counter
    int i = 0;
    //custom vector used to store the teachers and data
    vector vec;
    //simple boolean used to check if the user exists or not in our database
    bool user;

    do{
        try{
            std::cout << "> ";
            std::cin >> operation;
            //adding teacher to the database
            if (operation == "add"){
                std::cin >> name >>  room;
                //room length must be 4, otherwise throw error
                if (room.length() != 4){
                    throw std::runtime_error ("invalid room");
                }
                //and it must start with a letter, otherwise throw error
                else if(isdigit(room.at(0))){
                    throw std::runtime_error ("room number must start with a letter");
                }
                //check if the teacher exists in the database
                user = false;
                for (i = 0; i < vec.size(); i++){
                    if (vec.at(i).getname() == name){
                        user = true;
                    }
                }
                if (user){
                    throw std::runtime_error ("You cannot add person with already used name");
                }
                //otherwise add it to the vector
                else if(!user){
                    Teacher ta;
                    ta.movename(name);
                    ta.moveroom(room);
                    vec.push_back (ta);
                }
            }
            //move operation, move teacher from one room to another
            else if (operation == "move"){
                std::cin >> name >> room;
                if (room.length() != 4){
                    throw std::runtime_error ("invalid room");
                }
                else if(isdigit(room.at(0))){
                    throw std::runtime_error ("room number must start with a letter");
                }
                //check if the teacher exists in the database
                user = false;
                for (i = 0; i < vec.size(); i++){
                    if (vec.at(i).getname() == name){
                        user = true;
                    }
                }
                //if not throw error
                if (!user){
                    throw std::runtime_error ("there is no such person in database");
                }
                //else change the room
                else if (user){
                    for (i = 0; i < vec.size(); i++){
                        if (vec.at(i).getname() == name){
                            vec.at(i).moveroom(room);
                            std::cout << vec.at(i).getroom() << std::endl;
                        }
                    }
                }
            }
            //operation of finding given teacher in the database
            else if (operation == "find"){
                std::cin >> name;
                //check if exists in database
                user = false;
                for (i = 0; i < vec.size(); i++){
                    if (vec.at(i).getname() == name){
                        user = true;
                    }
                }
                if (!user){
                    throw std::runtime_error ("there is no such person in database");
                }
                else if (user){
                    for (i = 0; i < vec.size(); i++){
                        if (vec.at(i).getname() == name){
                            std::cout << vec.at(i).getname() << " is in room " << vec.at(i).getroom() << std::endl;
                        }
                    }
                }
            }
            //operation of removal of the teacher
            else if (operation == "remove"){
                std::cin >> name;

                user = false;
                for (i = 0; i < vec.size(); i++){
                    if (vec.at(i).getname() == name){
                        user = true;
                    }
                }
                if (!user){
                    throw std::runtime_error ("there is no such person in database");
                }
                else if (user){
                    for (i = 0; i < vec.size(); i++){
                        if (vec.at(i).getname() == name){
                            vec.remove(i);
                        }
                    }
                }
            }
            //clear our database
            else if (operation == "clear"){
                if (vec.size() == 0){
                    throw std::runtime_error ("list is  empty");
                }
                else{
                    vec.clear();
                }
            }
            else if (operation == "list"){
                vec.sort();
                for (i = 0; i < vec.size(); i++){
                    std::cout << vec.at(i).getname() << " is in room " << vec.at(i).getroom() << std::endl;
                }
            }
            else{
                if(operation != "exit")
                    throw std::runtime_error ("invalid operation");
            }
        }catch (std::runtime_error& e){
            std::cerr << "error: " << e.what() <<std::endl;
        }
    }while (operation != "exit");
    return 0;
}
