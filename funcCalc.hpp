/*
header function for Bell Curve implmention
By: Ari Sherman
Class: CS5201 HW #4
Date: 3.12.18
*/
// operator ()
template <typename T>
T FuncCalc<T>::operator()(const T num) const
{
	return (1/(1+(12*pow(num,2))));
}