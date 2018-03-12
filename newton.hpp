/*
# Newton class functoins
# By: Ari Sherman
# Class: CS5201 HW #4
# Date: 3.12.18
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <typeinfo>
#include <tuple>
#include <algorithm>
#include "myArray.h"

using namespace std;

// Add data points to intervalData.
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

//operator []
template <typename T>   
T Newton<T>::operator[](const int placer) const
{
	if (placer < intervalData.getSize())
		return intervalData[placer];
	return 0;
}

//caluclate Newton Polynomial Divdion fucntion
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
 //interpolantVals calculation function
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

// coefficent printer function
template <typename T>   
void Newton<T>::coefficientsPrint()
{
	int size = intervalData.getSize();
	MyArray<T> coefHelper (size);
	MyArray<T> center (size-1);
 	coefHelper.insert(polyTable[size-1][size-1],size-1);
	for (int i = 0 ; i < size-1 ;i++)
	{
		center.insert(get<0>(intervalData[i]),i);
		coefHelper.insert(polyTable[i][i],i);
	}
	for (int i = 0 ; i < size-1 ; i ++)
	{
		for (int j = size-1 ; j > 0 ; j--)
			coefHelper.insert((coefHelper[j-1])+(0 - center[j-1])
			*(coefHelper[j]),j-1);
		for (int k = size-2 ; k > 0 ; k--)
				center.insert(center[k-1],k);
		center.insert(0,0);
	}
	cout << coefHelper;
	return;
}

//print
template <typename T>   
 ostream& operator<< (ostream& out , Newton<T> & n)
{
  for ( int i = 0 ; i < n.intervalData.getSize() ; i ++)
  	out << get<0>(n.intervalData[i]) << " " 
		<< get<1>(n.intervalData[i]) << endl;
  return out;
}

// Absloute error
template <typename T>   
T  Newton<T>::absErr(const T & x)
{	
	return (fabs( 1/(1+12*pow((x),2)) - interpolantVals(x) ) *100);
}

// Relative error
template <typename T>   
T Newton<T>::relErr(const T & x) 
{	
	return (fabs(absErr(x)/(1/(1+12*pow((x),2)))));
}