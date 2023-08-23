//
//  main.cpp
//  IfStatementPractice
//
//  Created by Josh Barton on 8/23/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //declare variables
    int age;
    
    //prompt user for their age and read in their response and store it in the age variable
    std::cout << "What is your age?\n";
    std::cin >> age;
    
    //create if statement that sees if the user is able to vote. The voting age is 18
    if (age >= 18) {
        std::cout << "You are old enough to vote.\n";
    }
    
    //create if statement that check if the user can run for senate. Needs to be age 30 or older
    if (age >= 30) {
        std::cout << "You are old enough to run for senate.\n";
    }
    
    //create if statement to check if user is part of the greatest generation
    if (age > 80) {
        std::cout << "You are part of the greatest generation!\n";
    }
    
    //create if statement to check if user is part of the baby boomer generation
    if (age < 80 && age > 60) {
        std::cout << "You are part of the baby boomer generation!\n";
    }
    
    //create if statement to check if user is part of generation X
    if (age > 40 && age < 60) {
        std::cout << "You are part of generation X!\n";
    }
    
    //create if statement to check if user is part of millenial generation and else statement to say that anyone else is part of the iKid generation.
    if (age > 20 && age < 40) {
        std::cout << "You are part of the millenial generation!\n";
    } else if (age < 20) {
        std::cout << "You are part of the iKid generation!\n";
    }
    
    //Part 2 of If Statement Practice
    
    //declare variables
    char weekdayResponse;
    char holidayResponse;
    char youngChildrenResponse;
    bool isWeekday = false;
    bool isHoliday = false;
    bool hasYoungChildren = false;
    
    
    //prompt the user to enter whether or not its a weekday with a Y or N and have them re-enter if its not a Y or N
    do{
        std::cout << "Is today a Weekday? Answer with Y/N\n";
        std::cin >> weekdayResponse;
    }while(weekdayResponse != 'Y' && weekdayResponse != 'N');
    
    //statement that decides whether the user entered Y or N for whether or not it is a weekday and based off that answer, I put the answer into the isWeekday variable.
    if (weekdayResponse == 'Y') {
        isWeekday = true;
    }
    
    //prompt user to enter whether or not it is a holiday, Y or N
    do {
        std::cout << "Is today a Holiday? Answer with Y/N\n";
        std::cin >> holidayResponse;
    } while (holidayResponse != 'Y' && holidayResponse != 'N');
    
    //statement that decides whether the user entered Y or N for whether or not it is a holiday.
    if (holidayResponse == 'Y') {
        isHoliday = true;
    }
    
    //prompt user to enter whether or not they have young children with Y or N
    do {
        std::cout << "Do you have young children? Answer with Y/N\n";
        std::cin >> youngChildrenResponse;
    } while (youngChildrenResponse != 'Y' && youngChildrenResponse != 'N');
    //statement that decides whether the user entered Y or N for whether or not they have young children
    if (youngChildrenResponse == 'Y') {
        hasYoungChildren = true;
    }
    
    //print whether the user gets to sleep in today or not based on there answers to if it's a weekday, holiday, or they have young children.
    if (isWeekday && !isHoliday && hasYoungChildren) {
        std::cout << "You cannot sleep in today!\n";
    } else if (!isWeekday && isHoliday && !hasYoungChildren) {
        std::cout << "You can sleep in today! Yay!\n";
    } else if (isWeekday && isHoliday && !hasYoungChildren) {
        std::cout << "You can sleep in today! Yay!\n";
    }
    
    return 0;
}
