//
//  numberConverter.cpp
//  NumberConverter
//
//  Created by Josh Barton on 9/6/23.
//

#include "numberConverter.hpp"
#include <cctype>
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>

//function that will convert a string of digits to an integer
int stringToInt(std::string& stringOfDigits, int base) {
    //convert the string to lowercase
    std::transform(stringOfDigits.begin(), stringOfDigits.end(), stringOfDigits.begin(), ::tolower);
    
    //variable for sum of numeric value times the base
    int sumOfValueTimesBase = 0;
    
    //boolean flag variable that will help us with negative inputs
    bool isNegative = false;
    
    //check if the string has a negative sign at the beginning
    if (stringOfDigits[0] == '-') {
        isNegative = true;
        //remove the negative sign from the string
        stringOfDigits = stringOfDigits.substr(1);
    }
    
    //loop to go through characters of string
    for (int i = 0 ; i < stringOfDigits.length() ; i++) {
        //variable to store the numeric value of a character
        int numericValue = 0;

        //variable for multiplication of numeric value times the base raised to the proper power
        int numericValueTimesBase = 0;
        
        //if statement that checks if base is 10. If so, convert each character to integer
        if (base == 10) {
                numericValue = (stringOfDigits[i]) - '0';
        } else if (base == 2) {
                numericValue = (stringOfDigits[i]) - '0';
        } else if (base == 16) {
                if (stringOfDigits[i] >= '0' && stringOfDigits[i] <= '9') {
                    numericValue = (stringOfDigits[i]) - '0';
                } else if (stringOfDigits[i] >= 'a' && stringOfDigits[i] <= 'f') {
                    numericValue = (stringOfDigits[i] - 'a' + 10);
                }
            }
            
            //take numeric value generated and multiply it by the base raised to the appropriate power
            numericValueTimesBase = numericValue * pow(base, (stringOfDigits.length() - 1) - i);
            
            //sum all the values of the numeric value times base variable to get the total sum
            sumOfValueTimesBase += numericValueTimesBase;
        }
    //if number is negative, make the sum negative
    if (isNegative) {
        sumOfValueTimesBase = -sumOfValueTimesBase;
    }
    
    return sumOfValueTimesBase;
}


//Part 2

//Convert an int to its decimal representation as a string
std::string toDecimalAsString(int number) {
    //way to check against negative input integers
        bool isNegative = number < 0;
        if (isNegative) {
            number = -number;
        }
    //variable that will return the string result
    std::string decimalToString;
    
    //vector of characters variable
    std::vector<char> integersOfNumber;
    
    //while loop that goes through the number divided by 10 until the number is no longer greater than zero
    while (number > 0) {
        int remainder = number % 10;
        number = number / 10;
        char value = remainder + '0';
        integersOfNumber.push_back(value);
    }
    
    //for loop that reorders the vector into the correct string
    for (int i = integersOfNumber.size() - 1; i >= 0; i--) {
        decimalToString += integersOfNumber[i];
    }
    
    //if the number is negative, add a negative sign
    if (isNegative) {
        decimalToString = '-' + decimalToString;
    }
    
    return decimalToString;
}

//Convert an int to its binary string representation
std::string toBinaryAsString(int number) {
    //way to check against negative input integers
        bool isNegative = number < 0;
        if (isNegative) {
            number = -number;
        }
    
    //string to return the binary as a string
    std::string binaryAsString;
    //vector of characters variable
    std::vector<char> integersOfNumber;
    
    //while loop that goes through the number divided by 10 until the number is no longer greater than zero
    while (number > 0) {
        int remainder = number % 2;
        number = number / 2;
        char value = remainder + '0';
        integersOfNumber.push_back(value);
    }
    
    //for loop that reorders the vector into the correct string
    for (int i = integersOfNumber.size() - 1; i >= 0; i--) {
        binaryAsString += integersOfNumber[i];
    }
    
    //if the number is negative, add a negative sign
    if (isNegative) {
        binaryAsString = '-' + binaryAsString;
    }
    
    return binaryAsString;
}


//Convert an int to its hexadecimal string representation.
std::string toHexAsString(int number) {
    //way to check against negative input integers
        bool isNegative = number < 0;
        if (isNegative) {
            number = -number;
        }
    
    std::string hexAsString;
    
    //vector of characters variable
    std::vector<char> integersOfNumber;
    
    //variable to store the character
    char character;
    
    //while loop that goes through the number divided by 10 until the number is no longer greater than zero
    while (number > 0) {
        int remainder = number % 16;
        number = number / 16;
        if (remainder >= 0 && remainder < 10) {
            character = remainder + '0';
            integersOfNumber.push_back(character);
        } else if (remainder >= 10 && remainder <= 15) {
            character = remainder - 10 + 'A';
            integersOfNumber.push_back(character);
        }
    }
    
    //for loop that reorders the vector into the correct string
    for (int i = integersOfNumber.size() - 1; i >= 0; i--) {
        hexAsString += integersOfNumber[i];
    }
    
    //check if number is negative, if so, add a negative sign
    if (isNegative) {
        hexAsString = '-' + hexAsString;
    }
    
    return hexAsString;
}

//Write tests for your functions to demonstrate that they work correctly. Note that a good test is that those operations are inverses: stringToInt( intToHexadecimal( anything ), 16 ) == anything for any valid input.


