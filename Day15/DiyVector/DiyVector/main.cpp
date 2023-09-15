//
//  main.cpp
//  DiyVector
//
//  Created by Josh Barton on 9/12/23.
//

#include <iostream>
#include "DiyVector.hpp"

int main(int argc, const char * argv[]) {
    
    //test for push back method
    MyVector v1(10);
    v1.push_back(3);
    v1.push_back(6);
    v1.push_back(12);
    
    //use print method to see if the element is getting pushed back
    v1.printVector(v1);
    
    //test for pop back method
    v1.pop_back();
    
    v1.printVector(v1);
    
    v1.push_back(7);
    
    v1.printVector(v1);
    
    
    //test for get method
    std::cout << "Element 0 of vector: " << v1.get(2, 0) << std::endl;
    
    std::cout << "Element 1 of vector: " << v1.get(2, 1) << std::endl;
    
    
    //test for set method
    v1.set(198, 2);
    
    v1.printVector(v1);
    
    
    return 0;
}
