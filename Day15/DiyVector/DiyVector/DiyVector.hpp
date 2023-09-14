//
//  DiyVector.hpp
//  DiyVector
//
//  Created by Josh Barton on 9/12/23.
//

#ifndef DiyVector_hpp
#define DiyVector_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <cassert>
#include <iostream>

class MyVector {
private:
    int* _myArray;
    size_t _size, _capacity;
    void growVector();
    
public:
    void freeVector(MyVector& vector);
    void push_back(int value);
    void pop_back(int value);
    int get(int value, size_t position);
    void set(int value, size_t position);
    size_t getSize();
    size_t getCapacity(MyVector& vector);
    
    
    //constructor
    MyVector(size_t capacity) {
        if (capacity > 0) {
            std::cout << "Hello from the constructor" << std::endl;
            _myArray = new int [capacity];
            _capacity = capacity;
            _size = 0;
        }
    }
    
    //destructor
    ~MyVector() {
        std::cout << "Hello from the destructor" << std::endl;
        _size = 0;
        _capacity = 0;
        delete [] _myArray;
    }
    
    

};

//makeVector(initialCapacity ) -- should return a vector with the given capacity and a size of 0
//std::vector<int> makeVector(

//freeVector(MyVec) -- should deallocate any heap memory used by the MyVector object
//pushBack and popBack -- should work like they do for std::vector. Since these are functions, and not "methods" like std::vector uses, the syntax for calling them will be slightly different. For example, you might write pushBack(myVector, 5);
//get(myVec, index) -- return the appropriate value in the vector. This should work like [] does for std::vectors
//set(myVec, index, newValue) -- set the appropriate value in the vector. This should work like [] for std::vector when they're on the left of an equals sign (vec[3] = 10;).
//growVector(myVec) -- should double the capacity of the vector. The values should be copied from the old array to the new array


#endif /* DiyVector_hpp */
