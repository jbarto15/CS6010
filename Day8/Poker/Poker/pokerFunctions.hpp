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
#include <iostream>

//create struct for a card
struct Card {
    std::string suit;
    int rank;
};


//create a function to create a deck of cards
std::vector<Card> deckOfCards(std::vector<Card>& deckOfCards);


//create a function to print a deck of cards
void printDeckOfCards(std::vector<Card> deckOfCards);


//definition of a function that creates a hand of cards
std::vector<Card> createHandOfCards(std::vector<Card>& deckOfCards);


/*write a function to shuffle the deck. It should modify its parameter and return void. */
void shuffleDeckOfCards (std::vector<Card>& deckOfCards);


//create a function that creates a hand of five cards to test isFlush, isStraight, isStraightFlush and isRoyalFlush
std::vector<Card> testHandOne(std::vector<Card>& testDeck);


//function that prints the test deck of 5 cards
void printHandOfFiveCards(std::vector<Card> testDeck);


//isFlush: are all the cards the same suit?
bool isHandFlush(std::vector<Card>& handOfCards);


//isStraight: are all 5 cards in numerical order (note this is a little tricky because the hand is unsorted!)
bool isHandStraight(std::vector<Card>& handOfCards);


//isStraightFlush: is this hand both a straight and a flush?
bool isHandStraightFlush(std::vector<Card>& handOfCards);


//isRoyalFlush: is this hand a straight flush whose low card is a ten?
bool isHandRoyalFlush(std::vector<Card>& handOfCards);


//isFullHouse: are there 3 of one rank, and 2 of another (for example: 3 aces and 2 fives)
bool isHandFullHouse(std::vector<Card>& handOfCards);


//create a sort function for the ranks that returns integers
std::vector<int> sortCardsByRanks(std::vector<Card>& handOfCards);

//create a sort function for the suits
std::vector<std::string> sortCardsBySuits(std::vector<Card>& handOfCards);




#endif /* pokerFunctions_hpp */
