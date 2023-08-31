

#include <iostream>
#include <string>
#include "VectorUtil.h"

/*
 * Helper function for failing a test.
 * Prints a message and exits the program.
 */
void ErrorExit( std::string message )
{
  std::cerr << "Failed test: " << message << std::endl;
  exit(1); // Causes the entire program to exit.
}


int main()
{
  
  // Set up some input vectors for testing purposes.

  // We can use list initialization syntax:
  vector<int> v1 = {3, 1, 0, -1, 5};

  // Or we can repeatedly push_back items
  vector<int> v2;
  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(3);

  // When testing, be sure to check boundary conditions, such as an empty vector
  vector<int> empty;
  
  
  /* 
   * Contains tests 
   */

  // v1 doesn't contain 4, so this should return false
  if( Contains(v1, 4) ) {
    ErrorExit( "Contains() - test 1" );
  }

  // v1 does contain -1, so this should return true
  if(!Contains(v1, -1)) {
    ErrorExit("Contains() - test 2");
  }

  /* 
   * The vector 'empty' doesn't contain anything, so this should return false
   * The specific value we're looking for here (99) is not important in this test. 
   * This test is designed to find any general errors caused by the array being empty. 
   * That type of error is unlikely to depend on the value we are looking for.
  */
  if( Contains(empty, 99) ) {
    ErrorExit("Contains() - empty");
  }

  
  //test for if the FindMin function is sorting properly
    if (FindMin(v1) != -1) {
        ErrorExit("FindMin() - not sorting correctly");
    }
  //testing if minimum of v2 is correct
    if (FindMin(v1) != -1) {
        ErrorExit("FindMin() is incorrect");
    }
  //test if the FindMax function is sorting correctly
    if (FindMax(v1) == 3) {
        ErrorExit("FindMax() - not sorting correctly");
    }
  
  //testing if maximum of v1 is correct
    if (FindMax(v1) != 5) {
        ErrorExit("FindMax() is incorrect");
    }
    
  //tests for the average function
    if (Average(v2) != 2) {
        ErrorExit("Average() - not computing average correctly");
    }
    
    if (Average(v1) == 2) {
        ErrorExit("Average() - not computing average correctly");
    }
    
    if (Average(v1) == 0) {
        ErrorExit("Average() - not computing average correctly");
    }
    
    if (Average(v2) == 0) {
        ErrorExit("Average() - not computing average correctly");
    }
    
  //Error message that prints whether or not v2 is sorted or not. If it is not sorted it will display the error message.
    if (!IsSorted(v2)) {
        ErrorExit("isSorted() - false");
    }
  //Error message that checks if v1 is sorted. If it is sorted then an error message will pop up. If not, the error message will not display
    if (IsSorted(v1)) {
        ErrorExit("isSorted() - false");
    }

  //Since any failed test exits the program, if we made it this far, we passed all tests.
  std::cout << "All tests passed!\n";

  
    Average(v1);
    std::cout << IsSorted(v2) << std::endl;
    std::cout << FindMin(v1) << std::endl;
    std::cout << FindMax(v1) << std::endl;
}
