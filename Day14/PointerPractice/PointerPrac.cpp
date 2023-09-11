
#include <iostream>
#include "PointerPrac.hpp"

//function that adds one to each element of the array
int arrayModSum(MyVector& someVar, int sizeOfArray) {
  //variable that will return the arrayModSum
  int sum = 0;

  //modify someVar.data by adding 1 to each element
  for (int i = 0; i < sizeOfArray; i++) {
    someVar.data[i] = someVar.data[i] + 1;
    sum += someVar.data[i];
  }

  return sum;
}


void growMyVector(MyVector& someVar) {

  if (someVar.size == someVar.capacity) {
    someVar.capacity = someVar.capacity * 2;
    double* tempArray = new double [someVar.capacity];

    for (int i = 0; i < someVar.size; i++) {
      tempArray[i] = someVar.data[i];
    }


  //call delete on someVar.data
  delete [] someVar.data;

  //assign someVar.data to the contents of the new array
  someVar.data = tempArray;

  //nullify the tempArray so that we can free up the space in memory
  tempArray = nullptr;

  //print out the capacity size after growing it
  std::cout << "Capacity of New Array: " << someVar.capacity << std::endl;
}


}
