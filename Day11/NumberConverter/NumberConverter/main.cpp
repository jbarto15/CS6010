//
//  main.cpp
//  NumberConverter
//
//  Created by Josh Barton on 9/6/23.
//

#include <iostream>
#include "numberConverter.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Please enter a string:\n";
    
    //variable to hold user input
    std::string userInput;
    
    //get a string from the user
    std::cin >> userInput;
    
    //ask for a base
    std::cout << "Please enter a base:\n";
    
    //variable to hold user input
    int base;
    
    //get a base from the user
    std::cin >> base;
    
    //call string to integer function
    std::cout << "Sum: " << stringToInt(userInput, base) << std::endl;
    
    //call decimal to string function
    std::cout << "Decimal as String: " << toDecimalAsString(stringToInt(userInput, base)) << std::endl;
    
    //call binary to string function
    std::cout << "Binary as String: " << toBinaryAsString(stringToInt(userInput, base)) << std::endl;
    
    //call hex to string function
    std::cout << "Hex as String: " << toHexAsString(stringToInt(userInput, base)) << std::endl;
    
    
    
    return 0;
}
