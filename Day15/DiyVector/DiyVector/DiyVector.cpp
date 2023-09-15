//
//  DiyVector.cpp
//  DiyVector
//
//  Created by Josh Barton on 9/12/23.
//

#include "DiyVector.hpp"


//method that will delete the data in the array
void MyVector::freeVector(MyVector& vector) {
    delete [] vector._myArray;
}


//method that will push back a value in the vector
void MyVector::push_back(int value) {
    //check if size + 1 == capacity, if so, increase the capacity * 2
    if (_size + 1 >= _capacity) {
        growVector();
    }
    
    //assign the value they give to us to be the last element in the vector
    _myArray[_size] = value;
    _size ++;
}


//method that will take the last element of the vector and delete it
void MyVector::pop_back() {
    //take away the last element by decreasing the size of the vector by 1
    _size--;
}


//method that gets a value from the vector
int MyVector::get(int value, size_t position) const {
    //check to see if the position is in the valid range of the size of the array. If not, crash the program
    assert(position < _size);
    //check to see if the data array pointer is not null. If it is null, crash the program
    assert(_myArray != nullptr);
    
    //return the positoin in the array
    return _myArray[position];
}


//method that sets a specific position in the vector to a new value
void MyVector::set(int value, size_t position) const {
    //check to see if the position is a valid position
    if (position > 0 && position < _size) {
        //if the position is valid we want to assign that value to the appropriate position in the vector
        _myArray[position] = value;
    }
}


//method that grows the vector
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


//method that gets the size of the vector
size_t MyVector::getSize() const {
    //simply return the size of the vector
    return _size;
}


//method that gets the capacity of the vector
size_t MyVector::getCapacity() const {
    //simply return the size of the vector
    return _capacity;
}


//method that prints the contents of the vector
void MyVector::printVector(MyVector& vector) const {
    //go through the elements of the vector and print them
    for (int i = 0; i < _size; i++) {
        std::cout << "Element: " << _myArray[i] << std::endl;
    }
}



//OPERATORS

//operator plus function
MyVector operator+(const MyVector& lhs, const MyVector& rhs) {
    MyVector result;
    
    
    return result;
}
