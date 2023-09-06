//
//  bookAnalyzer.hpp
//  BookAnalyzer
//
//  Created by Josh Barton on 8/31/23.
//

#ifndef bookAnalyzer_hpp
#define bookAnalyzer_hpp

#include <stdio.h>
#include <string>

//function for finding the title index
int findTitleIndex(std::vector<std::string>& textOfEntireBook);

//function for finding the author index
int findAuthorIndex(std::vector<std::string>& textOfEntireBook);

//function to find the title of the book
std::string findBookTitle(std::vector<std::string>& textOfEntireBook);



//function for finding the release date index
int findReleaseDateIndex(std::vector<std::string>& textOfEntireBook);


//function to find the author of the book
std::string findBookAuthor(std::vector<std::string>& textOfEntireBook);


//function to calculate the total number of words in the file
unsigned long calculateTotalNumOfWordsInFile(std::vector<std::string>& textOfEntireBook);

//function to calculate the total number of characters in the file
unsigned long calculateTotalNumOfCharactersInFile(std::vector<std::string>& textOfEntireBook);


//function to find the shortest word in the book
std::string findShortestWordInBook(std::vector<std::string>& textOfEntireBook);


//function to find the longest word in the book
std::string findLongestWordInBook(std::vector<std::string>& textOfEntireBook);


//function for finding the key word
int findHowManyTimesKeyWordAppears(std::string& keyWord, std::vector<std::string>& textOfEntireBook);



//function that prints out the statistics
void giveKeyWordStatisticsAndInformation(std::string& keyWord, unsigned long& totalNumOfCharactersInFile, std::vector<std::string>& textOfEntireBook);

//function creating a vector of characters
std::vector<char> allCharactersOfText(std::vector<std::string>& textOfEntireBook);


//function to find the position of the key words first character
int findPositionOfKeyWord(std::string keyword, std::vector<char> allCharactersOfText);


#endif /* bookAnalyzer_hpp */
