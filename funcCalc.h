/*! \file
 *
 * the Bell Curve class
 */
/*
header function for  Bell Curve class
By: Ari Sherman
Class: CS5201 HW #4
Date: 3.12.18
*/

#ifndef FUNCCALC_H
#define FUNCCALC_H
/*!
 * the Bell Curve calculation class
 *
*/
#include <cmath>

template <typename T>
class FuncCalc
{
	public:

	/*! Operator () calculator!
	* \s
  * \pre T must have the "*" binary operator defiend for it
  * \post none
  *	\return the bell curve value for given "Num"
  */
		T operator()(const T num) const;
};

#include "funcCalc.hpp"
#endif