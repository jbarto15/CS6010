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
    void pop_back();
    int get(int value, size_t position);
    void set(int value, size_t position);
    size_t getSize();
    size_t getCapacity();
    
    
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


#endif /* DiyVector_hpp */
