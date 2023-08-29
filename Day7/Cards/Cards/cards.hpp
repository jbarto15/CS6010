//
//  cards.hpp
//  Cards
//
//  Created by Josh Barton on 8/29/23.
//

#ifndef cards_hpp
#define cards_hpp

#include <stdio.h>
#include <string>

//create struct for a card
struct Card {
    std::string suit;
    int rank;
};

//create a function to create a deck of cards.
std::vector<Card> deckOfCards();

//create a function to print a deck of cards.
void printDeckOfCards(std::vector<Card> deckOfCards);


#endif /* cards_hpp */
