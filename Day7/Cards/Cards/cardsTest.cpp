//
//  main.cpp
//  Cards
//
//  Created by Josh Barton on 8/29/23.
//

#include <iostream>
#include "cards.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::vector<Card> deck = deckOfCards();
    printDeckOfCards(deck);
    
    return 0;
}
