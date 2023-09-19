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

template<typename T>
class MyVector {
private:
    T* _myArray;
    size_t _size, _capacity;
    void growVector();
    
public:
    void freeVector(MyVector<T>& vector);
    void push_back(T value);
    void pop_back();
    T get(size_t position) const;
    void set(T value, size_t position);
    size_t getSize() const;
    size_t getCapacity() const;
    void print();
    
    
    
    //operators
    MyVector<T> operator+(const MyVector<T>& rhs);
    T& operator[](size_t index);
    MyVector<T>& operator=(const MyVector<T>& rhs);
    bool operator==(const MyVector<T>& rhs) const;
    bool operator!=(const MyVector<T>& rhs) const;
    bool operator<(const MyVector<T>& rhs) const;
    bool operator<=(const MyVector<T>& rhs) const;
    bool operator>=(const MyVector<T>& rhs) const;
    bool operator>(const MyVector<T>& rhs) const;
    
    //lab iterators
    T* begin() {
        return _myArray;
    }
    
    T* end() {
        return _myArray + _size;
    }
    
    const T* begin() const {
        return _myArray;
    }
    
    const T* end() const {
        return _myArray + _size;
    }
    
    //constructor
    MyVector(size_t capacity) {
        if (capacity > 0) {
            std::cout << "Hello from the constructor" << std::endl;
            _myArray = new T [capacity];
            _capacity = capacity;
            _size = 0;
        }
    }
    
    //constructor with no parameters
    MyVector() {
            _capacity = 10;
            _myArray = new T [_capacity];
            _size = 0;
    }
    
    //copy constructor
    MyVector(MyVector& vector) {
        _size = vector.getSize();
        _capacity = vector.getCapacity();
        _myArray = new T[_capacity];

        for(int i = 0; i < _size; i++) {
            _myArray[i] = vector._myArray[i];
        }
        
    }
    
    // Constructor that initializes the vector from a std::vector<int>
    MyVector(const std::vector<T>& data) {
        //Initialize the capacity and size based on the size of the input vector
        _capacity = data.size() * 2;
        _size = data.size();

        //Allocate memory for the internal array
        _myArray = new T[_capacity];

        //Copy the data from the input vector to the internal array
        for (size_t i = 0; i < _size; i++) {
            _myArray[i] = data[i];
        }
    }

    
    //destructor
    ~MyVector() {
        _size = 0;
        _capacity = 0;
        delete [] _myArray;
        _myArray = nullptr;
    
    }
};


template<typename T>
//method that will push back a value in the vector
void MyVector<T>::push_back(T value) {
    //check if size + 1 == capacity, if so, increase the capacity * 2
    if (_size + 1 >= _capacity) {
        growVector();
    }
    
    //assign the value they give to us to be the last element in the vector
    _myArray[_size] = value;
    _size ++;
}


template<typename T>
//method that will take the last element of the vector and delete it
void MyVector<T>::pop_back() {
    //check if vector size is not zero
    if (_size > 0) {
        //take away the last element by decreasing the size of the vector by 1
        _size--;
    }
}


template<typename T>
//method that gets a value from the vector
T MyVector<T>::get(size_t position) const {
    //check to see if the position is in the valid range of the size of the array. If not, crash the program
    if (position < _size && _myArray != nullptr) {
        //return the position in the array
        return _myArray[position];
    }
    else {
        std::cout<< "Invalid Position" << std::endl;
        exit(1);
    }
}


template<typename T>
//method that sets a specific position in the vector to a new value
void MyVector<T>::set(T value, size_t position) {
    //check to see if the position is a valid position
    if (position > 0 && position < _size) {
        //if the position is valid we want to assign that value to the appropriate position in the vector
        _myArray[position] = value;
    }
}


