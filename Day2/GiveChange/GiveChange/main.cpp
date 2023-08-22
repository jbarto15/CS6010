//
//  main.cpp
//  GiveChange
//
//  Created by Josh Barton on 8/22/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // creation of variables
    int itemPrice;
    int amountPaid;
    int changeToReturn;
    int numberOfQuarters;
    int remainingCentsAfterQuarters;
    int numberOfDimes;
    int remainingCentsAfterDimes;
    int numberOfNickels;
    int remainingCentsAfterNickels;
    int numberOfPennies;
    int fewestPossibleCoins;
    
    // prompt the user to enter the item price
    std::cout << "Item price in cents: ";
    std::cin >> itemPrice;
    
    // prompt user to enter amount paid
    std::cout << "Amount Paid in cents: ";
    std::cin >> amountPaid;
    
    // report the total amount of change to return
    changeToReturn = amountPaid - itemPrice;
    std::cout << "Change: ";
    std::cout << changeToReturn;
    std::cout << " cents\n";
    
    // report the number of quarters and then print the result
    /* number of quarters will check to see how much change is left and will do that divided by 25. If greater than 25 it should show at least 1 */
    numberOfQuarters = changeToReturn / 25;
    std::cout << "Quarters: ";
    std::cout << numberOfQuarters << "\n";
    
    //calculate the number of cents left over after quarters.
    remainingCentsAfterQuarters = changeToReturn % 25;
    
    // report the number of dimes and then print the result
    numberOfDimes = remainingCentsAfterQuarters / 10;
    std::cout << "Dimes: ";
    std::cout << numberOfDimes << std::endl;
    
    //calculate the number of cents left over after dimes
    remainingCentsAfterDimes = remainingCentsAfterQuarters % 10;
    
    // report the number of nickels and then print the result
    numberOfNickels = remainingCentsAfterDimes / 5;
    std::cout << "Nickels: ";
    std::cout << numberOfNickels << std::endl;
    
    //calculate the number of cents left over after nickels
    remainingCentsAfterNickels = remainingCentsAfterDimes % 5;
    
    // report the number of pennies
    numberOfPennies = remainingCentsAfterNickels / 1;
    std::cout << "Pennies: ";
    std::cout << numberOfPennies << std::endl;
    
    // the fewest number of coins possible are returned here
    fewestPossibleCoins = numberOfQuarters + numberOfDimes + numberOfNickels + numberOfPennies;
    std::cout << "Fewest Coins Possible: ";
    std::cout << fewestPossibleCoins << '\n';
    
    return 0;
}
