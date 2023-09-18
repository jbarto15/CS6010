//
//  main.cpp
//  DiyVector
//
//  Created by Josh Barton on 9/12/23.
//

#include <iostream>
#include "DiyVector.hpp"

int main(int argc, const char * argv[]) {
    
    //create an object of MyVector
    MyVector<int> v1(10);
    
    //create objects of MyVector sending in a vector of data
    std::vector<int> data1 = {3, 6, 12, 198};
    MyVector v4(data1);
    
    std::vector<int> data2 = {3, 4, 12, 198};
    MyVector v5(data2);
    
    std::vector<int> data3 = {3, 6, 12, 198, 3, 4, 12, 198};
    MyVector v6(data3);
    
    std::vector<int> data4 = {3, 6, 12, 198};
    MyVector v7(data1);
    
    
    //test for push back method
    testPushBack(v1);
    
    //test print method
    testPrint(v1);
    
    //test for pop back method
    testPopBack(v1);
    
    
    //test for get method
    testGet(v1);
    
    
    //test for set method
    testSet(v1);
    
    
    //test get size method
    testGetSize(v4);
    
    
    //test get capacity method
    testGetCapacity(v4);
    
    
    //use the copy constructor
    MyVector v2(v1);
    
    MyVector<int> v3(10);
    
    
    //test operator plus
    testOperatorPlus(v4, v5, v6);
    
    //test operator get value
    testOperatorGet(v4);
    
    //test operator assignment
    testOperatorAssignment(v4, v7);
    
    //test operator equals
    testOperatorEquals(v1, v2);
    
    //test operator does not equal
    testOperatorDoesNotEqual(v5, v4);
    
    //test operator less than
    testOperatorLessThan(v5, v4);
    
    //test operator less than or equal to
    testOperatorLessThanOrEqual(v4, v4);
    
    //test operator greater than or equal to
    testOperatorGreaterThanOrEqual(v5, v4);
    
    //test operator greater than
    testOperatorGreaterThan(v4, v5);
    
    v3 = v4;
    
    v3.print();
    
    
    //test with doubles
    std::vector<double> doubles = {1.0, 2.0, 3.0, 4.0, 5.0};
    MyVector<double> v8(doubles);
    
    v8.print();
    
    
    //test with strings
    std::vector<std::string> names = {"Josh", "Brittney", "Caleb"};
    MyVector<std::string> v9(names);
    
    //test with characters
    std::vector<char> characters = {'a', 'b', 'c', 'd'};
    MyVector<char> v10(characters);
    
    v9.print();
    v10.print();
    
    
    
    return 0;
}
