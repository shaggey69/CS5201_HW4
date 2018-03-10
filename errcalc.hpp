template <typename T>
T Errcalc<T>::absError(const T & lhs, const T & rhs) const
{
	return fabs(lhs-rhs)*100;
}
template <typename T>
T Errcalc<T>::relError(const T & lhs, const T & rhs) const
{
	return abs((lhs-rhs)/lhs)*100;
}