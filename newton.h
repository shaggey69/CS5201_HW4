
/*! \file
 *
 * A Newton polynomial class.
 */

/*
# Newton class header
# By: Ari Sherman
# Class: CS5201 HW #4
# Date: 3.12.18
*/ 

#ifndef NEWTON_H
#define NEWTON_H

#include <iostream>
#include <vector>
#include <tuple>
#include "myArray.h"

using namespace std;

template <typename T>
class Newton;

/*! Stream insertion operator for `Newton`.
 *
 * \pre Stream insertion operator is defined for `T`.
 * \post The contents of the intervalData are printed to the ouptut stream.
 * \return the modified output stream.
 *
 */
template<class T>
ostream& operator<< (ostream& out , Newton<T> & n);


/*! The Newton Class.
 *
 *contains 2 myArray objects:
 * intervalData - contains tuples of type T and T 
 * of data points.
 * PolyTable - contains Vectors of type T that hold 
 * the data for Newton Polynomial Divdion.
 */
template <typename T>
class Newton 
{
	private:

		MyArray <tuple <T,T> > intervalData; 

		MyArray <vector <T> > polyTable;	

		/*! caluclaures the Newton Polynomial Divdion.
		* Each vector in polyTable will be assoicated with the column
		* from the Newton Polynomial Divdion Table.
		* \pre intervalData must be implmented and can not be empty.
		* \post polyTable will contain the numer of vectors as 
		* the number of Tuples in intervalData.
		*/

		void calcNewton();

	public:

		/*! Add data points to intervalData.
		* Each tuple from theDataVec will be added to intervalData
		* and calcNewton function will be called!
		* \pre '<' operator defind for T! 
		* \post intervalData will contain the number of tupels
		*	in theDataVec.
		*/

		void AddValues(vector <tuple <T,T> > theDataVec);

		/*! object getter []
		*
		* \pre placer must be between 0 and size of intervalData.
		* \post Will return the Tuple of type T and T that is
		* is stored in intervalData at the "placer" index.
		*
		*/

		T operator[](const int placer) const;

		/*! Stream insertion operator for `Newton`.
		*
		* \pre Stream insertion operator is defined for `T`.
		* \post The contents of the intervalData are printed to the ouptut stream.
		* \return the modified output stream.
		*
		 */

		friend ostream& operator<< <T> (ostream& out , Newton<T> & n);

		/*! calculates the values of the interpolant at the given x Value
		*
		* \pre "=" "*=" "+=" operators are defined for `T`,
		* And PolyTable must have at least one memeber.
		* \post none
		* \return the value of x at interpolant point.
		*
		*/

		T interpolantVals( const T & x) ;

		/*! prints the cofficents of the Polynomial
		* in the fourm: a + bX + cX^2 ...
		* \pre none
		* \post values printed on screen
		*/

		void coefficientsPrint();

		/*! Abslotre error of given x from Newton Polynomial Divdion
		* as oppsed to the function 1/(1+12x^2)
		*
		* \pre meets requirments of "interpolantVals" functions
		*	and "<<" defined for T
		* \post none
		*/

		T absErr(const T & x);

		/*! Relative error of given x from Newton Polynomial Divdion
		* as oppsed to the function 1/(1+12x^2)
		*
		* \pre meets requirments of "interpolantVals" functions
		* \post none
		*/

		T relErr(const T & x);

};

/*! The compare Class.
 */
template <typename T>
class Compare
{
	public:
		/*! The () Operator
		*	returns true if lhs is bigger then rhs
		* \pre '<' operator defind for T! 
		* \post none
		*/
		bool operator() (const tuple <T,T> lhs, const tuple <T,T> rhs) const
		{
			return (get<0>(lhs)) < (get<0>(rhs));
		}
};
#include "newton.hpp"
#endif