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


/*write a function to shuffle the deck. It should modify its parameter and return void. */
void shuffleDeckOfCards (std::vector<Card>& deckOfCards);


//create a function that creates a deck of five cards to test isFlush, isStraight, isStraightFlush and isRoyalFlush
std::vector<Card> testDeckOne(std::vector<Card>& testDeck);


//function that prints the test deck of 5 cards
void printDeckOfFiveCards(std::vector<Card> deckOfCards);


//isFlush: are all the cards the same suit?
bool isFlush(std::vector<Card> deckOfCards);


//isStraight: are all 5 cards in numerical order (note this is a little tricky because the hand is unsorted!)
bool isStraight(std::vector<Card> deckOfCards);


//isStraightFlush: is this hand both a straight and a flush?
bool isStraightFlush(std::vector<Card> deckOfCards);


//isRoyalFlush: is this hand a straight flush whose low card is a ten?
bool isRoyalFlush(std::vector<Card> deckOfCards);


//isFullHouse: are there 3 of one rank, and 2 of another (for example: 3 aces and 2 fives)
bool isFullHouse(std::vector<Card> deckOfCards);


//STATISTICAL ANALYSIS FUNCTIONS

//Finally, we're going to do some statistical analysis. In main(), create a deck. Then, shuffle it many times. After each shuffle, check whether the hand is one of the hands you test for above and keep track of the total numbers of flushes, straights, royal flushes, etc, you see.
//
//Print out what fraction of hands are one of the above. You probably will not see a royal flush until you examine 100k to 1 milion hands!
//
//At the top of your code (in comments), record the percentage you see each type of hand.

//function to keep track of number of isFlush's
int getNumOfFlush(bool isFlush);

//function to keep track of number of isStraight's
int getNumOfStraights(bool isStraight);

//function to keep track of number of isStraightFlush
int getNumOfStraightFlush(bool isStraightFlush);

//function to keep track of number of Royal Flush's
int getNumOfRoyalFlush(bool isRoyalFlush);

//function to keep track of number of Full House's
int getNumOfFullHouse(bool isHouseFlush);

#endif /* pokerFunctions_hpp */
