//
//  WordHelpers.cpp
//  StringAnalyzer
//
//  Created by Josh Barton on 8/28/23.
//

#include "WordHelpers.hpp"
#include <string>
#include "LetterHelpers.hpp"

//int NumWords(string s) - Returns the number of words in the string.
int getNumWords(std::string s) {
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
int getNumSentences(std::string s) {
    int numberOfSentences = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isTerminator(s[i])) {
            numberOfSentences += 1;
        }
    }
    return numberOfSentences;
}

//int NumVowels(string s) - Returns the number of vowels in the string. This function can make use of the IsVowel helper.
int getNumVowels(std::string s) {
    int numberOfVowels = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isVowel(s[i])) {
            numberOfVowels += 1;
        }
    }
    return numberOfVowels;
}
//int NumConsonants(string s) - Returns the number of consonants in the string. This function can make use of the IsConsonant helper.
int getNumConsonants(std::string s) {
    int numberOfConsonants = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isConsonant(s[i])) {
            
            numberOfConsonants += 1;
        }
    }
    return numberOfConsonants;
}

//double AverageWordLength(string s) - Returns the average length of all words in the string. This function can make use of the IsVowel , IsConsonant , and NumWords helpers, as discussed in the Analysis section above.
double calculateAverageWordLength(std::string s) {
    int numberOfVowels = getNumVowels(s);
    int numberOfConsonants = getNumConsonants(s);
    int numberOfWords = getNumWords(s);
    double averageWordLength = (numberOfVowels + numberOfConsonants) / numberOfWords;
    
    return averageWordLength;
}

//double AverageVowelsPerWord(string s) - Returns the //average number of vowels per word in the string. This //function can make use of the IsVowel and NumWords //helpers, as discussed in the Analysis section above.
double calculateAverageVowelsPerWord(std::string s) {
    int numberOfVowels = getNumVowels(s);
    int numberOfWords = getNumWords(s);
    double averageVowelsPerWord = numberOfVowels / numberOfWords;
    
    return averageVowelsPerWord;
}


/*when naming functions, it's helpful to name them as actions. So for example: countNumOfWords is better than numOfWords because it tells you what the function is doing. */
