/*
# myArray class functoins
# By: Ari Sherman
# Class: CS5201 HW #3
# Date: 2.26.18
*/
#include <iostream>
using namespace std;

//initialize constructor
template <typename T>   
MyArray<T>::MyArray(const int size)
{
	m_size = size;
	ptr_to_data = new T[m_size];
}

//dedult constructor 
template <typename T>   
MyArray<T>::MyArray()
{
	m_size = 0;
	ptr_to_data = 0;
}

//copy constructor
template <typename T>   
MyArray<T>::MyArray(const MyArray<T>& rhs)
{
	m_size = rhs.m_size;
	ptr_to_data = new T[m_size];
	arrayCopy(rhs);
}

//deconstructor
template <typename T>   
MyArray<T>::~MyArray()
{
	delete [] ptr_to_data;
}

//object getter []
template <typename T>   
T & MyArray<T>::operator[](const int index) 
{
	return ptr_to_data[index];
}

//set size
template <typename T>   
void MyArray<T>::setSize(const int n)
{
	if (n != m_size)
	{
		delete[] ptr_to_data;
		m_size = n ;
		ptr_to_data = new T[n];
	}
}

//clear
template <typename T>   
void MyArray<T>::clear()
{
	delete[] ptr_to_data;
	m_size = 0;
	ptr_to_data = 0;
}


//= assignment with RHS MyArray
template <typename T>   
MyArray<T>&  MyArray<T>::operator= (const MyArray<T>& rhs)
{
	if (ptr_to_data != rhs.ptr_to_data)
	{
		m_size = rhs.m_size;
		arrayCopy(rhs);
	}
	return (*this);
}

//= assignment with T element
template <typename T>   
MyArray<T>& MyArray<T>::operator= (const T rhs)
{
	T* p =ptr_to_data + m_size;
	while (p  > ptr_to_data)
		*--p= rhs;
	return *this;
}

//= insert
template <typename T>   
void MyArray<T>::insert(const T & x, int pos)
{
	ptr_to_data[pos] = x ;
}


//copy function
template <typename T>   
void MyArray<T>::arrayCopy(const MyArray<T> & source)
{
	T* p = ptr_to_data + m_size;
	T* q = source.ptr_to_data + m_size;
	while (p > ptr_to_data)
		*--p = * --q ;
}

//streamer
template <typename T>   
ostream& operator<< (ostream& out , MyArray<T> & arr)
{
	for (int i = 0; i < arr.getSize() ; i++)
		out << arr[i] << " " ;
	return out;
}
