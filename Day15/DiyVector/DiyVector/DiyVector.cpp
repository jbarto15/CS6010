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
//    std::cout << "after pop back: \n" << _size;
//    print();
}


//method that gets a value from the vector
int MyVector::get(size_t position) const {
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
        std::cout <<"\n before: "<< _myArray[position];
        _myArray[position] = value;
        std::cout <<"\n after: "<< _myArray[position]<<"\n";
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

////operator plus function
//MyVector operator+(const MyVector& lhs, const MyVector& rhs) const {
//    MyVector result;
//
//    assert((lhs.getSize()) == (rhs.getSize()) && "Size mismatch in operator");
//    size_t size = lhs.getSize();
//
//    for (size_t i = 0; i < size; i++) {
//        result.push_back(lhs.get(i) + rhs.get(i));
//    }
//
//    return result;
//}


////operator equals function
//MyVector operator=(const MyVector& lhs, const MyVector& rhs) {
//
//}



//TEST FUNCTIONS
void testFreeVector(MyVector& vector) {
    
}

void testPushBack(MyVector& vector) {
    //test for push back method
    vector.push_back(3);
    vector.push_back(6);
    vector.push_back(12);
    assert(vector.get(2) == 12);
}

void testPopBack(MyVector& vector) {
    vector.pop_back();
    //assert that the size of the vector has decreased by 1
}

//fix this one
void testGet(MyVector& vector) {
    vector.set(3, 0);
    assert(vector.get(0) == 3);
    vector.print();
}

void testSet(MyVector& vector){
    vector.set(198, 1);
    assert(vector.get(1) == 198);
}

void testGetSize(MyVector& vector) {
    
}

void testGetCapacity(MyVector& vector) {
    
}

void testPrint(MyVector& vector) {
    vector.print();
}
                
