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

class MyVector {
private:
    int* myArray;
    int capacity;
    int size;
    
public:
    void freeVector(MyVector& vector);
    MyVector pushBack(MyVector& vector);
    MyVector popBack(MyVector& vector);
    int get(MyVector& vector, int index);
    int set(MyVector& vector, int index);
    MyVector growVector(MyVector& vector);
    int getSize(MyVector& vector);
    int getCapacity(MyVector& vector);
    
    

    MyVector(int* _myArray, int _capacity, int _size) {
        myArray = _myArray;
        capacity = _capacity;
        size = _size;
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
