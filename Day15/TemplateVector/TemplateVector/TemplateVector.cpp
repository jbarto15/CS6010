//
//  TemplateVector.cpp
//  TemplateVector
//
//  Created by Josh Barton on 9/16/23.
//

#include "TemplateVector.hpp"


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
int MyVector::get(size_t position) const {
    //check to see if the position is in the valid range of the size of the array. If not, crash the program
    if (position < _size && _myArray != nullptr) {
        //return the position in the array
        return _myArray[position];
    }
    else {
        return -1;
    }
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
void MyVector::print() {
    //go through the elements of the vector and print them
    for (int i = 0; i < _size; i++) {
        std::cout << "Element: " << _myArray[i] << std::endl;
    }
}



//OPERATORS

//operator plus function
MyVector operator+(const MyVector& lhs, const MyVector& rhs) {
    MyVector result;

    assert((lhs.getSize()) == (rhs.getSize()) && "Size mismatch in operator");
    size_t size = lhs.getSize();

    for (size_t i = 0; i < size; i++) {
        result.push_back(lhs.get(i) + rhs.get(i));
    }


    return result;
}


//operator plus function, concatenate {
MyVector MyVector::operator+(const MyVector& rhs) {
    if (rhs.getSize() == 0)
        return *this;
        
    // Create a new MyVector as a result of the concatenation
    MyVector result;

    // Copy the elements from the current object (this) to result
    for (int i = 0; i < getSize(); i++) {
        result.push_back(get(i));
    }

    // Copy the elements from rhs to result
    for (int i = 0; i < rhs.getSize(); i++) {
        result.push_back(rhs.get(i));
    }

    // Return a reference to the result
    return result;
}


//operator equals function
MyVector& MyVector::operator=(const MyVector& rhs) {
    //check to see if rhs and _myArray are the same
    if (this == &rhs) {
        return *this;
    }
    
    //create new memory for the new array
    if (_capacity < rhs._size) {
        delete [] _myArray;
        _myArray = new int [rhs._size];
        _capacity = rhs._size * 2;
    }
    
    //copy the data from rhs to _myArray
    _size = rhs._size;
        for (int i = 0; i < _size; i++) {
                _myArray[i] = rhs._myArray[i];
        }
    return *this;
}


//operator [] function, returns an address
int& MyVector::operator[](size_t index) {
    assert(index < _size && "Out of bounds in operator[]!");
    return _myArray[index];
}


//equals operator
bool MyVector::operator==(const MyVector& rhs) const {
    // Check if sizes of the vectors are equal
        if (_size != rhs._size) {
            return false;
        }
    //check if each element in the vector is the same
    for (int i = 0; i < _size; i++) {
        if (_myArray[i] != rhs._myArray[i]) {
            return false;
        }
    }
    return true;
}


//does not equal operator
bool MyVector::operator!=(const MyVector& rhs) const {
    // Check if sizes of the vectors are not equal
        if (_size != rhs._size) {
            return true;
        }
    
    //check if each element in the vector is not the same
    for (int i = 0; i < _size; i++) {
        if (_myArray[i] != rhs._myArray[i]) {
            return true;
        }
    }
    return false;
}


//less than operator
bool MyVector::operator<(const MyVector& rhs) const {
    // Check if sizes of the vectors are not equal
        if (_size != rhs._size) {
            return false;
        }
    
    //check if each element in the vector is not the same
    for (int i = 0; i < _size; i++) {
        if (_myArray[i] < rhs._myArray[i]) {
            return true;
        }
        else if (_myArray[i] > rhs._myArray[i]) {
                return false;
            }
    }
    return false;
}


//less than or equal to
bool MyVector::operator<=(const MyVector& rhs) const {
    // Check if sizes of the vectors are not equal
        if (_size != rhs._size) {
            return false;
        }
    
    //check if each element in the vector is not the same
    for (int i = 0; i < _size; i++) {
        if (_myArray[i] < rhs._myArray[i] || _myArray[i] == rhs._myArray[i]) {
            return true;
        }
        else if (_myArray[i] > rhs._myArray[i]) {
                return false;
            }
    }
    return false;
}


//operator greater than or equal to
bool MyVector::operator>=(const MyVector& rhs) const {
    // Check if sizes of the vectors are not equal
        if (_size != rhs._size) {
            return false;
        }
    
    //check if each element in the vector is not the same
    for (int i = 0; i < _size; i++) {
        if (_myArray[i] > rhs._myArray[i] || _myArray[i] == rhs._myArray[i]) {
            return true;
        }
        else if (_myArray[i] < rhs._myArray[i]) {
                return false;
            }
    }
    return false;
}


//operator greater than
bool MyVector::operator>(const MyVector& rhs) const {
    // Check if sizes of the vectors are not equal
        if (_size != rhs._size) {
            return false;
        }
    
    //check if each element in the vector is not the same
    for (int i = 0; i < _size; i++) {
        if (_myArray[i] > rhs._myArray[i]) {
            return true;
        }
        else if (_myArray[i] < rhs._myArray[i]) {
                return false;
            }
    }
    return false;
}
