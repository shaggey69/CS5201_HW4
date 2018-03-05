/*! \file
 *
 * A Newton polynomial class.
 */

/*
# myArray class header
# By: Ari Sherman
# Class: CS5201 HW #3
# Date: 2.26.18
*/
#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
using namespace std;


template <typename T>
class MyArray;

/*! Stream insertion operator for `myArray`.
 *
 * \pre Stream insertion operator is defined for `T`.
 * \post The contents of the intervalData are printed to the ouptut stream.
 * \return the modified output stream.
 *
 */
template<class T>
ostream& operator<< (ostream& out ,  MyArray<T> & arr);


/*! myArray calss
 *
 * contains a:
 * m_size - represting the size of the array
 * ptr_to_data - a pointer to the beginning of the array
 */


template <class T>
class MyArray
{
 
  int m_size;

  T* ptr_to_data;         


  /*! copies the content of the source into the CO
  *
  * \pre "=" assignment must be defined for T
  * \post ptr_to_data of CO will point to differnet adress
  *
  */
  void arrayCopy (const MyArray<T> & source);

  
public:
  
   /*! initialize constructor.
  * A new Array is craeted length equel "size"
  * \pre size must be bigger then 0!
  * \post a MyArray is born!
  *
  */

  MyArray(const int size);

   /*! defult constructor.
  * A new Array is craeted with size 0 and 
  * ptr_to_data points to 0.
  * \pre none
  * \post a MyArray is born!
  *
  */
  MyArray();

  /*! copy constructor.
  * A new Array is craeted length equel to RHS
  * size. New array does NOT point to same adress as RHS.
  * \pre 
  * \post a MyArray is born!
  *
  */


  MyArray(const MyArray<T>& rhs);

  /*! deconstructor.
  *
  * An Arnold Schwarzenegger Terminates the pointer
  * to avoid Skynet taking over with their memorey Leacks.
  * " Hasta La Vista , Pointer "
  *
  */

  ~MyArray();

  /*! object getter []
  *
  * \pre index must be between 0 and m_size
  * \post none
  * \return Will return the value of T at the index 
  */

	T & operator[](const int index);

  /*! get size!
  *
  * \pre none
  * \post none
  * \return size of array
  */

	int getSize() const {return m_size;}


  /*! set size!
  *
  * \pre n must be postive
  * \post none
  */


	void setSize(const int n);

  /*! clear
  * emptys out the array!
  * \pre none
  * \post ptr_to_data points to 0
  */

	void clear(); 


  /*! = assignment
  * turns the CO array into RHS arry
  * \pre none
  * \post ptr_to_data points to rhs data
  */


  MyArray<T>& operator= (const MyArray<T>& rhs);  

  /*! = assignment
  * assigns T to the CO
  * \pre  "=" assignment must be defined for T
  * \post none
  */


	MyArray<T>& operator= (const T);  	

   /*! insert
  * insert T elment into Array at the "pos" index
  * \pre pos must be smaller then m_size!
  * \post array modified with new element
  */
  
  void insert(const T & x, int pos);

/*! Stream insertion operator for `myArray`.
 *
 * \pre Stream insertion operator is defined for `T`.
 * \post The contents of the intervalData are printed to the ouptut stream.
 * \return the modified output stream.
 *
 */
  friend ostream& operator<< <T> (ostream& out , MyArray<T> & arr);

}; 


#include "myArray.hpp"

#endif
