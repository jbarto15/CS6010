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
    int get(int value, size_t position) const;
    void set(int value, size_t position) const;
    size_t getSize() const;
    size_t getCapacity() const;
    void printVector(MyVector& vector) const;
    
    
    //constructor
    MyVector(size_t capacity) {
        if (capacity > 0) {
            std::cout << "Hello from the constructor" << std::endl;
            _myArray = new int [capacity];
            _capacity = capacity;
            _size = 0;
        }
    }
    
    //additional constructor that gives it an array of data
    MyVector(int* data) {
        if (_capacity > 0) {
            std::cout << "Hello from the array constructor" << std::endl;
            _myArray = data;
            _capacity = 10;
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


MyVector operator+(const MyVector& lhs, const MyVector& rhs);


#endif /* DiyVector_hpp */
