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
int unsigned long calculateTotalNumOfWordsInFile(std::vector<std::string>& textOfEntireBook);


#endif /* bookAnalyzer_hpp */
