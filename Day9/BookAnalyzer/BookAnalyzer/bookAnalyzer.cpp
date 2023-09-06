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



//function to calculate the total number of characters in the file
unsigned long calculateTotalNumOfCharactersInFile(std::vector<std::string>& textOfEntireBook) {
    //create totalNumOfCharacters variable
    unsigned long totalNumOfCharacters = 0;
    
    //for each loop to go through the text of the entire book and put individual characters into the character vector
    for (int i = 0; i < textOfEntireBook.size(); i++) {
            totalNumOfCharacters += textOfEntireBook[i].length();
        }
    
    return totalNumOfCharacters;
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


void giveKeyWordStatisticsAndInformation(std::string& keyWord, unsigned long& totalNumOfCharactersInFile, std::vector<std::string>& textOfEntireBook) {
    //variable for word to the left and word to the right
    std::string wordToLeft;
    std::string wordToRight;
    
    //variable to calculate the percentage
    double percentage = 0;
    
    //use a loop to find the keyword
    for (int i = 0; i < textOfEntireBook.size(); i++) {
        if (keyWord == textOfEntireBook[i] && i > 0 && i < textOfEntireBook.size()) {
            wordToLeft = textOfEntireBook[i - 1];
            wordToRight = textOfEntireBook[i + 1];
            percentage = (50 / calculateTotalNumOfCharactersInFile(textOfEntireBook)) * 100;
            std::cout << " at " << percentage << "%: " << wordToLeft + " " << keyWord + " " << wordToRight << std::endl;
        }
    }
}


//function creating a vector of characters
std::vector<char> allCharactersOfText(std::vector<std::string>& textOfEntireBook) {
    //variable to store the vector of characters
    std::vector<char> allCharactersOfText;
    
    //loop to create character vector
    for (std::string strings: textOfEntireBook) {
        for (char c: allCharactersOfText) {
            allCharactersOfText.push_back(c);
        }
    }
    return allCharactersOfText;
}

//this function doesn't work yet
//function to find the position of the key words first character
int findPositionOfKeyWord(std::string keyword, std::vector<char> allCharactersOfText) {
    //variable that will store position
    int positionOfKeyWord = 0;
    //variable that will store the characters of keyword
    std::vector<char> charactersOfKeyWord;
    //loop to loop through the key word and make it a vector of characters
    for (char c: keyword) {
        charactersOfKeyWord.push_back(c);
    }
    
    for (int i = 0; i < charactersOfKeyWord.size(); i++) {
        if (charactersOfKeyWord[i] == keyword[i]) {
            positionOfKeyWord = i;
            break;
        }
    }
    return positionOfKeyWord;
}


