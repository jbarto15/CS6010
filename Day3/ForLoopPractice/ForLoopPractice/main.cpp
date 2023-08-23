//
//  main.cpp
//  ForLoopPractice
//
//  Created by Josh Barton on 8/23/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //create counter variable
    int i;
    int j = 1;
    
    //print numbers 1-10 using a for loop
    for (i = 1; i <= 10; i++) {
        std::cout << i;
        std::cout << " ";
    }
    
    //new line for the while loop
    std::cout << '\n';
    
    //print number 1-10 using a while loop
    while (j <= 10) {
        std::cout << j;
        std::cout << " ";
        j = j + 1;
    }
    //new line
    std::cout << '\n';
    
    //I thought the for loop was more appropriate. It condenses everything really easily
    
    
    
    //variables for asking user to input 2 numbers
    int number1;
    int number2;
    int largerNumber = 0;
    int smallerNumber = 0;
    
    //Prompt the user to enter 2 numbers
    std::cout << "Please enter two numbers.\n";
    std::cout << "Number 1: ";
    std::cin >> number1;
    std::cout << "Number 2: ";
    std::cin >> number2;
    
    //if statements to determine which number is the larger number and which is the smaller number.
    if (number1 > number2) {
        largerNumber = number1;
        smallerNumber= number2;
    }
    else if (number1 < number2) {
        smallerNumber = number1;
        largerNumber = number2;
    }
    else {
        smallerNumber = number1;
        largerNumber = number1;
    }
    
    //while loop used to count up from smaller number to larger number.
    while (smallerNumber <= largerNumber) {
        std::cout << smallerNumber;
        std::cout << " ";
        smallerNumber = smallerNumber + 1;
    }
     
    //new line
    std::cout << '\n';
    
    
    //print all the odd numbers between 1 and 20 using an if statement
    for (int k = 1; k <= 20; k++) {
        if (k % 2 == 1) {
            std::cout << k;
            std::cout << " ";
        }
    }
    
    //new line
    std::cout << '\n';
    
    
    //print all the odd numbers without using an if statement
    for (int x = 1; x <= 20; x += 2) {
        std::cout << x;
        std::cout << " ";
    }
    
    //new line
    std::cout << '\n';
    
    
    //asking a user to enter positive numbers
    //creation of variables
    int positiveNumberFromUser;
    int sumOfPositiveNumbers = 0;
    
    //do while loop asking the user to enter a positive number
    do {
        std::cout << "Please enter positive numbers to add up.\n";
        std::cin >> positiveNumberFromUser;
        sumOfPositiveNumbers = positiveNumberFromUser + sumOfPositiveNumbers;
    } while (positiveNumberFromUser > 0);
    
    if (positiveNumberFromUser < 0) {
        sumOfPositiveNumbers = sumOfPositiveNumbers - positiveNumberFromUser;
        std::cout << "Sum of all numbers equal: ";
        std::cout << sumOfPositiveNumbers;
    }
    
    //new line
    std::cout << "\n";
    std::cout << "\n";
     
     
    //print multiplication table for the #'s 1-5
    //creation of second for loop counter variable.
    int b = 1;
    
    for (int a = 1; a <= 5; a++) {
        std::cout << a << "X*: ";
        for (b = 1; b <= 5; b++) {
            std::cout << a * b << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}
