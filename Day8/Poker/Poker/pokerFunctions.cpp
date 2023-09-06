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
#include <algorithm>


//implementation of creating a deck of cards
std::vector<Card> deckOfCards(std::vector<Card>& deckOfCards) {
    
    //create vector of the different suits.
    std::vector<std::string> typeOfSuit = {"Diamond", "Club", "Spade", "Heart"};

    //create vector of the different card numbers
    std::vector<int> allRanks = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    
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

//implement a function that creates a hand of cards
std::vector<Card> createHandOfCards(std::vector<Card>& deckOfCards) {
    //create a variable to store the hand of five cards
    //create a hand of cards by taking the first 5 cars of the deck of cards
    std::vector<Card> handOfCards = {deckOfCards[0], deckOfCards[6], deckOfCards[11], deckOfCards[16], deckOfCards[21]};
    
    //return the 5 cards
    return handOfCards;
}

//implementation of the shuffle a deck of cards function
void shuffleDeckOfCards (std::vector<Card>& deckOfCards) {
    //set the seed
    
    for (unsigned long int i = deckOfCards.size() - 1; i > 0; i--) {
        //j is a random generated number
        int j = rand() % (i + 1);
        //here I'm creating an integer variable j. I'm assigning it to
        //i want to swap j with i
        //swap array elements i and j
        Card temp = deckOfCards[i];
        deckOfCards[i] = deckOfCards[j];
        deckOfCards[j] = temp;
    }
}


//write a function for creating a deck of 5 cards to test for isFlush, isStraight, isStraightFlush, and isRoyalFlush
std::vector<Card> testHandOne(std::vector<Card>& testDeck) {
    //create vector of the different suits.
    std::vector<std::string> typeOfSuit = {"Diamond"};

    //create vector of the card numbers 1 through 5
    std::vector<int> allRanks = {10, 11, 12, 13, 14};
    
    //use a for loop and a nested for loop to create a type card with the type of suit and the rank
    for (int i = 0; i < typeOfSuit.size(); i++) {
        for (int j = 0; j < allRanks.size(); j++) {
            Card newCard = {typeOfSuit[i], allRanks[j]};
            testDeck.push_back(newCard);
            
        }
    }
    return testDeck;
}

//function that prints test deck of 5 cards
void printHandOfFiveCards(std::vector<Card> deckOfCards) {
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
bool isHandFlush(std::vector<Card>& handOfCards) {
    //create variable that stores the first suit of the deck of cards
    std::string targetSuit = handOfCards[0].suit;
    for (int i = 1; i < handOfCards.size(); i++) {
        //check to see if those cards are all the same suit
        if (handOfCards[i].suit != targetSuit) {
            return false;
        }
    }
    return true;
}

//fix this one
//implementation of the isStraight function: are all 5 cards in numerical order
bool isHandStraight(std::vector<Card>& handOfCards) {
    //sort cards by rank
    std::vector<int> sortedByRank = sortCardsByRanks(handOfCards);
    
    //check if the integers in the sortedByRank vector have a difference of one between them.
    for (int i = 0; i < sortedByRank.size() - 1; i++) {
        if (sortedByRank[i + 1] - sortedByRank[i] != 1) {
            return false;
        }
    }
    return true;
}


//implementation of the isStraightFlush function: is this hand both a straight and a //flush?
bool isHandStraightFlush(std::vector<Card>& handOfCards) {
    //return the results of isFlush and isStraight, if both of them are true //isStraightFlush will be true
    return (isHandFlush(handOfCards) && isHandStraight(handOfCards));
}


//implementation of the isRoyalFlush function: is this hand a straight flush whose //low card is a ten?
bool isHandRoyalFlush(std::vector<Card>& handOfCards) {
    //create boolean variable that will store if the lowest card is a 10
    bool isLowestCardRankTen = false;
    
    //sort cards by ranks saved in a variable
    std::vector<int> sortedByRank = sortCardsByRanks(handOfCards);
    
    //check if lowest card in the sorted deck is equal to 10
    if (sortedByRank[0] == 10) {
        isLowestCardRankTen = true;
    }
    
    // Return whether it's a royal flush
    return (isHandFlush(handOfCards) && isHandStraight(handOfCards) && isLowestCardRankTen);
    }


//implementation of the isFullHouse function: are there 3 of one rank, and 2 of //another (for example: 3 aces and 2 fives)
bool isHandFullHouse(std::vector<Card>& handOfCards) {
    //vector to store the sorted ranks
    std::vector<int> sortedByRanks = sortCardsByRanks(handOfCards);
    
    if ((sortedByRanks[0] == sortedByRanks[1] && sortedByRanks[0] == sortedByRanks[2] && sortedByRanks[3] == sortedByRanks[4]) || (sortedByRanks[0] == sortedByRanks[1] && sortedByRanks[2] == sortedByRanks[3] && sortedByRanks[3] == sortedByRanks[4])) {
        return true;
    }
    
    return false;
}


//create a sort function for the ranks that returns integers
std::vector<int> sortCardsByRanks(std::vector<Card>& handOfCards) {
    //create an integer varible to save the sorted card ranks
    std::vector<int> cardsByRank;
    //go through the handOfCards
    for (Card newCard: handOfCards) {
        cardsByRank.push_back(newCard.rank);
    }
    
    //take the hand of cards and sort them
    std::sort(cardsByRank.begin(), cardsByRank.end());
    
    return cardsByRank;
}




