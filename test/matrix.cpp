// matrix.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//
#include "stdafx.h"
#include "matrix.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#ifndef matrix_cpp
#define matrix_cpp

template <typename T>
class stack
{
public:	
   stack() : array_(nullptr), array_size_(0), count_(0) {}
   	~stack() { delete[] array_; }	
   stack(const stack<T> & st) : array_size_(st.array_size_), count_(st.count_) {		
      array_ = new T[array_size_];		
      for (size_t i = 0; i < count_; i++) {			
      array_[i] = st.array_[i];		
      }
   }	
   size_t count() const { return count_; }
   	void push(T const & el) {		
      if (array_size_ == count_) {
         			if (array_size_==0) {				array_size_=1;			}			
      array_size_ = array_size_*2;			
      T * ar = new T[array_size_];			
      for (size_t i = 0; i < count_; i++) {				
         ar[i] = array_[i];			}			
         delete[] array_;			
         array_ = ar;
         		}		
      array_[count_++] = el;	
    }	
    stack<T> & operator = (stack<T> & st) {
       		if (this != &st) {			
          delete[] array_;			
          array_size_ = st.array_size_;			
          count_ = st.count_;			
          array_ = new T[array_size_];			
          for (int i = 0; i < count_; i++)			{				
             array_[i] = st.array_[i];
       			   }
       		}		
       return *this;	
    }	
    T pop() {		if (count_ == 0) {
          			throw std::logic_error("Empty");
       		}		
       return array_[--count_];
    	}
private:
   	T * array_;	
   size_t array_size_;	
   size_t count_;
};


#endif
