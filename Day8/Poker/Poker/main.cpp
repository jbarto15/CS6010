//
//  main.cpp
//  Poker
//
//  Created by Josh Barton on 8/30/23.
//


#include "pokerFunctions.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //seed for random number generator
    std::srand(time(0));
    
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
    for (int i = 0; i < 900; i++) {
        shuffleDeckOfCards(cards);
        createHandOfCards(cards);
        std::vector<Card> newHand = createHandOfCards(cards);
        for(Card cd : newHand){
            //std::cout << "Rank " << cd.rank << " Suit " << cd.suit << std::endl;
        }
        //std::cout << " New 5" << std:: endl;
        if (isHandFlush((newHand))) {
            numOfHandFlush += 1;
        } else if (isHandStraight(newHand)) {
            numOfHandStraight += 1;
        } else if (isHandStraightFlush(newHand)) {
            numOfHandStraightFlush += 1;
        } else if (isHandRoyalFlush(newHand)) {
            numOfHandRoyalFlush += 1;
        } else if (isHandFullHouse(newHand)) {
            numOfHandFullHouse += 1;
        }
        totalNumberOfHands += 1;
    }
    
    std::cout << "Number of Flush: " << numOfHandFlush << std::endl;
    std::cout << "Number of Straight: " << numOfHandStraight << std::endl;
    std::cout << "Number of Straight-Flush: " << numOfHandStraightFlush << std::endl;
    std::cout << "Number of Royal-Flush: " << numOfHandRoyalFlush << std::endl;
    std::cout << "Number of Full-House: " << numOfHandFullHouse << std::endl;
    
    //percentage of hands that are a flush and print percentage
    float percentageOfHandsFlush = float ((numOfHandFlush) / float (totalNumberOfHands)) * 100;
    std::cout << "Percentage of Hands Flush: " << percentageOfHandsFlush << std::endl;
    
    //percentage of hands that are a straight and print percentage
    float percentageOfHandsStraight = float ((numOfHandStraight) / float (totalNumberOfHands)) * 100;
    std::cout << "Percentage of Hands Straight: " << percentageOfHandsStraight << std::endl;
    
    //percentage of hands that are a straightflush and print percentage
    float percentageOfHandsStraightFlush = float ((numOfHandStraightFlush) / float (totalNumberOfHands)) * 100;
    std::cout << "Percentage of Hands Straight Flush: " << percentageOfHandsStraightFlush << std::endl;
    
    //percentage of hands that are a royalflush and print percentage
    float percentageOfHandsRoyalFlush = float ((numOfHandRoyalFlush) / float (totalNumberOfHands)) * 100;
    std::cout << "Percentage of Hands Royal Flush: " << percentageOfHandsRoyalFlush << std::endl;
    
    //percentage of hands that are a fullhouse and print percentage
    float percentageOfHandsFullHouse = float ((numOfHandFullHouse) / float (totalNumberOfHands)) * 100;
    std::cout << "Percentage of Hands Full House: " << percentageOfHandsFullHouse << std::endl;
    
    
    
    
    return 0;
}
