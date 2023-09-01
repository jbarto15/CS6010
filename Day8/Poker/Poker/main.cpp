//
//  main.cpp
//  Poker
//
//  Created by Josh Barton on 8/30/23.
//


#include "pokerFunctions.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<Card> cards = {};
    deckOfCards(cards);
    //printDeckOfCards(cards);
    
    shuffleDeckOfCards(cards);
    //printDeckOfCards(cards);
    
    //std::vector<Card> testDeck = {};
    std::vector<Card> testDeck;

    //testDeckOne(testDeck);
    //printDeckOfFiveCards(testDeck);
    
    //check if isFlush function is working with testDeckOne function
    //std::cout << isFlush(testDeckOne(testDeck));
    
    //try a randomized deck in isFlush
    //std::cout << isFlush(deckOfCards(cards));
    
    //printing out whether or not isStraight function is true
    //std::cout << isStraight(testDeckOne(testDeck));
    
    //printing out whether or not isStraightFlush function is true
    //std::cout << isStraightFlush(testDeckOne(testDeck));
    
    //call isRoyalFlush function and print it
    std::cout << isRoyalFlush(testDeckOne(testDeck));
    

    
    return 0;
}
