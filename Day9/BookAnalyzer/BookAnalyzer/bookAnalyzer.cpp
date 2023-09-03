//
//  bookAnalyzer.cpp
//  BookAnalyzer
//
//  Created by Josh Barton on 8/31/23.
//

#include "bookAnalyzer.hpp"
#include <iostream>
#include <fstream>
#include <vector>

//function for finding the title index
int findTitleIndex(std::vector<std::string>& textOfEntireBook) {
    for (int i = 0; i < textOfEntireBook.size(); i++) {
        if (textOfEntireBook[i] == "Title:") {
            return i;
        }
    }
    return -1;
}



//function for finding the author index
int findAuthorIndex(std::vector<std::string>& textOfEntireBook) {
    for (int i = 0; i < textOfEntireBook.size(); i++) {
    if (textOfEntireBook[i] == "Author:") {
        return i;
    }
}
return -1;
}

//function for finding the release date index
int findReleaseDateIndex(std::vector<std::string>& textOfEntireBook) {
    for (int i = 0; i < textOfEntireBook.size(); i++) {
    if (textOfEntireBook[i] == "Release") {
        return i;
    }
    }
    return -1;
    }


//function to find the title of the book
std::string findBookTitle(std::vector<std::string>& textOfEntireBook) {
    
    //variable for book title to be stored in
    std::string bookTitle;
    
    //vector variable to store the words after title until author
    std::vector<std::string> vectorOfWordsMakingTheTitle;
    
    //loop through the text starting at title and go until author
    for (int i = findTitleIndex(textOfEntireBook); i < findAuthorIndex(textOfEntireBook); i++) {
        //go through the loop and save the following words into a vector of strings
        vectorOfWordsMakingTheTitle.push_back(textOfEntireBook[i]);
    }
    //access all the words in the vector
    for (int i = 0; i < vectorOfWordsMakingTheTitle.size(); i++) {
        bookTitle += vectorOfWordsMakingTheTitle[i] + " ";
    }
    
    return bookTitle;
}



//function to find the author of the book
std::string findBookAuthor(std::vector<std::string>& textOfEntireBook) {
    //variable for book author to be stored in
    std::string bookAuthor;
    
    //vector variable to store the words after title until author
    std::vector<std::string> vectorOfWordsMakingTheAuthor;
    
    //loop through the text starting at title and go until author
    for (int i = findAuthorIndex(textOfEntireBook); i < findReleaseDateIndex(textOfEntireBook); i++) {
        //go through the loop and save the following words into a vector of strings
        vectorOfWordsMakingTheAuthor.push_back(textOfEntireBook[i]);
    }
    //access all the words in the vector
    for (int i = 0; i < vectorOfWordsMakingTheAuthor.size(); i++) {
        bookAuthor += vectorOfWordsMakingTheAuthor[i] + " ";
    }
    
    return bookAuthor;
}




//function to calculate the total number of words in the file
int unsigned long calculateTotalNumOfWordsInFile(std::vector<std::string>& textOfEntireBook) {
    //create variable that will return the total number of words in file
    int unsigned long totalNumOfWordsInFile = textOfEntireBook.size();
    
    return totalNumOfWordsInFile;
}




//function to calculate the total number of characters in the file
int unsigned long calculateTotalNumOfCharactersInFile(std::vector<std::string>& textOfEntireBook) {
    //create a variable that will return the total number of characters in file
    int unsigned long totalNumOfCharactersInFile = 0;
    
    //create stream variable that will input the book
    std::ifstream inputBookStreamByCharacter;//("frankenstein.txt");
    inputBookStreamByCharacter.open("/Users/joshbarton/Downloads/frankenstein.txt");
    
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
        //std::cout << "Read in: " << word << "\n";
        allCharactersOfBook.push_back(character);
        }
    
    totalNumOfCharactersInFile = allCharactersOfBook.size();

    return totalNumOfCharactersInFile;
}
