//
//  main.cpp
//  Poker
//
//  Created by Josh Barton on 8/30/23.
//


#include "pokerFunctions.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::vector<Card> cards = {};
//    deckOfCards(cards);
    //printDeckOfCards(cards);
    
    //create a hand of cards
    //createHandOfCards(cards);
    

    
    //std::vector<Card> testDeck = {};
    //std::vector<Card> testDeck;

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
    //std::cout << isHandRoyalFlush(testHandOne(testDeck)) << std::endl;
    
    //call isHandFullHouse and print it
    //std::cout << isHandFullHouse(testHandOne(testDeck)) << std::endl;
    
    
    //create empty vector of cards
    std::vector<Card> cards = {};
    //call deck of cards to create a deck
    deckOfCards(cards);
    
    
    //create counter variables
    int numOfHandFlush = 0;
    int numOfHandStraight = 0;
    int numOfHandStraightFlush = 0;
    int numOfHandRoyalFlush = 0;
    int numOfHandFullHouse = 0;
    
    //variable that stores the total num of hands
    int totalNumberOfHands = 0;

    //create a for loop that will shuffle the deck a lot of times and then keep track of the number of times each function returns true
    for (int i = 0; i < 10000; i++) {
        shuffleDeckOfCards(cards);
        createHandOfCards(cards);
        std::vector<Card> newHand = createHandOfCards(cards);
        for(Card cd : newHand){
            std::cout << "Rank" << cd.rank << "Suit" << cd.suit << std::endl;
        }
        std::cout << " New 5" << std:: endl;
        if (isHandFlush((cards))) {
            numOfHandFlush += 1;
        } else if (isHandStraight(cards)) {
            numOfHandStraight += 1;
        } else if (isHandStraightFlush(cards)) {
            numOfHandStraightFlush += 1;
        } else if (isHandRoyalFlush(cards)) {
            numOfHandRoyalFlush += 1;
        } else if (isHandFullHouse(cards)) {
            numOfHandFullHouse += 1;
        }
        totalNumberOfHands += 1;
    }
    
    std::cout << numOfHandFlush << std::endl;
    std::cout << numOfHandStraight << std::endl;
    std::cout << numOfHandStraightFlush << std::endl;
    std::cout << numOfHandRoyalFlush << std::endl;
    std::cout << numOfHandFullHouse << std::endl;
    
    //percentage of hands that are a flush and print percentage
    float percentageOfHandsFlush = numOfHandFlush / totalNumberOfHands;
    std::cout << "Percentage of Hands Flush: " << percentageOfHandsFlush << std::endl;
    
    //percentage of hands that are a straight and print percentage
    float percentageOfHandsStraight = numOfHandStraight / totalNumberOfHands;
    std::cout << "Percentage of Hands Straight: " << percentageOfHandsStraight << std::endl;
    
    //percentage of hands that are a straightflush and print percentage
    float percentageOfHandsStraightFlush = numOfHandStraightFlush / totalNumberOfHands;
    std::cout << "Percentage of Hands Straight Flush: " << percentageOfHandsStraightFlush << std::endl;
    
    //percentage of hands that are a royalflush and print percentage
    float percentageOfHandsRoyalFlush = numOfHandRoyalFlush / totalNumberOfHands;
    std::cout << "Percentage of Hands Royal Flush: " << percentageOfHandsRoyalFlush << std::endl;
    
    //percentage of hands that are a fullhouse and print percentage
    float percentageOfHandsFullHouse = numOfHandFullHouse / totalNumberOfHands;
    std::cout << "Percentage of Hands Full House: " << percentageOfHandsFullHouse << std::endl;
    
    
    
    
    return 0;
}
