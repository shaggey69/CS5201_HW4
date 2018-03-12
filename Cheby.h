/*! \file
 *
 * the Cheby class
 */
/*
header function for Cheby class
By: Ari Sherman
Class: CS5201 HW #4
Date: 3.12.18
*/
#ifndef CHEBY_H
#define CHEBY_H

#include "myArray.h"
#include "funcCalc.h"
#include <vector>
#include <cmath>
#include <tuple>

const double PI = 3.141592653589793;
/*!
 * the Cheby class
 *
 * A Pass-by function that calculates
 * Chevy polynumials for given data set
*/

template <typename T>
class Cheby
{
	/*! operator () for Cheby
  * This functions generates data points acording to the
  * Chebyshev spacing method in the [-1,1] interval. Num is the
  * number of points the function will generate. 
  * \pre num > 0
  * \post none
  *
  */
	public:
		MyArray <tuple <T,T>> operator()(const int num) ;
};

#include "Cheby.hpp"
#endif

