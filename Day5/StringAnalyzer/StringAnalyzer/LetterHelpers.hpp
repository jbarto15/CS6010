//
//  LetterHelpers.hpp
//  StringAnalyzer
//
//  Created by Josh Barton on 8/28/23.
//

#ifndef LetterHelpers_hpp
#define LetterHelpers_hpp

#include <stdio.h>
#include <string>

#endif /* LetterHelpers_hpp */

//bool IsTerminator(char c) - Returns whether or not the character is ., ?, or !.
bool isTerminator(char c);


//bool IsPunctuation(char c) - Returns whether or not the character is ., ?, !, or ,.
bool isPunctuation(char c);


//bool IsVowel(char c) - Returns whether or not the character is a vowel. For our purposes, always treat the character 'y' (and its uppercase version) as a vowel.
bool isVowel(char c);


//bool IsConsonant(char c) - Returns whether or not the character is a consonant. DO NOT write code that checks if the character is equal to every consonant. In our simple sentences, there are four classifications of characters: spaces, punctuation, vowels, and consonants. If a character is not one of the first three, then it must be a consonant. Use the previous two functions as helpers to determine this. This function can be completed in one simple line of code.
bool isConsonant(char c);
