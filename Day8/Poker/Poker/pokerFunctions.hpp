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
std::vector<Card> createHandOfCards(std::vector<Card> deckOfCards);


/*write a function to shuffle the deck. It should modify its parameter and return void. */
void shuffleDeckOfCards (std::vector<Card>& deckOfCards);


//create a function that creates a hand of five cards to test isFlush, isStraight, isStraightFlush and isRoyalFlush
std::vector<Card> testHandOne(std::vector<Card>& testDeck);


//function that prints the test deck of 5 cards
void printHandOfFiveCards(std::vector<Card> testDeck);


//isFlush: are all the cards the same suit?
bool isHandFlush(std::vector<Card> handOfCards);


//isStraight: are all 5 cards in numerical order (note this is a little tricky because the hand is unsorted!)
bool isHandStraight(std::vector<Card> handOfCards);


//isStraightFlush: is this hand both a straight and a flush?
bool isHandStraightFlush(std::vector<Card> handOfCards);


//isRoyalFlush: is this hand a straight flush whose low card is a ten?
bool isHandRoyalFlush(std::vector<Card> handOfCards);


//isFullHouse: are there 3 of one rank, and 2 of another (for example: 3 aces and 2 fives)
bool isHandFullHouse(std::vector<Card> handOfCards);


//STATISTICAL ANALYSIS FUNCTIONS

//Finally, we're going to do some statistical analysis. In main(), create a deck. Then, shuffle it many times. After each shuffle, check whether the hand is one of the hands you test for above and keep track of the total numbers of flushes, straights, royal flushes, etc, you see.
//
//Print out what fraction of hands are one of the above. You probably will not see a royal flush until you examine 100k to 1 milion hands!
//
//At the top of your code (in comments), record the percentage you see each type of hand.

//create a function that takes the first 5 random cards of the deck and returns a deck
std::vector<Card> createNewFiveCards(std::vector<Card> deckOfCards);

//create a sort function for the ranks that returns integers
std::vector<int> sortCardsByRanks(std::vector<Card> handOfCards);

//create a sort function for the suits
std::vector<std::string> sortCardsBySuits(std::vector<Card> handOfCards);

#endif /* pokerFunctions_hpp */
