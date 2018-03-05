template <typename T>
T FuncCalc<T>::operator()(const T num) const
{
	return (1/(1+(12*pow(num,2))));
}