#include<iostream>
#include<cstdio>
#include<string>
#include<new>
#include<vector>
#include "libarrayclass.hpp"

int main(int argc, char** argv)
{
  _Carray<int> array,b;
  b = array;
  size_t size;
  _Carray<int>* a = new _Carray<int>[size];  
  array[0];
  std::cout << array;
  return 0;
}
