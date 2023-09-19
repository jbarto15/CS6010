//
//  main.cpp
//  DiyVector
//
//  Created by Josh Barton on 9/12/23.
//

#include <iostream>
#include "DiyVector.hpp"
#include "DiyVectorTests.hpp"
#include <numeric>

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
    //testOperatorGreaterThanOrEqual(v4, v5);
    
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
    
    std::vector<int> integers = {34, 56, 45, 3, 7, 21, 7};
    MyVector<int> v11(integers);
    
    v9.print();
    v10.print();
    
    
    //test for begin method using a for each loop
    for (char character: v11) {
        std::cout << "Number: " << character << std::endl;
    }
    
    //test to see if we can sort vector
    std::sort(v11.begin(), v11.end());
    v11.print();
    
    //test to find the minimum element
    int min = *std::min_element(v11.begin(), v11.end());
    std::cout << "Minimum Element: " << min << std::endl;
    
    //test to sum the vector
    int sum = std::accumulate(v11.begin(), v11.end(), 0);
    std::cout << "Sum: " << sum << std::endl;
    
    //test count if num is even
    int count = std::count_if(v11.begin(), v11.end(), [](int i) { return i % 2 == 1; });
    std::cout << "Count: " << count << std::endl;
    
    
    //test remove-if and pop back
    int remove = *std ::remove_if(
                                  v11.begin(), v11.end(),
                                  [](int i) { return ((i % 2) == 0); });
    for (int i: v11) {
        std::cout << i << std::endl;
    }
    
    
    
    return 0;
}
