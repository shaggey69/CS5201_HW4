/*! \file
 *
 * A Polar library.
 */
/*
header function and implments for Cheby class
By: Ari Sherman
Class: CS5201 HW #4
Date: 2.12.18
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
	public:
		MyArray <tuple <T,T>> operator()(const int num) ;
};

#include "Cheby.hpp"
#endif

