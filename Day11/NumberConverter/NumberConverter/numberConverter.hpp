//
//  numberConverter.hpp
//  NumberConverter
//
//  Created by Josh Barton on 9/6/23.
//

#ifndef numberConverter_hpp
#define numberConverter_hpp

#include <stdio.h>
#include <iostream>

//function that will convert a string of digits to an integer
int stringToInt(std::string& stringOfDigits, int base);


//Convert an int to its decimal representation as a string
std::string toDecimalAsString(int number);


//Convert an int to its binary string representation
std::string toBinaryAsString(int number);


//Convert an int to its hexadecimal string representation.
std::string toHexAsString(int number);


#endif /* numberConverter_hpp */
