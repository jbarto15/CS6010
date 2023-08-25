//
//  main.cpp
//  FunctionPractice
//
//  Created by Josh Barton on 8/25/23.
//

#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

//Part 2 is first so that my functions are at the top
//Part 2 - Writing Our Own Functions

//creation of hypotenuse function that takes the two sides of a right triangle. Side1 and Side2. It will return the hypotenuse length. You wouldn't want to get the input from std::cin inside your function because the function is for the Engineer and not the user. The user will input things but we'll do that inside of main.
float calculateHypotenuseLength(float side1, float side2) {
    float hypotenuseSquared = (side1 * side1) + (side2 * side2);
    float hypotenuseLength = std::sqrt(hypotenuseSquared);
    
    return hypotenuseLength;
}

//it would be difficult to turn the speed/velocity task into a function because you would have to return more than one value. The x velocity and the y velocity. I think an imperfect solution would be to write one function that returns the x velocity and one that returns the y velocity

//Write a function isCapitalized that takes in a string parameter and returns whether or not the string starts with a capital letter.

bool isCapitalized(std::string userString) {
    bool stringCapitalized;
    char firstLetter;
    firstLetter = userString.front();
    if (firstLetter >= 65 && firstLetter <= 90) {
        stringCapitalized = true;
    } else {
        stringCapitalized = false;
    }
    return stringCapitalized;
}

//Write a function boolToString that takes in a Boolean parameter and returns the string "true" or "false" depending on its value. Use this function to display the results of testing the isCapitalized function.

void boolToString(bool isCapitalizedResult) {
    if (isCapitalizedResult) {
        std::cout << "Your sentence starts with a capital.\n";
    } else {
        std::cout << "Your sentence DOES NOT start with a capital.\n";
    }
}

//Challenge question: write a function called isPrime that takes an integer and returns whether or not it's a prime number

//use a for loop and use a counter as the number that is being divided by. In the loop I should write an if statement that checks if the user number is divisible by 2, 3, 4 , 5 and so on. If it is divisible by 2 then it will say the number is not a prime number and then break out of the loop. right an else statement outside of the loop that says it is a prime number. if it's divisible by 1 and the counter number it is prime.

bool isPrime(int number) {
    int numberDividedByTwo = number / 2;
    if (number == 0) {
        return false;
    } else if (number == 1) {
        return true;
    }
    for (int i = 2; i <= numberDividedByTwo; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    //Part 1 - Practice Calling Functions
    
    // a)
    
    //create side 1 and side 2 variables
    float side1;
    float side2;
    float hypotenuseLength;
    float hypotenuseSquared;
    
    //ask the user to enter the right-angle side lengths of a triangle and then print the length of the hypotenuse
    std::cout<< "Please enter the right-angle side lengths of a triangle.\n" << "Side 1: ";
    std::cin >> side1;
    std::cout << "Side 2: ";
    std::cin >> side2;
    
    //assign hypotenuseSquared variable to side1^2 and side2^2
    hypotenuseSquared = (side1 * side1) + (side2 * side2);
    
    //call the sqrt function so I can find the square root of hypotenuseSquared. Then print the hypotenuse length
    hypotenuseLength = std::sqrt(hypotenuseSquared);
    std::cout << "Hypotenuse Length: ";
    std::cout << hypotenuseLength << std::endl;
    
    
    // b)
    
    //create variables
    double userSpeed;
    double userAngle;
    double xVelocity;
    double yVelocity;
    
    //ask the user to input the speed they're going (a double) and the angle they're going in (a double)
    std::cout << "What speed are you traveling?\n";
    std::cin >> userSpeed;
    std::cout << "At what angle are you traveling?\n";
    std::cin >> userAngle;
    
    //use the std::cos and std::sin functions and the formulas x = speed*cos(angle), y = speed*sin(angle) to print out their x and y velocity.
    xVelocity = userSpeed * (std::cos(userAngle));
    yVelocity = userSpeed * (std::sin(userAngle));
    
    std::cout << xVelocity << std::endl << yVelocity << std::endl;
    
    // c)
    
    //code copied
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result))
                 << result << " seconds since the Epoch\n";
    //The functions being called in the above code are std::time as well as std::asctime and std::localtime.
    
    std::cout << calculateHypotenuseLength(2, 4);
    std::cout << "\n";
    
    
    //create variable for userString
    std::string userString;
    
    //Ask user to input a string
    std::cout << "Please type a sentence: ";
    std::cin >> userString;
    
    //print out whether or not the sentence started with a capital or not using the boolToString function.
    boolToString(isCapitalized(userString));
    
    //for the isPrime part. Call isPrime and pass a number to it. Also print a statement for it to ask the user for a number.
    //create number variable
    int number;
    std::cout << "Please enter a number: ";
    std::cin >> number;
    
    //place the function into a variable so I can print it in the console.
    bool isPri = isPrime(number);
    if (isPri) {
        std::cout << "Your number is prime.\n";
    } else {
        std::cout << "Your number is NOT prime.\n";
    }
    
    
    return 0;
}



