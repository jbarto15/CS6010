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
#include <string>

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


//function to find the shortest word in the book
std::string findShortestWordInBook(std::vector<std::string>& textOfEntireBook) {
    //create variable to store the shortest word
    std::string shortestWordInBook;
    //create a shortest word length variable to compare the shortest word with
    int unsigned long shortestLength = 10;
    
    for (const std::string& word: textOfEntireBook) {
        if (word.length() < shortestLength) {
            shortestWordInBook = word;
            shortestLength = word.length();
        }
    }
    
    return shortestWordInBook;
}


//function to find the longest word in the book
std::string findLongestWordInBook(std::vector<std::string>& textOfEntireBook) {
    //create variable to store the longest word
    std::string longestWordInBook;
    
    //create a longest word length variable to compare the longest word with
    int unsigned long longestLength = 0;
    
    for (const std::string& word: textOfEntireBook) {
        if (word.length() > longestLength) {
            longestWordInBook = word;
            longestLength = word.length();
        }
    }
    
    return longestWordInBook;
}



//function for finding how many times the key word appears
int findHowManyTimesKeyWordAppears(std::string& keyWord, std::vector<std::string>& textOfEntireBook) {
    
    int numOfTimesKeyWordIsInBook = 0;
    
    //use a loop to find the keyword
    for (int i = 0; i < textOfEntireBook.size(); i++) {
        if (keyWord == textOfEntireBook[i]) {
            numOfTimesKeyWordIsInBook += 1;
        }
    }
    
    return numOfTimesKeyWordIsInBook;
}



//function finding the percentage of where the key word occurs
void percentageOfWhereKeyWordOccursInFile(std::string& keyWord, int unsigned long& totalNumOfCharactersInFile, std::vector<char>& charactersOfEntireBook) {
    
    
    //create a vector of characters
    std::vector<char> vectorOfKeyWordCharacters;
    
    //parse the keyWord into characters
    for (char keyWordCharacter: keyWord) {
        vectorOfKeyWordCharacters.push_back(keyWordCharacter);
    }
    
    //variable that will store the position of the first character in the word. Set to -1 because we don't want it storing any character at first
    int positionOfCharacterOfKeyWord = -1;
    
    //variable to store if the character in the book is the same as the one in the key word
    bool keyWordFound = true;
    
    //search for the characters of the key word in all of the characters of the book
    for (int i = 0; i < charactersOfEntireBook.size(); i++) {
        if (charactersOfEntireBook[i] == vectorOfKeyWordCharacters[0]) {
            positionOfCharacterOfKeyWord = i;
            std::cout << "character position: " << positionOfCharacterOfKeyWord << std::endl;
        }
        for (int j = 1; j < vectorOfKeyWordCharacters.size(); j++) {
            if (vectorOfKeyWordCharacters[j] == charactersOfEntireBook[i + j]) {
                keyWordFound = true;
//                std::cout << "at " << positionOfCharacterOfKeyWord / totalNumOfCharactersInFile << "%: " << keyWord << std::endl;
                
            } else {
                keyWordFound = false;
                break;
            }
        }

        while (keyWordFound) {
            std::cout << "at " << positionOfCharacterOfKeyWord / totalNumOfCharactersInFile << "%: " << keyWord << std::endl;
        }
    }
    
//    std::cout << "First character position: " << positionOfFirstCharacerOfKeyWord << std::endl;
    
    
    
}
