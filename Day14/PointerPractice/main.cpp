
#include <iostream>
#include "PointerPrac.hpp"

int main(int argc, char const *argv[]) {
  /* code */

//create a variable of type MyVector
MyVector vec1;

//read in the array size
vec1.size = 0;

//allocate an array on the heap using new
vec1.data = new double[10];

//update vec1.size to the new size, and vec1.capacity to be equal to the size
vec1.size = 0;

vec1.capacity = 10;

//loop over the newly created array and fill each element with 1.0
for (int i = 0; i < vec1.capacity; i++) {
  vec1.data[i] = 1.0;
  vec1.size += 1.0;
}


//print out returned sum of the arrayModSum function
std::cout << "Sum: " << arrayModSum(vec1, 5) << std::endl;

//delete vec1
// delete [] vec1.data;
// vec1.data = nullptr;


//call the growMyVector function
growMyVector(vec1);

  return 0;
}
