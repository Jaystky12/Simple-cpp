#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <time.h>
//Method used to generate and return random sequence of letters based on the user input
std::vector <char> random_generator (int characters, int length){

    //variables 
    int i=0;
    int x;
    std::vector <char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    std::vector <char> random;

    //generating random sequence of letters based on ranom number generator 
    srand (time(NULL));
    for (i = 0; i < length; i++){
        x = rand() % characters;
        random.push_back(alphabet[x]);
    }
    return random;
}

int main (){
    try{
        //variables
        //counters
        int a = 0;
        int b = 0;
        int i = 0;
        //user input
        int length;
        int characters;
        std::string guess;

        //ask the user to determine the number of different characters
        std::cout << "Enter the amount of different characters: ";
        std::cin >> characters;
        if (!std::cin)
            throw std::runtime_error ("number expected");

        else if (characters > 26)
            throw std::runtime_error ("there are only 26 characters aviable");

        //ask the user to enter the length of the sequence of random letters
        std::cout << "Enter the pattern length: ";
        std::cin >> length;
        if (!std::cin)
            throw std::runtime_error ("number expected");

        //get the random letters sequence
        std::vector <char> random_letters = random_generator(characters,length);

        //check the user input and give feedback
        while (a != (length)){
            a = 0;
            std::cout << "Enter your guess: ";
            std::cin >> guess;

            if (!std::cin)
                throw std::runtime_error ("invalid guess");

            else if (guess.length() != (characters))
                throw std::runtime_error ("invalid guess");

            for (i=0; i < length; i++){
                if (guess.at(i)==random_letters[i]){
                    a++;
                }
            }
            std::cout << "You guessed " << a  <<" character correctly" << std::endl;
            b++;
        }

        std::cout << std::endl;
        std::cout << "You guessed the pattern in " << b <<" guesses" << std::endl;
    }catch (std::runtime_error& e){
        std::cerr << "error: " << e.what() << std::endl;
    }
    return 0;
}
