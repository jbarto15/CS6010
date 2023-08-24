//
//  main.cpp
//  RomanNumerals
//
//  Created by Josh Barton on 8/24/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //creation of variables
    int userNumber;
    
    //print a statement that asks the user for a number and then store that number in the variable userNumber
    std::cout << "Please enter a whole number: \n";
    std::cin >> userNumber;
    
    //print out the string Roman numeral version:
    std::cout << "Roman numeral version: \n";
    
    /*creating while loops to first check if the users number is greater than or equal to the first Roman numeral token but also if it's greater than the next roman numeral token. If so, I want it to subtract the amount of the roman numeral token from the users number and save that as userNumber so we keep track of the new number. Then print the corresponding letter that goes with each token. */
    while (userNumber >= 1000 && userNumber > 900) {
        userNumber = userNumber - 1000;
        std::cout<< "M";
    }
    while (userNumber >= 900 && userNumber > 500) {
        userNumber -= 900;
        std::cout<< "CM";
    }
    while (userNumber >= 500 && userNumber > 400) {
        userNumber -= 500;
        std::cout<< "D";
    }
    while (userNumber >= 400 && userNumber > 100) {
        userNumber -= 400;
        std::cout<< "CD";
    }
    while (userNumber >= 100 && userNumber > 90) {
        userNumber -= 100;
        std::cout<< "C";
    }
    while (userNumber >= 90 && userNumber > 50) {
        userNumber -= 90;
        std::cout<< "XC";
    }
    while (userNumber >= 50 && userNumber > 40) {
        userNumber -= 50;
        std::cout<< "L";
    }
    while (userNumber >= 40 && userNumber > 10) {
        userNumber -= 40;
        std::cout<< "XL";
    }
    while (userNumber >= 10 && userNumber > 9) {
        userNumber -= 10;
        std::cout<< "X";
    }
    while (userNumber >= 9 && userNumber > 5) {
        userNumber -= 9;
        std::cout<< "IX";
    }
    while (userNumber >= 5 && userNumber > 4) {
        userNumber -= 5;
        std::cout<< "V";
    }
    while (userNumber >= 4 && userNumber > 1) {
        userNumber -= 4;
        std::cout<< "IV";
    }
    while (userNumber >= 1 && userNumber > 0) {
        userNumber -= 1;
        std::cout<< "I";
    }
    
    //print new line at the end of the roman numeral version so it looks better.
    std::cout << "\n";
    
    return 0;
}
