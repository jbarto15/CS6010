
#include <iostream>
#include "VectorUtil.h"
#include <algorithm>

//function that determines whether or not a vector contains a certain item
bool Contains( vector<int> input, int lookFor )
{
  // returns true if input contains the value lookFor, and false otherwise.
    for (int value: input) {
        if (lookFor == value) {
            return true;
        }
    }
  return false;
}


//function that determines the minimum value in a vector
int FindMin( vector<int> input )
{
    int minNumber = input[0];
    for (int value: input) {
        if (value < minNumber) {
            minNumber = value;
        }
    }
  return minNumber;
}


//function that determines the maximum value in a vector
int FindMax( vector<int> input ){
    int maxNumber = input[0];
    for (int value: input) {
        if (value > maxNumber) {
            maxNumber = value;
        }
    }
    return maxNumber;
}


//function that determines the average of all values in a vector
int Average( vector<int> input )
{
    float additionOfVectorValues = 0;
    for (int value: input) {
        additionOfVectorValues = additionOfVectorValues + value;
    }
    float averageOfVectorValues = additionOfVectorValues / input.size();
    std::cout << averageOfVectorValues << std::endl;
  return averageOfVectorValues;
}


//function that determines whether or not a vector is sorted in non-descending order
bool IsSorted( vector<int> input )
{
    vector<int> input2 = {};
    input2.assign(input.begin(), input.end());
    std::sort(input.begin(), input.end());
    if (input == input2) {
        return true;
    }
  return false;
}


