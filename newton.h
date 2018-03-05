#ifndef NEWTON_H
#define NEWTON_H

#include <iostream>
#include <vector>
#include <tuple>
#include "myArray.h"

using namespace std;

template <typename T>
class Newton;

template<class T>
ostream& operator<< (ostream& out , Newton<T> & n);


template <typename T>
class Newton 
{
	private:

		MyArray <tuple <T,T> > intervalData; 

		MyArray <vector <T> > polyTable;	

		void calcNewton();

	public:

		void AddValues(vector <tuple <T,T> > theDataVec);

		T operator[](const int placer) const;

		friend ostream& operator<< <T> (ostream& out , Newton<T> & n);

		T interpolantVals( const T & x) ;

		void coefficientsPrint();

		T absErr(const T & x);

		T relErr(const T & x);

};

template <typename T>
class Compare
{
	public:
		bool operator() (const tuple <T,T> lhs, const tuple <T,T> rhs) const
		{
			return (get<0>(lhs)) < (get<0>(rhs));
		}
};
#include "newton.hpp"
#endif