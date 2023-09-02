//
//  bookAnalyzer.cpp
//  BookAnalyzer
//
//  Created by Josh Barton on 8/31/23.
//

#include "bookAnalyzer.hpp"
#include <iostream>


//function to find the title of the book
std::string findBookTitle(std::vector<std::string>& textOfEntireBook) {
    //variable for book title to be stored in
    std::string bookTitle;
    //vector variable to store the words after title until author
    std::vector<std::string> vectorOfWordsMakingTheTitle;
    //loop through the entire text and look for the keyword
    for (std::string title: textOfEntireBook) {
        //if string is equal to "Title", print the title
        if (title == "Title") {
            //continue going through the loop and saving the following words into a vector of strings
            vectorOfWordsMakingTheTitle.push_back(title);
            continue;
        } else if (title == "Author") {
            break;
        }
    }
    //access all the words in the vector
    for (int i = 0; i < vectorOfWordsMakingTheTitle.size(); i++) {
        bookTitle = vectorOfWordsMakingTheTitle[i];
    }
    
    std::cout << "Book Title: " << bookTitle << std::endl;
    
    return bookTitle;
}
