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
    //convert each char into an integer
    int numericValue = stringOfDigits[0];

    //variable for multiplication of numeric value times the base raised to the proper power
    int numericValueTimesBase = 0;
    
    //variable for sum of numeric value times the base
    int sumOfValueTimesBase = 0;
    
    //loop to go through characters of string
    for (int i = 0 ; i < stringOfDigits.length() ; i++) {
        //if statement that checks if base is 10. If so, convert each character to integer
        if (base == 10) {
            numericValue = (stringOfDigits[i]) - '0';
            std::cout << "Numeric value: " << numericValue << std::endl;
            
        } else if (base == 2) {
            numericValue = (stringOfDigits[i]) - '0';
            std::cout << "Numeric value: " << numericValue << std::endl;
        } else if (base == 16) {
            numericValue = (stringOfDigits[i] - 'a' + 10);
            std::cout << "Numeric value: " << numericValue << std::endl;
        }
        
        //take numeric value generated and multiply it by the base raised to the appropriate power
        numericValueTimesBase = numericValue * pow(base, (stringOfDigits.length() - 1) - i);
        
        //sum all the values of the numeric value times base variable to get the total sum
        sumOfValueTimesBase += numericValueTimesBase;
        
        std::cout << "Sum: " << sumOfValueTimesBase << std::endl;
    }
    
    
    
    return sumOfValueTimesBase;
}


//if (stringOfDigits[i] >= 'a' && stringOfDigits[i] <= 'z') {
