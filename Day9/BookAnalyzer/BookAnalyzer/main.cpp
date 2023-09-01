//
//  main.cpp
//  BookAnalyzer
//
//  Created by Josh Barton on 8/31/23.
//

#include <iostream>
#include <fstream> //file stream
#include <cstdlib> // For exit() function

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //create stream variable that will input the book
    std::ifstream bookStream("frakenstein.txt");
    
    //create a string varible that the stream will go into
    std::string bookText;
    
    //stream in the book to the variable
    bookStream >> bookText;
    
    //check to see if book stream opened properly
//    std::string bookText = (“texasFootball.txt”);
//    std::ifstream bookStream( bookText );
//
//    if( bookStream.fail() ) {
//        std::cout << “Failed to open file: “ << bookText << “.\n”;
//        exit( 1 ); // Kill the program and exit with a return value of 1
//
//    }
    
    return 0;
}
