//
//  DiyVectorTests.cpp
//  DiyVector
//
//  Created by Josh Barton on 9/16/23.
//

#include <stdio.h>
#include "DiyVector.hpp"


//TEST FUNCTIONS
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
    assert(vector.getSize() == 4);
}

void testGetCapacity(MyVector& vector) {
    assert(vector.getCapacity() == 8);
}

void testPrint(MyVector& vector) {
    vector.print();
}
  
//OPERATOR TESTS

void testOperatorPlus(MyVector& vector1, MyVector& vector2, MyVector& vector3) {
    assert(vector1 + vector2 == vector3);
}


void testOperatorGet(MyVector& vector) {
    assert(vector[1] == 6);
}


void testOperatorAssignment(MyVector& vector1, MyVector& vector2) {
    assert(vector1 == vector2 && "Operator = is not working!");
}


void testOperatorEquals(MyVector& vector1, MyVector& vector2) {
    assert(vector1 == vector2 && "Operator == is not working!");
}


void testOperatorDoesNotEqual(MyVector& vector1, MyVector& vector2) {
    assert(vector1 != vector2 && "Operator != is not working!");
}


void testOperatorLessThan(MyVector& vector1, MyVector& vector2) {
    assert(vector1 < vector2 && "Operator < is not working!");
}


void testOperatorLessThanOrEqual(MyVector& vector1, MyVector& vector2) {
    assert(vector1 <= vector2 && "Operator <= is not working!");
}


void testOperatorGreaterThanOrEqual(MyVector& vector1, MyVector& vector2) {
    assert(vector1 >= vector2 && "Operator >= is not working!");
}


void testOperatorGreaterThan(MyVector& vector1, MyVector& vector2) {
    assert(vector1 > vector2 && "Operator > is not working!");
}
