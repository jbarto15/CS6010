//
//  LetterHelpers.cpp
//  StringAnalyzer
//
//  Created by Josh Barton on 8/28/23.
//

#include "LetterHelpers.hpp"

//write functions
//bool IsTerminator(char c) - Returns whether or not the character is ., ?, or !
bool isTerminator(char c) {
    //is character ., ?, or !.
    bool terminator = true;
    if (c == '.') {
        terminator = true;
    } else if (c == '?') {
        terminator = true;
    } else if (c =='!') {
        terminator = true;
    } else {
        return false;
    }
    return terminator;
}

//bool IsPunctuation(char c) - Returns whether or not the character is ., ?, !, or ,
bool isPunctuation(char c) {
    bool punctuation = true;
    if (c == '.') {
        punctuation = true;
    } else if (c == '?') {
        punctuation = true;
    } else if (c == '!') {
        punctuation = true;
    } else if (c == ',') {
        punctuation = true;
    } else {
        punctuation = false;
    }
    return punctuation;
}

//bool IsVowel(char c) - Returns whether or not the character is a vowel. For our purposes, always treat the character 'y' (and its uppercase version) as a vowel.

//When writing your IsVowel() function, be sure to check for uppercase and lowercase versions of each vowel. (Or better yet, before you check a letter, convert it to a lowercase letter.)
bool isVowel(char c) {
//for (int i = 65; i <= 121; i++) {
        if (c == 65 || c == 97 || c == 69 || c == 101 || c == 73 || c == 105 || c == 79 || c == 111 || c == 85 || c == 117 || c == 89 || c == 121) {
            return true;
        }
 //   }
    
    return false;
}

//bool IsConsonant(char c) - Returns whether or not the character is a consonant. DO NOT write code that checks if the character is equal to every consonant. In our simple sentences, there are four classifications of characters: spaces, punctuation, vowels, and consonants. If a character is not one of the first three, then it must be a consonant. Use the previous two functions as helpers to determine this. This function can be completed in one simple line of code.
bool isConsonant(char c) {
    if (!isVowel(c) && !isTerminator(c) && !isPunctuation(c) && c != ' ') {
        return true;
    }
    return false;
}
