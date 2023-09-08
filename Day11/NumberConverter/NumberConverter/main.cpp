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
    
    
    int number = 78;
    //call string to integer function
    stringToInt(userInput, base);
    
    //call decimal to string function
    toDecimalAsString(number);
    
    int nine = 9;
    
    
    assert(nine + '0' == 57);
    
    
    
    return 0;
}
