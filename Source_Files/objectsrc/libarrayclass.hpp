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
class __attribute__((__packed__)) Basedef {
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
/* Template Class for Array entry & Array operations */
template <typename Atype> class __attribute__((__packed__)) _Carray : virtual public Basedef{
  /* Array */
  Atype array[];
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
  inline _input_stream operator>>(_input_stream);
  /* Extractor Stream */
  inline _output_stream operator<<(_input_stream);
  /* Buffer Filled Stream */
  inline Atype& operator[](_int_type) noexcept;
  /* Array Subscripter */
  inline _Carray operator++(_Carray&) noexcept;
  inline _Carray operator--(_Carray&) noexcept;
  /* Adding operation */
  inline _void_ptr operator new(_size_type ,_nothrow)__attribute__((alloc_size(1),aligned(BUFF_SIZE)));
  /* New Allocation */
  inline _void_ptr operator new[] (_size_type,_nothrow)__attribute__((alloc_size(1),aligned(BUFF_SIZE)));
  /* New Allocation Object Array */
  inline void operator delete(_void_ptr,_nothrow) noexcept;
  /* Delete */
  inline void operator delete[] (_void_ptr,_nothrow) noexcept;
  /* =OP */
  inline _Carray& operator=(_Carray&);
  /* op() */
  inline _Carray operator()(Atype,_int_type);
    /* Add/Subs at a particular position */
  static inline void ObjectRefs(_object);
  /* Get Object Refs */
  template<typename _compare> inline bool operator==(_compare) noexcept;
  /*Compare == */
  template<typename _compare> inline bool operator!=(_compare) noexcept;
  /* Compare != */
  template<typename _compare> inline bool operator<(_compare) noexcept;
  /* Compare < */
  template<typename _compare> inline bool operator>(_compare) noexcept;
  /* Compare > */
  inline _Carray* operator->() noexcept {return *this;}
  /* Constructor */
  inline ~_Carray() const {}
  /* Destructor */
  inline _Carray(_size_type) : size() noexcept {}
  /* Copy Constructor */
  inline _Carray(const _Carray&) noexcept : array()
  {

  }
};
