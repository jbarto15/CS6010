//
//  main.cpp
//  StringAnalyzer
//
//  Created by Josh Barton on 8/25/23.
//

#include <iostream>
#include <ctype.h>
#include <cctype>
#include <string>
#include "LetterHelpers.hpp"
#include "WordHelpers.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    /*create a do while loop to ask the user to enter sentences until they type the word done*/
    std:: string input;
    do {
        //Enter a string containing one or more sentences:
        std::cout << "Enter sentence\n";
        //std::string s = "how are you doing";
        //std::cout<< numWords(s);
        
        //tell the user what to do when finished
        std::cout << "Type 'done' when finished:\n";
        
        //Here is sentence number one. Here is sentence number two!
        
        std::getline( std::cin, input);
        // After the user types something and presses enter, the variable "input" will contain the line of text they typed.
    } while (input != "done");
       
        
        //print heading analysis
        std::cout << "\nAnalysis\n";
            //print number of words
            std::cout << "\nNumber of Words: ";
        std::cout << getNumWords(input) << std::endl;
        
        //print number of sentences
        std::cout << "Number of Sentences: ";
        std::cout << getNumSentences(input) << std::endl;
        
        //print number of vowels
        std::cout << "Number of Vowels: ";
        std::cout << getNumVowels(input) << std::endl;
        
        //print number of consonants
        std::cout << "Number of Consonants: ";
        std::cout << getNumConsonants(input) << std::endl;
        
        //print average word length
        std::cout << "Reading level (average word length): ";
        std::cout << calculateAverageWordLength(input) << std::endl;
        
        //print average number of vowels per word
        std::cout << "Average vowels per word: ";
        std::cout << calculateAverageVowelsPerWord(input) << std::endl;
        
    
    return 0;
}


