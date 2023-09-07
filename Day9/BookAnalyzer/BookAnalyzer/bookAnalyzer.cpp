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
    //initialize title position variable
    int titlePosition = -1;
    
    //variable for book title to be stored in
    std::string bookTitle;
    
    //vector variable to store the words after title until author
    std::vector<std::string> vectorOfWordsMakingTheTitle;
    
    //store actual title index
    titlePosition = findTitleIndex(textOfEntireBook);
    
    //loop through the text starting at title and go until author
    if (titlePosition != -1) {
        for (int i = titlePosition; i < findAuthorIndex(textOfEntireBook); i++) {
            //go through the loop and save the following words into a vector of strings
            vectorOfWordsMakingTheTitle.push_back(textOfEntireBook[i]);
        }
    } else {
        bookTitle = "Title: unknown";
    }
    
    //access all the words in the vector
    for (int i = 0; i < vectorOfWordsMakingTheTitle.size(); i++) {
        bookTitle += vectorOfWordsMakingTheTitle[i] + " ";
    }
    
    return bookTitle;
}



//function to find the author of the book
std::string findBookAuthor(std::vector<std::string>& textOfEntireBook) {
    //initialize title position variable
    int authorPosition = -1;
    
    //variable for book author to be stored in
    std::string bookAuthor;
    
    //vector variable to store the words after title until author
    std::vector<std::string> vectorOfWordsMakingTheAuthor;
    
    
    //store actual author index
    authorPosition = findAuthorIndex(textOfEntireBook);
    //loop through the text starting at title and go until author
    if (authorPosition != -1)
    for (int i = authorPosition; i < findReleaseDateIndex(textOfEntireBook); i++) {
        //go through the loop and save the following words into a vector of strings
        vectorOfWordsMakingTheAuthor.push_back(textOfEntireBook[i]);
    } else {
        bookAuthor = "Author: unknown";
    }
    //access all the words in the vector
    for (int i = 0; i < vectorOfWordsMakingTheAuthor.size(); i++) {
        bookAuthor += vectorOfWordsMakingTheAuthor[i] + " ";
    }
    
    return bookAuthor;
}




//function to calculate the total number of words in the file
int calculateTotalNumOfWordsInFile(std::vector<std::string>& textOfEntireBook) {
    //create variable that will return the total number of words in file
    int totalNumOfWordsInFile = textOfEntireBook.size();
    
    return totalNumOfWordsInFile;
}



//function to calculate the total number of characters in the file
int calculateTotalNumOfCharactersInFile(std::vector<std::string>& textOfEntireBook) {
    //create totalNumOfCharacters variable
    int totalNumOfCharacters = 0;
    
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


void giveKeyWordStatisticsAndInformation(std::string& keyWord, int& totalNumOfCharactersInFile, std::vector<std::string>& textOfEntireBook) {
    //variable for word to the left and word to the right
    std::string wordToLeft;
    std::string wordToRight;
    
    //variable to calculate the percentage
    float percentage = 0;
    
    //variable to save the position of the keyword
    float positionOfKeyWord = 0;
    
    //create counter variable that will count the length of each word in the entire book
    int totalCount = 0;
    
    //use a loop to find the keyword
    for (int i = 0; i < textOfEntireBook.size(); i++) {
        totalCount += textOfEntireBook[i].length();
        
        if (keyWord == textOfEntireBook[i] && i >= 0 && i < textOfEntireBook.size()) {
            wordToLeft = textOfEntireBook[i - 1];
            wordToRight = textOfEntireBook[i + 1];
            positionOfKeyWord = totalCount - (keyWord.size() - 1);
            percentage = (positionOfKeyWord / totalNumOfCharactersInFile) * 100;
            std::cout << " at " << percentage << "%: " << wordToLeft + " " << keyWord + " " << wordToRight << std::endl;
        }
    }
}




