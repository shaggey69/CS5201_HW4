/*
implmentation of error class
By: Ari Sherman
Class: CS5201 HW #4
Date: 3.12.18
*/
//Absloute error
template <typename T>
T Errcalc<T>::absError(const T & lhs, const T & rhs) const
{
	return fabs(lhs-rhs);
}
//Relative error
template <typename T>
T Errcalc<T>::relError(const T & lhs, const T & rhs) const
{
	return abs((lhs-rhs)/lhs)*100;
}