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
    std::vector<int> allRanks = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    
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
        } else if (newCard.rank == 1){
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
    for (unsigned long int i = deckOfCards.size() - 1; i >= 0; i--) {
        int j = std::rand() % 52;
        
    }
}

//implementation of swap function (look at lecture notes for this)
