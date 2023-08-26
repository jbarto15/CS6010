//
//  main.cpp
//  StringAnalyzer
//
//  Created by Josh Barton on 8/25/23.
//

#include <iostream>
#include <ctype.h>
#include <string>

//write functions
//bool IsTerminator(char c) - Returns whether or not the character is ., ?, or !.
bool isTerminator(char c) {
    //is character ., ?, or !.
    bool terminator = true;
    if (c == '.') {
        terminator = true;
    } else if (c == '?') {
        terminator = true;
    } else if (c == '!') {
        terminator = true;
    }
    return terminator;
}

//bool IsPunctuation(char c) - Returns whether or not the character is ., ?, !, or ,.
bool isPunctuation(char c) {
    bool punctuation = true;
    if (c == '.') {
        punctuation = true;
    } else if (c == '?') {
        punctuation = true;
    } else if (c == '!') {
        punctuation = true;
    } else {
        punctuation = false;
    }
    return punctuation;
}

//bool IsVowel(char c) - Returns whether or not the character is a vowel. For our purposes, always treat the character 'y' (and its uppercase version) as a vowel.

//When writing your IsVowel() function, be sure to check for uppercase and lowercase versions of each vowel. (Or better yet, before you check a letter, convert it to a lowercase letter.)
bool isVowel(char c) {
    //vowels == a, e, i, o, u, y.
    //check for a, e, i, o, u, and y in the sentence string.
    //use a for loop to
    for (int i = 65; i <= 121; i++) {
        if (c == 65 || c == 97 || c == 69 || c == 101 || c == 73 || c == 105 || c == 79 || c == 111 || c == 85 || c == 117 || c == 89 || c == 121) {
            return true;
        }
    }
    
    return false;
}

//bool IsConsonant(char c) - Returns whether or not the character is a consonant. DO NOT write code that checks if the character is equal to every consonant. In our simple sentences, there are four classifications of characters: spaces, punctuation, vowels, and consonants. If a character is not one of the first three, then it must be a consonant. Use the previous two functions as helpers to determine this. This function can be completed in one simple line of code.
bool isConsonant(char c) {
    if (c != isVowel(c) && c != isTerminator(c) && c != isPunctuation(c)) {
        return true;
    }
    return false;
}

//int NumWords(string s) - Returns the number of words in the string.
int numWords(std::string s) {
    int numberOfSpaces = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            numberOfSpaces += 1;
        }
    }
    int numberOfWords = numberOfSpaces + 1;
    return numberOfWords;
}

//int NumSentences(string s) - Returns the number of sentences in the string. This function can make use of the IsPunctuation helper.
int numSentences(std::string s) {
    if (isPunctuation(s))
}

//int NumVowels(string s) - Returns the number of vowels in the string. This function can make use of the IsVowel helper.
//int NumConsonants(string s) - Returns the number of consonants in the string. This function can make use of the IsConsonant helper.
//double AverageWordLength(string s) - Returns the average length of all words in the string. This function can make use of the IsVowel , IsConsonant , and NumWords helpers, as discussed in the Analysis section above.
//double AverageVowelsPerWord(string s) - Returns the average number of vowels per word in the string. This function can make use of the IsVowel and NumWords helpers, as discussed in the Analysis section above.



int main(int argc, const char * argv[]) {
    // insert code here...
    
    //Enter a string containing one or more sentences:
    std::cout << "Enter a string containing one or more sentences:\n";
    //std::string s = "how are you doing";
    //std::cout<< numWords(s);
    
    //Here is sentence number one. Here is sentence number two!
    //Analysis:
     //Number of words: 10
     //Number of sentences: 2
     //Number of vowels: 19
     //Number of consonants: 27
     //Reading level (average word length): 4.6
     //Average vowels per word: 1.9
    
    std::string input;
    std::getline( std::cin, input);
    // After the user types something and presses enter, the variable "input" will contain the line of text they typed.
    std::cout << "Number of Words: ";
    std::cout << numWords(input);
    
    
    return 0;
}

//In this assignment you will write a tool that analyzes sentences and reports various statistics about them. There will be a lot of common computation among some of the analyses performed, so you will need to write helper functions to reuse common code.

//Your program should repeatedly ask the user to input a string, then use the below functions to print various statistics about it. Assume each input string contains one or more sentences terminated with proper grammar (ends with '.', '?', or '!'). Assume the string only contains letters, spaces, commas, and the mentioned sentence terminators. Your program should terminate if the user types in "done".

//Important: Use the C++ function std::getline to read an entire string at once. Using cin >> ... will not work, because its default behavior is to stop on the first space character. The below code snippet illustrates how to use getline.
