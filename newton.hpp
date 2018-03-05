#include <iostream>
#include <cmath>
#include <vector>
#include <typeinfo>
#include <tuple>
#include <algorithm>
#include "myArray.h"

using namespace std;


template <typename T>   
void Newton<T>::AddValues(vector <tuple <T,T> > theDataVec)
{
	sort(theDataVec.begin(),theDataVec.end(),Compare<T>());
	intervalData.setSize(theDataVec.size());
	for (int i = 0 ; i < intervalData.getSize() ; i++)
		intervalData.insert(theDataVec[i],i);
	calcNewton();

	return;
}

template <typename T>   
T Newton<T>::operator[](const int placer) const
{
	if (placer < intervalData.getSize())
		return intervalData[placer];
	return 0;
}

template <typename T>   
void Newton<T>::calcNewton()
{
	polyTable.clear();
	polyTable.setSize(intervalData.getSize());
	vector<T> xValues;
	vector<T> yValues;
	for ( int i = 0 ; i < intervalData.getSize() ; i ++)
	{
		xValues.push_back(get<0>(intervalData[i])) ;
		yValues.push_back(get<1>(intervalData[i])) ;
	}
	polyTable.insert(yValues,0);
	int size = xValues.size();	
	for (int j = 1 ; j < size ; j++)
	{
		vector<T> temp;
		for (int z = 0; z < j ; z++)
			temp.push_back(0);

		for (int k = j ; k < size ; k++)
		{
			T o1,o2,o3,o4;
			o1 = xValues[k];
			o2 = xValues[k-j];
			o3 = polyTable[j-1][k];
			o4 = polyTable[j-1][k-1];
			T denominator = (o1) - (o2) ;
			T numerator = (o3) -(o4) ;
			temp.push_back(numerator/denominator);
		}

		polyTable.insert(temp,j);
	}

	return;
}

template <typename T>   
T Newton<T>::interpolantVals ( const T & x) 
{
	T retVal = polyTable[0][0];
	T temp = 1;
	for (int i = 0 ; i < intervalData.getSize()-1 ; i++)
	{				
		temp *= (x - get<0>(intervalData[i]));
		retVal += temp *(polyTable[i+1][i+1]);
	}
	return retVal;
}


template <typename T>   
void Newton<T>::coefficientsPrint()
{
	for ( int i = 0 ; i < polyTable.getSize() ; i ++)
		cout << polyTable[i][i] << endl;
	return;
}


template <typename T>   
 ostream& operator<< (ostream& out , Newton<T> & n)
{
  for ( int i = 0 ; i < n.intervalData.getSize() ; i ++)
  	out << get<0>(n.intervalData[i]) << " " 
		<< get<1>(n.intervalData[i]) << endl;
  return out;
}


template <typename T>   
T  Newton<T>::absErr(const T & x)
{	
	return (fabs( 1/(1+12*pow((x),2)) - interpolantVals(x) )*100);
}

template <typename T>   
T Newton<T>::relErr(const T & x) 
{	
	return (fabs(absErr(x)/(1/(1+12*pow((x),2)))));
}


//ABS error : (actuel func) - (table)
//rel error: abs error/actuel func