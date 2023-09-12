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
    
    //variable to store the numeric value of a character
    int numericValue = stringOfDigits[0];

    //variable for multiplication of numeric value times the base raised to the proper power
    int numericValueTimesBase = 0;
    
    //variable for sum of numeric value times the base
    int sumOfValueTimesBase = 0;
    
    //loop to go through characters of string
    for (int i = 0 ; i < stringOfDigits.length() ; i++) {
        //if statement that checks if base is 10. If so, convert each character to integer
        if (base == 10) {
            if (stringOfDigits[i] == '-') {
                continue;
            }
            numericValue = (stringOfDigits[i]) - '0';
        } else if (base == 2) {
            numericValue = (stringOfDigits[i]) - '0';
        } else if (base == 16) {
            if (stringOfDigits[i] - '0' >= 0 && stringOfDigits[i] - '0' < 10) {
                numericValue = (stringOfDigits[i]) - '0';
            }
            if (stringOfDigits[i] >= 'a' && stringOfDigits[i] <= 'z') {
                numericValue = (stringOfDigits[i] - 'a' + 10);
            }
        }
        
        //if statement to handle if decimal number is negative for base 10
        if (base == 10 && stringOfDigits[0] == '-') {
            numericValue *= -1;
        }
        
        //if statement to handle if binary number is negative for base 2
        if (base == 2 && stringOfDigits[0] == '-') {
            numericValue *= -1;
        }
        
        //if statement to handle if hex number is negative for base 16
        if (base == 16 && stringOfDigits[0] == '-') {
            numericValue *= -1;
        }
        
        
        
        //take numeric value generated and multiply it by the base raised to the appropriate power
        numericValueTimesBase = numericValue * pow(base, (stringOfDigits.length() - 1) - i);
        
        //sum all the values of the numeric value times base variable to get the total sum
        sumOfValueTimesBase += numericValueTimesBase;
    }
    //print out the sum
    //std::cout << "Sum: " << sumOfValueTimesBase << std::endl;
    
    return sumOfValueTimesBase;
}


//Part 2

//Convert an int to its decimal representation as a string
std::string toDecimalAsString(int number) {
    //condition that changes the number to positive
    if (number < 0) {
        number *= -1;
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
    
    return decimalToString;
}

//Convert an int to its binary string representation
std::string toBinaryAsString(int number) {
    //condition that changes the number to positive
    if (number < 0) {
        number *= -1;
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
    
    return binaryAsString;
}


//Convert an int to its hexadecimal string representation.
std::string toHexAsString(int number) {
    //condition that changes the number to positive
    if (number < 0) {
        number *= -1;
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
        } else if (remainder >= 'a' && remainder <= 'z') {
            character = remainder + 'a' - 10;
            integersOfNumber.push_back(character);
        }
    }
    
    //for loop that reorders the vector into the correct string
    for (int i = integersOfNumber.size() - 1; i >= 0; i--) {
        hexAsString += integersOfNumber[i];
    }
    
    return hexAsString;
}


//Write tests for your functions to demonstrate that they work correctly. Note that a good test is that those operations are inverses: stringToInt( intToHexadecimal( anything ), 16 ) == anything for any valid input.
