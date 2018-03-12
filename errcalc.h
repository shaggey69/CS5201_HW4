/*! \file
 *
 * the error calclation class
 */
/*
error calclation header  
By: Ari Sherman
Class: CS5201 HW #4
Date: 3.12.18
*/#ifndef ERRCALC_H
#define ERRCALC_H

#include <cmath>
/*!
 * the Error calculation class
 *
*/
template <typename T>
class Errcalc
{
	public:
	/*! Absloute Error calculator!
	* \
  * \pre "-" binary operator defiend for T!
  * \post none
  *	\return the absloute error value!
  */
		T absError(const T & lhs, const T & rhs) const;

	/*! Relative Error calculator!
	* \
  * \pre "-" binary operator defiend for T!
  * \post none
  *	\return the relarive error value!
  */
		T relError(const T & lhs, const T & rhs) const;

};

#include "errcalc.hpp"
#endif