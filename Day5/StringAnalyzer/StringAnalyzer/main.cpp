//
//  main.cpp
//  StringAnalyzer
//
//  Created by Josh Barton on 8/25/23.
//

#include <iostream>
#include <ctype.h>
#include <string>
#include "LetterHelpers.hpp"
#include "WordHelpers.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    /*create a do while loop to ask the user to enter sentences until they type the word done*/
        
        //Enter a string containing one or more sentences:
        std::cout << "Enter one or more sentences:\n";
        //std::string s = "how are you doing";
        //std::cout<< numWords(s);
        
        //tell the user what to do when finished
        std::cout << "Enter 'done' when finished\n";
        
        //Here is sentence number one. Here is sentence number two!
        
        std::string input;
        std::getline( std::cin, input);
        // After the user types something and presses enter, the variable "input" will contain the line of text they typed.
            
            //print number of words
            std::cout << "Number of Words: ";
        std::cout << numWords(input) << std::endl;
        
        //print number of sentences
        std::cout << "Number of Sentences: ";
        std::cout << numSentences(input) << std::endl;
        
        //print number of vowels
        std::cout << "Number of Vowels: ";
        std::cout << numVowels(input) << std::endl;
        
        //print number of consonants
        std::cout << "Number of Consonants: ";
        std::cout << numConsonants(input) << std::endl;
        
        //print average word length
        std::cout << "Reading level (average word length): ";
        std::cout << averageWordLength(input) << std::endl;
        
        //print average number of vowels per word
        std::cout << "Average vowels per word: ";
        std::cout << averageVowelsPerWord(input) << std::endl;
        
    
    return 0;
}


