//
//  main.cpp
//  DiyVector
//
//  Created by Josh Barton on 9/12/23.
//

#include <iostream>
#include "DiyVector.hpp"

int main(int argc, const char * argv[]) {
    
    //create an object of MyVector
    MyVector v1(10);
    
    //create an object of MyVector sending in a vector of data
    std::vector<int> data1 = {3, 6, 12, 198};
    MyVector v4(data1);
    
    std::vector<int> data2 = {3, 4, 12, 198};
    MyVector v5(data2);
    
    
    //test for push back method
    testPushBack(v1);
    
    //test print method
    testPrint(v1);
    
    //test for pop back method
    testPopBack(v1);
    
    
    //test for get method
    testGet(v1);
    
    
    //test for set method
    testSet(v1);
    
    
    //use the copy constructor
    MyVector v2(v1);
    
    MyVector v3;
    
    
    //test operator plus
    testOperatorPlus(v1, v2);
    
    //test operator get value
    testOperatorGet(v4);
    
    //test operator assignment
    testOperatorAssignment(v1, v3);
    
    //test operator equals
    testOperatorEquals(v1, v2);
    
    //test operator does not equal
    testOperatorDoesNotEqual(v5, v4);
    
    //test operator less than
    testOperatorLessThan(v5, v4);
    
    //test operator less than or equal to
    testOperatorLessThanOrEqual(v4, v4);
    
    //test operator greater than or equal to
    testOperatorGreaterThanOrEqual(v5, v4);
    
    //test operator greater than
    testOperatorGreaterThan(v4, v5);
    
    
    
    return 0;
}
