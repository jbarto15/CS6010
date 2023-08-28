//
//  WordHelpers.hpp
//  StringAnalyzer
//
//  Created by Josh Barton on 8/28/23.
//

#ifndef WordHelpers_hpp
#define WordHelpers_hpp

#include <stdio.h>
#include <string>

#endif /* WordHelpers_hpp */

//int NumWords(string s) - Returns the number of words in the string.
int numWords(std::string s);


//int NumSentences(string s) - Returns the number of sentences in the string. This function can make use of the IsPunctuation helper.
int numSentences(std::string s);


//int NumVowels(string s) - Returns the number of vowels in the string. This function can make use of the IsVowel helper.
int numVowels(std::string s);


//int NumConsonants(string s) - Returns the number of consonants in the string. This function can make use of the IsConsonant helper.
int numConsonants(std::string s);


//double AverageWordLength(string s) - Returns the average length of all words in the string. This function can make use of the IsVowel , IsConsonant , and NumWords helpers, as discussed in the Analysis section above.
double averageWordLength(std::string s);


//double AverageVowelsPerWord(string s) - Returns the average number of vowels per word in the string. This function can make use of the IsVowel and NumWords helpers, as discussed in the Analysis section above.
double averageVowelsPerWord(std::string s);
