//
//  pokerFunctions.cpp
//  Poker
//
//  Created by Josh Barton on 8/30/23.
//

#include "pokerFunctions.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


//implementation of creating a deck of cards
std::vector<Card> deckOfCards(std::vector<Card>& deckOfCards) {
    
    //create vector of the different suits.
    std::vector<std::string> typeOfSuit = {"Diamond", "Club", "Spade", "Heart"};

    //create vector of the different card numbers
    std::vector<int> allRanks = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    
    //create new vector to store the suits and ranks for each iteration
    //std::vector<Card> deckOfCards = {};
    
//    use a for loop and a nested for loop to create a type card with the type of suit and the rank
    for (int i = 0; i < typeOfSuit.size(); i++) {
        for (int j = 0; j < allRanks.size(); j++) {
            Card newCard = {typeOfSuit[i], allRanks[j]};
            deckOfCards.push_back(newCard);
        }
    }
    
    
    return deckOfCards;
}

//implementation of printing a deck of cards
void printDeckOfCards(std::vector<Card> deckOfCards) {
    for (Card newCard: deckOfCards) {
        std::cout << newCard.suit << " ";
        if (newCard.rank == 11) {
            std::cout<< "Jack\n";
        } else if (newCard.rank == 12) {
            std::cout << "Queen\n";
        } else if (newCard.rank == 13) {
            std::cout<< "King\n";
        } else if (newCard.rank == 14){
            std::cout << "Ace\n";
        }
        else {
                std::cout << newCard.rank << std::endl;
            }
    }
}

//implementation of the shuffle a deck of cards function

/* Below is a simple algorithm for shuffling an array or length N:
 
*/
/* for i = N -1 down to 0
 
 pick a random integer j between 0 and i

 swap array elements i and j*/

void shuffleDeckOfCards (std::vector<Card>& deckOfCards) {
    for (unsigned long int i = deckOfCards.size() - 1; i > 0; i--) {
        //j is a random generated number
        int j = std::rand() % (i + 1);
        //i want to swap j with i
        //swap array elements i and j
        Card temp = deckOfCards[i];
        deckOfCards[i] = deckOfCards[j];
        deckOfCards[j] = temp;
    }
}


//write a function for creating a deck of 5 cards to test for isFlush, isStraight, isStraightFlush, and isRoyalFlush
std::vector<Card> testDeckOne(std::vector<Card>& testDeck) {
    
    //create vector of the different suits.
    std::vector<std::string> typeOfSuit = {"Diamond"};

    //create vector of the card numbers 1 through 5
    std::vector<int> allRanks = {10, 11, 12, 13, 14};
    
//    use a for loop and a nested for loop to create a type card with the type of suit and the rank
    for (int i = 0; i < typeOfSuit.size(); i++) {
        for (int j = 0; j < allRanks.size(); j++) {
            Card newCard = {typeOfSuit[i], allRanks[j]};
            testDeck.push_back(newCard);
        }
    }
    
    
    return testDeck;
}

//function that prints test deck of 5 cards
void printDeckOfFiveCards(std::vector<Card> deckOfCards) {
    for (Card newCard: deckOfCards) {
        std::cout << newCard.suit << " ";
        if (newCard.rank == 11) {
            std::cout<< "Jack\n";
        } else if (newCard.rank == 12) {
            std::cout << "Queen\n";
        } else if (newCard.rank == 13) {
            std::cout<< "King\n";
        } else if (newCard.rank == 14){
            std::cout << "Ace\n";
        }
        else {
                std::cout << newCard.rank << std::endl;
            }
    }
}


//implementation of the isFlush function. are all the cards the same suit?
bool isFlush(std::vector<Card> fiveCards) {
    //receive the shuffled deck
    //go through the shuffled deck and select the first 5 cards
    for (int i = 0; i < 5; i++) {
        //store those cards
        Card newCard = fiveCards[i];
        fiveCards.push_back(newCard);
    }
    
    for (int i = 0; i < fiveCards.size(); i++) {
        //then check to see if those cards are all the same suit
        if (fiveCards[i].suit == "Diamond") {
            continue;
        } else {
            return false;
        }
    }
    
    //if they are print out "you have a flush"
    //else print out "try again"
    return true;
}


//implementation of the isStraight function: are all 5 cards in numerical order
bool isStraight(std::vector<Card> fiveCards) {
    return true;
}


//implementation of the isStraightFlush function: is this hand both a straight and a //flush?
bool isStraightFlush(std::vector<Card> fiveCards) {
    return true;
}


//implementation of the isRoyalFlush function: is this hand a straight flush whose //low card is a ten?
bool isRoyalFlush(std::vector<Card> fiveCards) {
    return true;
}


//implementation of the isFullHouse function: are there 3 of one rank, and 2 of //another (for example: 3 aces and 2 fives)
bool isFullHouse(std::vector<Card> fiveCards) {
    return true;
}