template<typename T>
//method that grows the vector
void MyVector<T>::growVector() {
    //create a new array (temp) on the heap for the new vector
    int* temp = new T [_capacity * 2];
    
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


template<typename T>
//method that gets the size of the vector
size_t MyVector<T>::getSize() const {
    //simply return the size of the vector
    return _size;
}


template<typename T>
//method that gets the capacity of the vector
size_t MyVector<T>::getCapacity() const {
    //simply return the size of the vector
    return _capacity;
}


template<typename T>
//method that prints the contents of the vector
void MyVector<T>::print() {
    //go through the elements of the vector and print them
    for (int i = 0; i < _size; i++) {
        std::cout << "Element: " << _myArray[i] << std::endl;
    }
}



//OPERATORS

//operator plus function
template<typename T>
MyVector<T> operator+(const MyVector<T>& lhs, const MyVector<T>& rhs) {
    //create a new MyVector as a result of the concatenation
    MyVector<T> result;

    assert((lhs.getSize()) == (rhs.getSize()) && "Size mismatch in operator");
    size_t size = lhs.getSize();

    for (size_t i = 0; i < size; i++) {
        result.push_back(lhs.get(i) + rhs.get(i));
    }


    return result;
}


//operator plus function, concatenate
template<typename T>
MyVector<T> MyVector<T>::operator+(const MyVector<T>& rhs) {
    if (rhs.getSize() == 0)
        return *this;
        
    //create a new MyVector as a result of the concatenation
    MyVector<T> result;

    //copy the elements from the current object (this) to result
    for (int i = 0; i < getSize(); i++) {
        result.push_back(get(i));
    }

    //copy the elements from rhs to result
    for (int i = 0; i < rhs.getSize(); i++) {
        result.push_back(rhs.get(i));
    }

    // Return the result
    return result;
}


//operator equals function
template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& rhs) {
    //check to see if rhs and _myArray are the same
    if (this == &rhs) {
        return *this;
    }
    
    //create new memory for the new array
    if (_capacity < rhs._size) {
        delete [] _myArray;
        _myArray = new T [rhs._size];
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
template<typename T>
T& MyVector<T>::operator[](size_t index) {
    assert(index < _size && "Out of bounds in operator[]!");
    return _myArray[index];
}


//equals operator
template<typename T>
bool MyVector<T>::operator==(const MyVector<T>& rhs) const {
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
template<typename T>
bool MyVector<T>::operator!=(const MyVector<T>& rhs) const {
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
template<typename T>
bool MyVector<T>::operator<(const MyVector<T>& rhs) const {
    // Check if sizes of the vectors are not equal
        if (_size != rhs._size) {
            return false;
        }
    
    //check if each element in the vector is not the same
    for (int i = 0; i < _size; i++) {
        if (_myArray[i] > rhs._myArray[i]) {
            return false;
        }
    }
    return true;
}


//less than or equal to
template<typename T>
bool MyVector<T>::operator<=(const MyVector<T>& rhs) const {
    // Check if sizes of the vectors are not equal
        if (_size != rhs._size) {
            return false;
        }
    
    //check if each element in the vector is not the same
    for (int i = 0; i < _size; i++) {
        if (_myArray[i] > rhs._myArray[i] || _myArray[i] != rhs._myArray[i]) {
            return false;
        }
    }
    return true;
}


//operator greater than or equal to
template<typename T>
bool MyVector<T>::operator>=(const MyVector<T>& rhs) const {
    // Check if sizes of the vectors are not equal
        if (_size != rhs._size) {
            return false;
        }
    
    //check if each element in the vector is not the same
    for (int i = 0; i < _size; i++) {
        if (_myArray[i] < rhs._myArray[i] || _myArray[i] != rhs._myArray[i]) {
            return false;
        }
    }
    return true;
}


//operator greater than
template<typename T>
bool MyVector<T>::operator>(const MyVector<T>& rhs) const {
    // Check if sizes of the vectors are not equal
        if (_size != rhs._size) {
            return false;
        }
    
    //check if each element in the vector is not the same
    for (int i = 0; i < _size; i++) {
        if (_myArray[i] < rhs._myArray[i]) {
            return false;
        }
    }
    return true;
}














#endif /* DiyVector_hpp */
