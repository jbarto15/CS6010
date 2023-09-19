//
//  DiyVectorTests.hpp
//  DiyVector
//
//  Created by Josh Barton on 9/19/23.
//

#ifndef DiyVectorTests_h
#define DiyVectorTests_h


//TEST FUNCTIONS
template<typename T>
void testBegin(MyVector<T>& vector);


template<typename T>
void testEnd(MyVector<T>& vector);



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
void testBegin(MyVector<T>& vector) {
    for (char character: vector) {
        std::cout << "Character: " << character << std::endl;
    }
}


template<typename T>
void testEnd(MyVector<T>& vector) {
    
}


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

//template<typename T>
//void testOperatorGreaterThanOrEqual(MyVector<T>& vector1, MyVector<T>& vector2) {
//    assert(vector1 >= vector2 && "Operator >= is not working!");
//}

template<typename T>
void testOperatorGreaterThan(MyVector<T>& vector1, MyVector<T>& vector2) {
    assert(vector1 > vector2 && "Operator > is not working!");
}




#endif /* DiyVectorTests_h */
