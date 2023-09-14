//
//  DiyVector.cpp
//  DiyVector
//
//  Created by Josh Barton on 9/12/23.
//

#include "DiyVector.hpp"


void MyVector::freeVector(MyVector& vector) {
    delete [] vector._myArray;
}

void MyVector::pushBack(int value) {
    //check if size + 1 == capacity, if so, increase the capacity * 2
    if (_size + 1 == _capacity) {
        growVector();
    }
    
    _myArray[_size] = value;
    _size ++;
}

MyVector MyVector::popBack(MyVector& vector) {
    
    
}

int MyVector::get(MyVector& vector, int index) {
    
}

int MyVector::set(MyVector& vector, int index) {
    
}

void MyVector::growVector() {
    //create a new array (temp) on the heap for the new vector
    int* temp = new int [_capacity * 2];
    
    //copy myArray into temp
    for (int i = 0; i < _size; i++) {
        temp[i] = _myArray[i];
    }
    
    //delete the first array so that we don't leak data
    delete [] _myArray;
    
    //point data at whatever temp is pointing at
    _myArray = temp;
    
    //set temp to null so that it's not a dangling pointer
    temp = nullptr;
    
    //update capacity
    _capacity *= 2;
    
}

size_t MyVector::getSize() {
    return _size;
}

size_t MyVector::getCapacity(MyVector& vector) {
    return _capacity;
}
