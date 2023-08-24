//
//  main.cpp
//  Palindromes
//
//  Created by Josh Barton on 8/24/23.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //Part 1 - Palindromes by Josh Barton
    
    //creation of variables
    std::string originalWord;
    std::string reversed = "";
    std::string wordIsAPalindrome = " IS a palindrome.\n";
    std::string wordIsNotAPalindrome = " is NOT a palindrome.\n";
    
    //Prompt user to enter a word and get their answer.
    std::cout << "Enter a word: ";
    std::cin >> originalWord;
    
    //build the reversed string one character at a time using a loop
    for (int i = originalWord.length()-1; i >= 0; i--) {
        reversed = reversed + originalWord[i];
    }
    //std::cout << reversed;
    
    //Print original string; check if the reversed string is equal to the original string followed by whether or not it's a palindrome.
    std::cout << originalWord << std::endl;
    if (reversed == originalWord) {
        std::cout << originalWord + wordIsAPalindrome;
    } else {
        std:: cout << originalWord + wordIsNotAPalindrome;
    }
    
    
    //Andrew Delis Part 2
    //Created the input variable that will be a single string.
    //Also created a boolean that will be used to check if the input
    //was in the correct format.
    std::string input;
    bool correctFormat;
    std::string inputDay;
    int day;
    int month = 0;
    int year;
    std::string inputMonth;
    std::string inputYear;

    //creating the prompt using the string variable we just created
    std::cout << " Enter a date: (mm/dd/yyyy)" << "\n";
    std::cin >> input;
    
    
    //used an if statement to make sure a date in correct format (mm/dd/yyyy) is entered
    //used an if statement to output a message if they did not enter the correct format
    if (input.length() == 10) {
        correctFormat = true;
      }
      else {
        correctFormat = false;
      }
      if (correctFormat != true) {
          std::cout << "Please enter a valid date." << "\n";
      }
      //separating the individual characters for the day, month, and year out
      //assigning those new values to new variables
      inputMonth = input.substr(0,2);
      inputDay = input.substr(3,2);
      inputYear = input.substr(6,4);
      //converting the month from numeric strings into word strings
      if (inputMonth == "01") {
        inputMonth = "January ";
      }
      else if (inputMonth == "02"){
        inputMonth = "February ";
      }
      else if (inputMonth == "03"){
        inputMonth = "March ";
      }
      else if (inputMonth == "04"){
        inputMonth = "April ";
      }
      else if (inputMonth == "05"){
        inputMonth = "May ";
      }
      else if (inputMonth == "06"){
        inputMonth = "June ";
      }
      else if (inputMonth == "07"){
        inputMonth = "July ";
      }
      else if (inputMonth == "08"){
        inputMonth = "August ";
      }
      else if (inputMonth == "09"){
        inputMonth = "September ";
      }
      else if (inputMonth == "10"){
        inputMonth = "October ";
      }
      else if (inputMonth == "11"){
        inputMonth = "November ";
      }
      else if (inputMonth == "12"){
        inputMonth = "December ";
      }
      else {
        std::cout << "Please enter a valid date." << "\n";
      }
      //converting the numeric string for the day of the month into an integer
      //and making sure it is a valid day of the month (not in the most precise way though)
      day = std::stoi(inputDay);
      if ( day < 1 || day > 31) {
        std::cout << "Please enter a valid date." << "\n";
      }
      //outputs
      std::cout << inputMonth << std::stoi(inputDay) << ", " << inputYear << "\n";
    
    
    
    
    
    //Part 2.5 - Magic Dates
    
    //new variables for the magic dates part
    std::string lastTwoDigitsOfYear = inputYear.substr(2,2);
    
    
    //convert last two digits of year to an integer.
    year = std::stoi(lastTwoDigitsOfYear);
    
    //creating the prompt using the string variable we just created
    std::cout << " Enter a date: (mm/dd/yyyy)" << "\n";
    std::cin >> input;
    
    
    //used an if statement to make sure a date in correct format (mm/dd/yyyy) is entered
    //used an if statement to output a message if they did not enter the correct format
    if (input.length() == 10) {
        correctFormat = true;
      }
      else {
        correctFormat = false;
      }
      if (correctFormat != true) {
          std::cout << "Please enter a valid date." << "\n";
      }
    
    
      //separating the individual characters for the day, month, and year out
      //assigning those new values to new variables
      inputMonth = input.substr(0,2);
      inputDay = input.substr(3,2);
      inputYear = input.substr(6,4);
      //converting the month from numeric strings into word strings
      if (inputMonth == "01") {
        inputMonth = "January ";
      }
      else if (inputMonth == "02"){
        inputMonth = "February ";
      }
      else if (inputMonth == "03"){
        inputMonth = "March ";
      }
      else if (inputMonth == "04"){
        inputMonth = "April ";
      }
      else if (inputMonth == "05"){
        inputMonth = "May ";
      }
      else if (inputMonth == "06"){
        inputMonth = "June ";
      }
      else if (inputMonth == "07"){
        inputMonth = "July ";
      }
      else if (inputMonth == "08"){
        inputMonth = "August ";
      }
      else if (inputMonth == "09"){
        inputMonth = "September ";
      }
      else if (inputMonth == "10"){
        inputMonth = "October ";
      }
      else if (inputMonth == "11"){
        inputMonth = "November ";
      }
      else if (inputMonth == "12"){
        inputMonth = "December ";
      }
      else {
        std::cout << "Please enter a valid date." << "\n";
      }
    
    if (day * month == year) {
        std::cout << input << " IS a magic date.\n";
    } else {
        std::cout << input << " is NOT a magic date.\n";
    }
    
    return 0;
}
