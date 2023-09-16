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
    
    v3 = v2 + v1;
    
    std::cout << "v2 contents: " << std::endl;
    v2.print();
    
    std::cout << "v1 contents: " << std::endl;
    v1.print();
    
    
    //test operator plus
    testOperatorPlus(v1, v2);
    
    //test operator get value
    testOperatorGet(v1);
    
    //test operator assignment
    testOperatorAssignment(v1, v3);
    
    //test operator equals
    testOperatorEquals(v1, v2);
    
    //test operator does not equal
    testOperatorDoesNotEqual(v1, v3);
    
    
    
    return 0;
}
