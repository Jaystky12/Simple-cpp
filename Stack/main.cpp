#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include "stack.cpp"


int main(){
    
    //variables
    int x;
    bool a;
    Stack st;
    std::string command;

    do{
        try{

            //ask user for input and perform operations, otherwise throw error if command unknown 
            std::cout << "> ";
            std::cin >> command;

            if (command.compare ("push")==0){
                std::cin >> x;
                st.push (x);
            }
            else if (command == "pop"){
                a = st.isEmpty();
                switch (a){
                    case true:
                        throw std::runtime_error ("stack is empty");
                        break;

                    case false:
                        std::cout << st.peek() << std::endl;
                        st.pop();
                        break;
                }
            }
            else if (command == "peek"){
                a = st.isEmpty();
                switch (a){
                    case true:
                        throw std::runtime_error ("stack is empty");
                        break;

                    case false:
                        std::cout << st.peek() << std::endl;
                        break;
                }
            }
            else if (command != "peek", command != "pop", command != "push", command != "end"){
                throw std::runtime_error ("invalid command");
            }
        }catch (std::runtime_error& e){
            std::cerr << "error: " << e.what() <<std::endl;
        }
    }while (command != "end");

    st.remaining();
    std::cout << std::endl;
return 0;
}
