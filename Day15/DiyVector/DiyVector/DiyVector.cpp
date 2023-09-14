//
//  DiyVector.cpp
//  DiyVector
//
//  Created by Josh Barton on 9/12/23.
//

#include "DiyVector.hpp"


void MyVector::freeVector(MyVector& vector) {
    delete [] vector.myArray;
}

MyVector MyVector::pushBack(MyVector& vector) {
    //return variable that will return the new MyVector after the push back
    MyVector newVector;
    
    return newVector;
}

MyVector MyVector::popBack(MyVector& vector) {
    
}

int MyVector::get(MyVector& vector, int index) {
    
}

int MyVector::set(MyVector& vector, int index) {
    
}

MyVector MyVector::growVector(MyVector& vector) {
    
}

int MyVector::getSize(MyVector& vector) {
    
}

int MyVector::getCapacity(MyVector& vector) {
    
}
