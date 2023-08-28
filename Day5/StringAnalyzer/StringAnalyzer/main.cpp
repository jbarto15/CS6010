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
    
    //Enter a string containing one or more sentences:
    std::cout << "Enter a string containing one or more sentences:\n";
    //std::string s = "how are you doing";
    //std::cout<< numWords(s);
    
    //Here is sentence number one. Here is sentence number two!
    //Analysis:
     //Number of words: 10
     //Number of sentences: 2
     //Number of vowels: 19
     //Number of consonants: 27
     //Reading level (average word length): 4.6
     //Average vowels per word: 1.9
    
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

//In this assignment you will write a tool that analyzes sentences and reports various statistics about them. There will be a lot of common computation among some of the analyses performed, so you will need to write helper functions to reuse common code.

//Your program should repeatedly ask the user to input a string, then use the below functions to print various statistics about it. Assume each input string contains one or more sentences terminated with proper grammar (ends with '.', '?', or '!'). Assume the string only contains letters, spaces, commas, and the mentioned sentence terminators. Your program should terminate if the user types in "done".

//Important: Use the C++ function std::getline to read an entire string at once. Using cin >> ... will not work, because its default behavior is to stop on the first space character. The below code snippet illustrates how to use getline.
