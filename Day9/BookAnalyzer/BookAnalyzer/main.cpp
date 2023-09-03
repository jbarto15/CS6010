//
//  main.cpp
//  BookAnalyzer
//
//  Created by Josh Barton on 8/31/23.
//

#include <iostream>
#include <fstream> //file stream
#include <cstdlib> // For exit() function
#include <vector>
#include "bookAnalyzer.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //create stream variable that will input the book
    std::ifstream inputBookStream;//("frankenstein.txt");
    inputBookStream.open("/Users/joshbarton/Downloads/frankenstein.txt");

    //check to see if book stream opened properly
    if( inputBookStream.fail() ) {
        std::cout << "Failed to open file.\n";
        // Kill the program and exit with a return value of 1
        exit(1);

    }
    
    //create a string varible that each word of the file text will be read into
    std::string word;

    //stream in the book to the variable
    inputBookStream >> word;
    
    //create a vector to store the words from the book
    std::vector<std::string> allWordsOfBook;

    //use a while loop to stream in the entire book
    while (inputBookStream >> word) {
        //std::cout << "Read in: " << word << "\n";
        allWordsOfBook.push_back(word);
    }
    
    //print out Book Title
    std::cout << findBookTitle(allWordsOfBook) << std::endl;
    
    //print out Book Author
    std::cout << findBookAuthor(allWordsOfBook) << std::endl;
    
    //print out number of words in the file
    std::cout << "Number of words: " << calculateTotalNumOfWordsInFile(allWordsOfBook) << std::endl;
    
    //print out number of characters in the file
    std::cout << "Number of characters: " << calculateTotalNumOfCharactersInFile(allWordsOfBook) << std::endl;
    
    //print out the shortest word in the file
    std::cout << "The shortest word is " << findShortestWordInBook(allWordsOfBook) << std::endl;
    
    return 0;
}
