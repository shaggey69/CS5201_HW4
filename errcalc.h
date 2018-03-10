#ifndef ERRCALC_H
#define ERRCALC_H

#include <cmath>

template <typename T>
class Errcalc
{
	public:
		T absError(const T & lhs, const T & rhs) const;
		T relError(const T & lhs, const T & rhs) const;

};

#include "errcalc.hpp"
#endif