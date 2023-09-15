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
    
    
    
    return 0;
}
