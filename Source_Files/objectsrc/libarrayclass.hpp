/* Copyright (c) 2017, Sumit Lahiri */
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
#endif

#ifndef MAX_SIZE
#define MAX_SIZE 8192
#define BUFF_SIZE 1024
#endif

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
#ifndef _input_stream
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
  /* Array */
  Atype array[BUFF_SIZE];
  /* Size */
  _size_type size;
  /* iterator */
  Atype *iterator;
  /* Allocation trait*/
  _void_ptr _alloc_;
  /* static int */
  static int count;
public:
  static inline void getCount();
  template <typename U> inline friend _input_stream operator>>(_input_stream,_Carray<U> const &);
  /* Extractor Stream */
  template <typename U> inline friend _output_stream operator<<(_output_stream,_Carray<U> const &);
  /* Buffer Filled Stream */
  inline Atype& operator[](_int_type);
  /* Array Subscripter */
  inline _Carray& operator++(int);
  inline _Carray& operator--(int);
  /* Adding operation */
  inline _void_ptr operator new(_size_type) __attribute__((alloc_size(1),aligned(1)));
  inline _void_ptr operator new(_size_type, _nothrow) __attribute__((alloc_size(1),aligned(1)));
  /* New Allocation */
  inline _void_ptr operator new[] (_size_type) __attribute__((alloc_size(1),aligned(1)));
  inline _void_ptr operator new[] (_size_type, _nothrow) __attribute__((alloc_size(1),aligned(1)));
  /* New Allocation Object Array */
  inline void operator delete(_void_ptr);
  inline void operator delete(_void_ptr,_nothrow);
  /* Delete */
  inline void operator delete[] (_void_ptr);
  inline void operator delete[] (_void_ptr,_nothrow);
  /* =OP */
  inline _Carray& operator=(_Carray&);
  /* op() */
  inline _Carray operator()(_Carray&, _int_type);
  /* Add/Subs at a particular position */
  static inline void ObjectRefs(_object);
  /* Get Object Refs */
  template<typename _compare> inline bool operator==(_compare);
  /*Compare == */
  template<typename _compare> inline bool operator!=(_compare);
  /* Compare != */
  template<typename _compare> inline bool operator<(_compare);
  /* Compare < */
  template<typename _compare> inline bool operator>(_compare);
  /* Compare > */
  inline _Carray* operator->(){return *this;} __attribute__((alloc_size(1)));
  /* Constructor */
  inline ~_Carray() {};
  /* Destructor */
  inline _Carray() {};
  inline _Carray(_size_type): size() {}
  /* Copy Constructor */
  inline _Carray(const _Carray&): array() {}
};

template <typename Atype>
inline _input_stream operator>>(_input_stream input, _Carray<Atype> const & object)
{ 
  std::cout << "_Output_stream_called\n";
  return input;
}

template <typename Atype>
inline _output_stream operator<<(_output_stream output,_Carray<Atype> const & object)
{ 
  output << "_Output_stream_called\n";
  return output;
}

template <typename Atype>
inline Atype& _Carray<Atype>::operator[](_int_type i)
{ 
  std::cout << "_Accessed\n" << i;
}

template <typename Atype>
inline _Carray<Atype>& _Carray<Atype>::operator++(int _dummy)
{ 
  std::cout << "_Increment\n";
}

template <typename Atype>
inline _Carray<Atype>& _Carray<Atype>::operator--(int _dummy)
{ 
  std::cout << "_Decrement\n";
}

template <typename Atype>
inline _void_ptr _Carray<Atype>::operator new (_size_type size, _nothrow nthrw)
{ 
  std::cout << "_Allocator\n";
}
template <typename Atype>
inline _void_ptr _Carray<Atype>::operator new (_size_type size)
{ 
  std::cout << "_Allocator\n";
}

template <typename Atype>
inline _void_ptr _Carray<Atype>::operator new[] (_size_type size, _nothrow nthrw)
{ 
  std::cout << "_Allocator[]\n";
}

template <typename Atype>
inline _void_ptr _Carray<Atype>::operator new[] (_size_type size)
{ 
  _void_ptr p;
  std::cout << "_Allocator[]\n";
  return p;
}

template <typename Atype>
inline void _Carray<Atype>::operator delete(_void_ptr p,_nothrow nthrw)
{

}

template <typename Atype>
inline void _Carray<Atype>::operator delete[](_void_ptr p,_nothrow nthrw)
{
  
}

template <typename Atype>
inline _Carray<Atype>& _Carray<Atype>::operator=( _Carray<Atype>& object)
{
  std::cout << "_Shadow_Assignment Ocurred\n";
}

template <typename Atype>
inline _Carray<Atype> _Carray<Atype>::operator()( _Carray<Atype>& object,_int_type i)
{
  std::cout << "_Functor_Access Ocurred\n";
}