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
    inputBookStream.open("/Users/joshbarton/Desktop/CS6010/Day9/testBookAnalyzer.txt");

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
    
    
    //input the characters of the book
    //variable to keep track of total number of characters in file
    int unsigned long totalNumOfCharactersInFile = 0;
    
    //create stream variable that will input the characters of the book
    std::ifstream inputBookStreamByCharacter;//("frankenstein.txt");
    inputBookStreamByCharacter.open("/Users/joshbarton/Desktop/CS6010/Day9/testBookAnalyzer.txt");
    
    //check to see if book stream opened properly
    if( inputBookStreamByCharacter.fail() ) {
        std::cout << "Failed to open file.\n";
        // Kill the program and exit with a return value of 1
        exit(1);
    }
    //create a char varible that each character of the file text will be read into
    char character;
    
    //stream in the book to the variable
    inputBookStreamByCharacter >> character;
        
    //create a vector to store the characters from the book
    std::vector<char> allCharactersOfBook;
        
    //use a while loop to stream in the entire book
    while (inputBookStreamByCharacter >> character) {
        if (character != ' ' && character != '\n') {
            //std::cout << "read in: " << character << std::endl;
            totalNumOfCharactersInFile++;
            allCharactersOfBook.push_back(character);
        }
        
        }
    
//    //print out all characters in the book vector
//    for (int i = 0; i < allCharactersOfBook.size(); i++) {
//        std::cout << allCharactersOfBook[i] << std::endl;
//    }
    
    //print out Book Title
    std::cout << findBookTitle(allWordsOfBook) << std::endl;
    
    //print out Book Author
    std::cout << findBookAuthor(allWordsOfBook) << std::endl;
    
    //print out number of words in the file
    std::cout << "Number of words: " << calculateTotalNumOfWordsInFile(allWordsOfBook) << std::endl;
    
    //print out number of characters in the file
    std::cout << "Number of characters: " << totalNumOfCharactersInFile << std::endl;
    
    //print out the shortest word in the file and the longest word
    std::cout << "The shortest word is: " << findShortestWordInBook(allWordsOfBook) << " and the longest word is: " << findLongestWordInBook(allWordsOfBook) << std::endl;
    
    //ask fo a key word
    std::cout << "Please enter a word to search for:" << std::endl;
    
    //create a keyword variable that will store the input from the user
    std::string keyWordFromUser;
    //get the keyword from the user
    std::cin >> keyWordFromUser;
    
    //print out the number of times the word appears in the book
    std::cout << "The word " << keyWordFromUser << " appears " << findHowManyTimesKeyWordAppears(keyWordFromUser, allWordsOfBook) << " times:" << std::endl;
    
    //print out the percentage of where the word occurs
    percentageOfWhereKeyWordOccursInFile(keyWordFromUser, totalNumOfCharactersInFile, allCharactersOfBook);
    
    
    return 0;
}
