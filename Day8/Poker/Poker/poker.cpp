//
//  main.cpp
//  Poker
//
//  Created by Josh Barton on 8/30/23.
//

#include <iostream>
#include "pokerFunctions.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<Card> cards = {};
    deckOfCards(cards);
    printDeckOfCards(cards);
    
    return 0;
}
