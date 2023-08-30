//
//  pokerFunctions.hpp
//  Poker
//
//  Created by Josh Barton on 8/30/23.
//

#ifndef pokerFunctions_hpp
#define pokerFunctions_hpp

#include <stdio.h>
#include <string>

//create struct for a card
struct Card {
    std::string suit;
    int rank;
};

//create a function to create a deck of cards
std::vector<Card> deckOfCards(std::vector<Card>& deckOfCards);

//create a function to print a deck of cards
void printDeckOfCards(std::vector<Card> deckOfCards);

/*write a function to shuffle the deck. It should modify its parameter and return void. */
void shuffleDeckOfCards (std::vector<Card> deckOfCards);

//write swap function


#endif /* pokerFunctions_hpp */
