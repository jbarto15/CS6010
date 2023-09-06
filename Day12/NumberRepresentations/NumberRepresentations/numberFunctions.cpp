//
//  numberFunctions.cpp
//  NumberRepresentations
//
//  Created by Josh Barton on 9/6/23.
//

#include "numberFunctions.hpp"
#include <cmath>
#include <fstream>
#include <iostream>

bool approxEquals( double a, double b, double tolerance ) {
    return (std::abs(a + b) < tolerance);
}


//input file character by character
void inputFileCharacterByCharacter() {
    //stream in file
    std::ifstream unicode("/Users/joshbarton/Downloads/UTF-8-demo.txt");
    
    //create variable to store each character
    char c;
    
    //create variable to store number of ascii characters
    int numOfAsciiCharacters = 0;
    
    //create variable to store number of unicode characters
    int numOfUnicodeCharacters = 0;
    
    
    while( unicode >> c ){
      // Print c on its own line.
        std::cout << "Character: " << c << std::endl;
        if (c >= 0 && c < 127) {
            numOfAsciiCharacters ++;
        }
        else {
            numOfUnicodeCharacters++;
        }
    }
    //print out num of ascii
    std::cout << "Number of Ascii: " << numOfAsciiCharacters << std::endl;
    
    //print out num of unicode
    std::cout << "Number of Unicode: " << numOfUnicodeCharacters << std::endl;
}
