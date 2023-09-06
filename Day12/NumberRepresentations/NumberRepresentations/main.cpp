//
//  main.cpp
//  NumberRepresentations
//
//  Created by Josh Barton on 9/6/23.
//

#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cmath>

#include "numberFunctions.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    //print out the size of an integer
    int integer;
    std::cout << sizeof(integer) << std::endl;
    
    //print out the size of a char
    char character;
    std::cout << sizeof(character) << std::endl;
    
    //print out the size of a bool
    bool boolean;
    std::cout << sizeof(boolean) << std::endl;
    
    //print out the size of a string
    std::string string;
    std::cout << sizeof(string) << std::endl;
    
    //print out the size of a float
    float floatSize;
    std::cout << sizeof(floatSize) << std::endl;
    
    //print out the size of a double
    double doubleSize;
    std::cout << sizeof(doubleSize) << std::endl;
    
    
    int a[] = { 7, 2, -56, 32, 1, 7, -2, 7 };
    std::cout << "size: " << sizeof( a ) << "\n";
    
    //print out the size of an array
    int b[] = { 7, 2, -56, 32};
    std::cout << "size: " << sizeof( b ) << "\n";
    
    //print out the size of an array
    int c[] = { 7, 2};
    std::cout << "size: " << sizeof( c ) << "\n";
    
     
    uint8_t min1 = 0x00;
    std::cout << "Min: " << +min1 << std::endl;
    
    uint8_t max1 = 0xFF;
    std::cout << "Max: " << +max1 << std::endl;
    
    uint16_t min2 = 0x00;
    std::cout << "Min: " << +min2 << std::endl;
    
    uint16_t max2 = 0xFFFF;
    std::cout << "Max: " << +max2 << std::endl;
    
    uint64_t min3 = 0x00;
    std::cout << "Min: " << +min3 << std::endl;
    
    uint64_t max3 = 0xFFFFFFFFFFFFFFFF;
    std::cout << "Max: " << +max3 << std::endl;
    
    
    
    int8_t min8 = 0x80 - 1;
    std::cout << "8Min: " << +min8 << std::endl;

    int8_t max8 = 0x7F - 1;
    std::cout << "8Max: " << +max8 << std::endl;
    
    int16_t min16 = 0x8000 - 1;
    std::cout << "16Min: " << +min16 << std::endl;
    
    int16_t max16 = 0x7FFF - 1;
    std::cout << "16Max: " << +max16 << std::endl;
    
    int64_t min64 = 0x8000000000000000 - 1;
    std::cout << "64Min: " << +min64 << std::endl;
    
    int64_t max64 = 0x7FFFFFFFFFFFFFFF - 1;
    std::cout << "Max: " << +max64 << std::endl;
    

    
    //compute .1 + .2 and store the result in a variable (of type double) and print it.
    double compute = .1 + .2;
    std::cout << "Result: " << compute << std::endl;
     
     //Use assert to verify that your variable is equal to .3 and run your program
    //assert(compute == .3);
     //Stare confused at the result for a couple minutes.
     //How is that possible?
     //print the value of your variable as well as 0.3 with more accuracy by doing the following:

     

     //in main

     std::cout << std::setprecision(18); //print numbers to 18

     //Write a function approxEquals that takes 3 doubles: the two numbers you want to compare with ==, and a tolerance that specifies how close they must be to be considered equal.
    double one = .1;
    double two = .2;
    double three = .3;
    
     //Verify that your function works for the example above involving .1 + .2 and .3
    
    std::cout << approxEquals(one, two, three);
    
    inputFileCharacterByCharacter();
    
    
    return 0;
}
