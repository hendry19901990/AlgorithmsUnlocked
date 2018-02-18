#include<iostream>
#include<cstdio>
#include<string>
#include<new>
#include<vector>
#include "libarrayclass.hpp"
int main(int argc, char** argv)
{
  /* Size Type*/
  size_t size;
  /* Generic Allocation */
  _Carray<int> object;
  /* Assignment */
  _Carray<char**> array1(size), array2;
  array1 = array2; /* Assignment Operator Called */
  /* Allocating from the heap one object only */
  _Carray<double**> *doublearray = new _Carray<double**>(size);
  /* Allocating from the heap an array of objects */
  _Carray<unsigned int> *u_arrayobj = new _Carray<unsigned int> [3];
  /* Calling copy constructor */
  _Carray<char**> chararray = array1; /* Copy Constructor Called */
  /* Parameterized Constructor Called */
  _Carray<unsigned int**> *int_array = new _Carray<unsigned int**>(size); 
  /* Extractors */
  std::cout << object << array1 << array2 << chararray;
  /* Array Access */
  u_arrayobj[0][0] = 50;
  std::cout << u_arrayobj[0][0] << "\n";
  /* Istream*/
  std::cin >> object >> array1 >> array2 >> chararray;
  /* Functor Called */
  array1(array1,8);
  /* Deleting from heaps */
  delete int_array; /* Deleting single object, destructor is also called*/
  delete[] u_arrayobj; /* Deleting array of objects, destructors are called */ 
  delete doublearray; /* Deleting single object, destructor is also called*/
  /* return */
  return 0;
}
