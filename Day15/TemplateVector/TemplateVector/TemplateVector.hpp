//
//  TemplateVector.hpp
//  TemplateVector
//
//  Created by Josh Barton on 9/16/23.
//

#ifndef TemplateVector_hpp
#define TemplateVector_hpp

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
    int get(size_t position) const;
    void set(int value, size_t position) const;
    size_t getSize() const;
    size_t getCapacity() const;
    void print();
    
    
    
    //operators
    MyVector operator+(const MyVector& rhs);
    int& operator[](size_t index);
    MyVector& operator=(const MyVector& rhs);
    bool operator==(const MyVector& rhs) const;
    bool operator!=(const MyVector& rhs) const;
    bool operator<(const MyVector& rhs) const;
    bool operator<=(const MyVector& rhs) const;
    bool operator>=(const MyVector& rhs) const;
    bool operator>(const MyVector& rhs) const;
    
    
    //constructor
    MyVector(size_t capacity) {
        if (capacity > 0) {
            std::cout << "Hello from the constructor" << std::endl;
            _myArray = new int [capacity];
            _capacity = capacity;
            _size = 0;
        }
    }
    
    //constructor with no parameters
    MyVector() {
            _myArray = new int [_capacity];
            _capacity = 10;
            _size = 0;
    }
    
    //copy constructor
    MyVector(MyVector& vector) {
        _size = vector.getSize();
        _capacity = vector.getCapacity();
        _myArray = new int[_capacity];

        for(int i = 0; i < _size; i++) {
            _myArray[i] = vector._myArray[i];
        }
        
    }
    
    // Constructor that initializes the vector from a std::vector<int>
    MyVector(const std::vector<int>& data) {
        // Initialize the capacity and size based on the size of the input vector
        _capacity = data.size() * 2;
        _size = data.size();

        // Allocate memory for the internal array
        _myArray = new int[_capacity];

        // Copy the data from the input vector to the internal array
        for (size_t i = 0; i < _size; i++) {
            _myArray[i] = data[i];
        }
    }

    
    //destructor
    ~MyVector() {
        _size = 0;
        _capacity = 0;
        delete [] _myArray;
    
    }
};


//TEST FUNCTIONS
void testFreeVector(MyVector& vector);

void testPushBack(MyVector& vector);

void testPopBack(MyVector& vector);

void testGet(MyVector& vector);

void testSet(MyVector& vector);

void testGetSize(MyVector& vector);

void testGetCapacity(MyVector& vector);

void testPrint(MyVector& vector);

//OPERATOR TESTS

void testOperatorPlus(MyVector& vector1, MyVector& vector2, MyVector& vector3);

void testOperatorGet(MyVector& vector);

void testOperatorAssignment(MyVector& vector1, MyVector& vector2);

void testOperatorEquals(MyVector& vector1, MyVector& vector2);

void testOperatorDoesNotEqual(MyVector& vector1, MyVector& vector2);

void testOperatorLessThan(MyVector& vector1, MyVector& vector2);

void testOperatorLessThanOrEqual(MyVector& vector1, MyVector& vector2);

void testOperatorGreaterThanOrEqual(MyVector& vector1, MyVector& vector2);

void testOperatorGreaterThan(MyVector& vector1, MyVector& vector2);


#endif /* TemplateVector_hpp */
