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
void shuffleDeckOfCards (std::vector<Card>& deckOfCards);


//write swap function

//create a function that creates a deck of five cards to test isFlush, isStraight, isStraightFlush and isRoyalFlush
std::vector<Card> testDeckOne(std::vector<Card>& testDeck);


//function that prints the test deck of 5 cards
void printDeckOfFiveCards(std::vector<Card> deckOfCards);


//isFlush: are all the cards the same suit?
bool isFlush(std::vector<Card> fiveCards);


//isStraight: are all 5 cards in numerical order (note this is a little tricky because the hand is unsorted!)
bool isStraight(std::vector<Card> fiveCards);


//isStraightFlush: is this hand both a straight and a flush?
bool isStraightFlush(std::vector<Card> fiveCards);


//isRoyalFlush: is this hand a straight flush whose low card is a ten?
bool isRoyalFlush(std::vector<Card> fiveCards);


//isFullHouse: are there 3 of one rank, and 2 of another (for example: 3 aces and 2 fives)
bool isFullHouse(std::vector<Card> fiveCards);



#endif /* pokerFunctions_hpp */
