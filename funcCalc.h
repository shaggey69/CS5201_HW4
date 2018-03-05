#ifndef FUNCCALC_H
#define FUNCCALC_H

#include <cmath>

template <typename T>
class FuncCalc
{
	public:
		T operator()(const T num) const;
};

#include "funcCalc.hpp"
#endif