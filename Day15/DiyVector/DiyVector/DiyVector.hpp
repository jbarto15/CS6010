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
            _myArray = new T [_capacity];
            _capacity = 10;
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
        // Initialize the capacity and size based on the size of the input vector
        _capacity = data.size() * 2;
        _size = data.size();

        // Allocate memory for the internal array
        _myArray = new T[_capacity];

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
    //take away the last element by decreasing the size of the vector by 1
    _size--;
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
        return -1;
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
        
    // Create a new MyVector as a result of the concatenation
    MyVector<T> result;

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
template<typename T>
bool MyVector<T>::operator<=(const MyVector<T>& rhs) const {
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
template<typename T>
bool MyVector<T>::operator>=(const MyVector<T>& rhs) const {
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
template<typename T>
bool MyVector<T>::operator>(const MyVector<T>& rhs) const {
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


//TEST FUNCTIONS
template<typename T>
void testFreeVector(MyVector<T>& vector);

template<typename T>
void testPushBack(MyVector<T>& vector);

template<typename T>
void testPopBack(MyVector<T>& vector);

template<typename T>
void testGet(MyVector<T>& vector);

template<typename T>
void testSet(MyVector<T>& vector);

template<typename T>
void testGetSize(MyVector<T>& vector);

template<typename T>
void testGetCapacity(MyVector<T>& vector);

template<typename T>
void testPrint(MyVector<T>& vector);

//OPERATOR TESTS

template<typename T>
void testOperatorPlus(MyVector<T>& vector1, MyVector<T>& vector2, MyVector<T>& vector3);

template<typename T>
void testOperatorGet(MyVector<T>& vector);

template<typename T>
void testOperatorAssignment(MyVector<T>& vector1, MyVector<T>& vector2);

template<typename T>
void testOperatorEquals(MyVector<T>& vector1, MyVector<T>& vector2);

template<typename T>
void testOperatorDoesNotEqual(MyVector<T>& vector1, MyVector<T>& vector2);

template<typename T>
void testOperatorLessThan(MyVector<T>& vector1, MyVector<T>& vector2);

template<typename T>
void testOperatorLessThanOrEqual(MyVector<T>& vector1, MyVector<T>& vector2);

template<typename T>
void testOperatorGreaterThanOrEqual(MyVector<T>& vector1, MyVector<T>& vector2);

template<typename T>
void testOperatorGreaterThan(MyVector<T>& vector1, MyVector<T>& vector2);



//TEST FUNCTIONS
template<typename T>
void testPushBack(MyVector<T>& vector) {
    //test for push back method
    vector.push_back(3);
    vector.push_back(6);
    vector.push_back(12);
    assert(vector.get(2) == 12);
}

template<typename T>
void testPopBack(MyVector<T>& vector) {
    vector.pop_back();
    //assert that the size of the vector has decreased by 1
}

template<typename T>
void testGet(MyVector<T>& vector) {
    vector.set(3, 0);
    assert(vector.get(0) == 3);
    vector.print();
}

template<typename T>
void testSet(MyVector<T>& vector){
    vector.set(198, 1);
    assert(vector.get(1) == 198);
}

template<typename T>
void testGetSize(MyVector<T>& vector) {
    assert(vector.getSize() == 4);
}

template<typename T>
void testGetCapacity(MyVector<T>& vector) {
    assert(vector.getCapacity() == 8);
}

template<typename T>
void testPrint(MyVector<T>& vector) {
    vector.print();
}
  
//OPERATOR TESTS
template<typename T>
void testOperatorPlus(MyVector<T>& vector1, MyVector<T>& vector2, MyVector<T>& vector3) {
    assert(vector1 + vector2 == vector3);
}

template<typename T>
void testOperatorGet(MyVector<T>& vector) {
    assert(vector[1] == 6);
}

template<typename T>
void testOperatorAssignment(MyVector<T>& vector1, MyVector<T>& vector2) {
    assert(vector1 == vector2 && "Operator = is not working!");
}

template<typename T>
void testOperatorEquals(MyVector<T>& vector1, MyVector<T>& vector2) {
    assert(vector1 == vector2 && "Operator == is not working!");
}

template<typename T>
void testOperatorDoesNotEqual(MyVector<T>& vector1, MyVector<T>& vector2) {
    assert(vector1 != vector2 && "Operator != is not working!");
}

template<typename T>
void testOperatorLessThan(MyVector<T>& vector1, MyVector<T>& vector2) {
    assert(vector1 < vector2 && "Operator < is not working!");
}

template<typename T>
void testOperatorLessThanOrEqual(MyVector<T>& vector1, MyVector<T>& vector2) {
    assert(vector1 <= vector2 && "Operator <= is not working!");
}

template<typename T>
void testOperatorGreaterThanOrEqual(MyVector<T>& vector1, MyVector<T>& vector2) {
    assert(vector1 >= vector2 && "Operator >= is not working!");
}

template<typename T>
void testOperatorGreaterThan(MyVector<T>& vector1, MyVector<T>& vector2) {
    assert(vector1 > vector2 && "Operator > is not working!");
}











#endif /* DiyVector_hpp */
