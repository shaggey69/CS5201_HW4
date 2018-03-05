//'()' Operator
template <typename T>
MyArray <tuple <T,T>> Cheby<T>::operator()(const int num)
{
	int polyNum = num -1 ;
	MyArray < tuple< T ,T > >  retVal(num);
	for (int i = 0 ; i < num ; i++)
	{
		T tempX = cos((PI/((polyNum*2)+2))*(2*polyNum+1-i*2)) ;
		FuncCalc<T> tempFunc;
		T tempY = tempFunc(tempX);
		retVal.insert((make_tuple(tempX,tempY)),i);
	}
	return retVal;
}