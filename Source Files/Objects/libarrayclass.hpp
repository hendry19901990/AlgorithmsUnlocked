/* Copyright (c) 2017, Sumit Lahiri */

/** 
 * The implementation here is only dummy but it shows how to overload operators
 * in case of classes defined with a template typename. Hope this will clarify the 
 * basics of how to write such kinds of code and will also help in better understanding of 
 * Functors, overloading & Constructors along with operator oveloading
 **/
/*

All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _LIBARRAYCLASS_H
#define _LIBARRAYCLASS_H 1

#ifndef MAX_SIZE
#define MAX_SIZE 8192
#define BUFF_SIZE 1024
#endif

#define EXIT_FAILURE 1

#ifndef NULL
#undef NULL
#define	NULL	0
#endif

#ifndef TRUE
#define TRUE	1
#endif
#ifndef FALSE
#define FALSE	0
#endif

#include<iostream>
#include<cstdio>
#include<string>
#include<new>
#include<vector>
typedef unsigned int _int_type;
typedef unsigned long _double_type;
typedef unsigned char _char_type;
typedef size_t _size_type;
typedef wchar_t _wide_type;
typedef const std::nothrow_t& _nothrow;
typedef std::istream& _input_stream;
typedef std::ostream& _output_stream;
typedef std::bad_alloc _bad_allocation;
typedef class object _object;
typedef void* _void_ptr;
#ifndef _BASEDEF_H
#define _BASEDEF_H 1
class __attribute__((__packed__)) Basedef{
public:
  typedef unsigned int _int_type;
  typedef unsigned long _double_type;
  typedef unsigned char _char_type;
  typedef size_t _size_type;
  typedef wchar_t _wide_type;
  typedef const std::nothrow_t& _nothrow;
  typedef std::istream& _input_stream;
  typedef std::ostream& _output_stream;
  typedef std::bad_alloc _bad_allocation;
  typedef class object _object;
  typedef void* _void_ptr;
  /* Since no object of this class will ever be created, it has no constructor or destructor implicitly defined */
};
#endif
/* Template Class for Array entry & Array operations */
template <typename Atype> class __attribute__((__packed__)) _Carray : public Basedef{
  /* Array usual :: int,char,double,int*,char*,double* */
  Atype *array;
  /* Size */
  _size_type size;
  /* iterator */
  Atype *iterator;
  /* Allocation trait*/
  _void_ptr _alloc_;
  /* static int */
  static int count;
public:
  static inline void getCount(); /* To be implemented later */
  template <typename U> inline friend _input_stream operator>>(_input_stream,_Carray<U> const &) noexcept;
  /* Extractor Stream */
  template <typename U> inline friend _output_stream operator<<(_output_stream,_Carray<U> const &) noexcept;
  /* Buffer Filled Stream */
  inline Atype& operator[](int) noexcept;
  /* Array Subscripter */
  inline _Carray operator++(int);
  inline _Carray operator--(int);
  /* Adding operation */
  inline _void_ptr operator new(_size_type) __attribute__((alloc_size(1),aligned(1)));
  inline _void_ptr operator new(_size_type, _nothrow) __attribute__((alloc_size(1),aligned(1)));
  /* New Allocation */
  inline _void_ptr operator new[](_size_type) __attribute__((alloc_size(1),aligned(1)));
  inline _void_ptr operator new[](_size_type, _nothrow) __attribute__((alloc_size(1),aligned(1)));
  /* New Allocation Object Array */
  inline void operator delete(_void_ptr);
  inline void operator delete(_void_ptr,_nothrow);
  /* Delete */
  inline void operator delete[](_void_ptr);
  inline void operator delete[](_void_ptr,_nothrow);
  /* =OP */
  inline _Carray operator=(_Carray&);
  /* op() */
  inline _Carray operator()(int);
  /* Add/Subs at a particular position */
  static inline void ObjectRefs(_object);
  /* Get Object Refs */
  template<typename _compare> inline bool operator==(_compare);  /* To be defined as per need */
  /*Compare == */
  template<typename _compare> inline bool operator!=(_compare);  /* To be defined as per need */
  /* Compare != */
  template<typename _compare> inline bool operator<(_compare);  /* To be defined as per need */
  /* Compare < */
  template<typename _compare> inline bool operator>(_compare);  /* To be defined as per need */
  /* Compare > */
  inline _Carray* operator->(){return *this;} /* Overload () */
  /* Constructor */
  inline ~_Carray() noexcept; 
  /* Destructor */
  inline _Carray() noexcept; 
  inline _Carray(_size_type);
  /* Copy Constructor */
  inline _Carray(const _Carray&) noexcept;
};
/* Define if required, returns a std::istream& istream */
template <typename Atype>
inline _input_stream operator>>(_input_stream input, _Carray<Atype> const &object) noexcept
{ 
  std::cout << "Enter the size : \n";
  input >> object.size;
  std::cout << "Enter the values : \n";
  for(auto i = 0; i < object.size; i++)
  {
    input >> object.array[i];
  }
  return input;
}
/* Define if required, returns a std::ostream& ostream */
template <typename Atype>
inline _output_stream operator<<(_output_stream output,_Carray<Atype> const & object) noexcept
{ 
  std::cout << "Values are : \n";
  for(auto i = 0; i < object.size; i++)
  {
    output << object.array[i];
  }
  return output;
}
/* Return value @ array[index] */
template <typename Atype>
inline Atype& _Carray<Atype>::operator[](int index) noexcept
{ 
  return array[index];
}
/*Increments each element of the array */
template <typename Atype>
inline _Carray<Atype> _Carray<Atype>::operator++(int _dummy)
{ 
  for(auto i = 0; i<BUFF_SIZE; i++){
    array[i] = ++array[i];
  }
  return *this;
}
/* Decrements each element of the array */
template <typename Atype>
inline _Carray<Atype> _Carray<Atype>::operator--(int _dummy)
{ 
  for(auto i = 0; i<BUFF_SIZE; i++){
    array[i] = --array[i];
  }
  return *this;
}
/* Allocate an object instance from the heap with nothrow set */
template <typename Atype>
inline _void_ptr _Carray<Atype>::operator new(_size_type size, _nothrow nthrw)
{ 
  _void_ptr p = NULL;
  p = malloc(size);
  if(!p){
    exit(EXIT_FAILURE);
  }
  std::memset(array,0,sizeof(array));
  return p;
}
/* Allocate an object instance from the heap */
template <typename Atype>
inline _void_ptr _Carray<Atype>::operator new(_size_type size)
{ 
  _void_ptr p = NULL;
  p = malloc(size);
  if(!p){
    exit(EXIT_FAILURE);
  }
  std::memset(array,0,sizeof(array));
  return p;
}
/* Allocate from heap an array of objects with nothrow set */
template <typename Atype>
inline _void_ptr _Carray<Atype>::operator new[](_size_type size, _nothrow nthrw)
{ 
  _void_ptr p = NULL;
  p = malloc(size);
  if(!p){
    exit(EXIT_FAILURE);
  }
  std::memset(array,0,sizeof(array));
  return p;
}
/* Allocate from heap an array of objects */
template <typename Atype>
inline _void_ptr _Carray<Atype>::operator new[](_size_type size)
{ 
  _void_ptr p = NULL;
  p = malloc(size);
  if(!p){
    exit(EXIT_FAILURE);
  }
  std::memset(array,0,sizeof(array));
  return p;
}
/* Delete objects */
template <typename Atype>
inline void _Carray<Atype>::operator delete(_void_ptr p)
{
  free(p);
}
/* Delete objects with nothrow set */
template <typename Atype>
inline void _Carray<Atype>::operator delete(_void_ptr p,_nothrow nthrw)
{
  free(p);
}
/* Delete array of objects */
template <typename Atype>
inline void _Carray<Atype>::operator delete[](_void_ptr p)
{
  free(p);
}
/* Delete array of objects with nothrow set */
template <typename Atype>
inline void _Carray<Atype>::operator delete[](_void_ptr p,_nothrow nthrw)
{
  free(p);
}
/* Overloaded assignment operator */
template <typename Atype>
inline _Carray<Atype> _Carray<Atype>::operator=( _Carray<Atype>& object)
{
  array = new Atype[BUFF_SIZE];
  if(!array){exit(EXIT_FAILURE);}
  for(auto i : array){
    array[i] = object.array[i];
  }
  size = object.size;
  iterator = object.iterator;
  _alloc_ = object._alloc_;
  return *this;
}
/* Will return the object with offset of array values as passed */
template <typename Atype>
inline _Carray<Atype> _Carray<Atype>::operator()(int num)
{
  for(auto i : array)
  {
    this->array[i] = this->array[i] + num;
  }
  return *this;
}
/* Copy Constructor for object copy & move */
template <typename Atype>
inline _Carray<Atype>::_Carray(const _Carray& object) noexcept
{
  array = new Atype[BUFF_SIZE];
  if(!array){exit(EXIT_FAILURE);}
  for(auto i : array){
    array[i] = object.array[i];
  }
  size = object.size;
  iterator = object.iterator;
  _alloc_ = object._alloc_;
}
/* Default constructor with initialization */
template <typename Atype>
inline _Carray<Atype>::_Carray() noexcept
{
  array = new Atype[BUFF_SIZE];
  if(!array){exit(EXIT_FAILURE);}
  std::memset(array,0,sizeof(array));
  size = 512;
  iterator = nullptr;
  _alloc_ = nullptr;
}
/* Destructor for deleting instance */
template <typename Atype>
inline _Carray<Atype>::~_Carray() noexcept
{
  // Deallocate memory that was previously reserved for array;
  if(array){
    delete[] array;
  } 
}
/* Parameter size is passed to ctor */
template <typename Atype>
inline _Carray<Atype>::_Carray(_size_type size) : size(size)
{
  array = new Atype[BUFF_SIZE];
  if(!array){exit(EXIT_FAILURE);}
  std::memset(array,0,sizeof(array));
  iterator = nullptr;
  _alloc_ = nullptr;
}
#endif