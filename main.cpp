/*
# main file for the 4th Prgram!
# By: Ari Sherman
# Class: CS5201 HW #3
# Date: 3.12.18
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> 
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "myArray.h"
#include "newton.h"
#include "Cheby.h"
#include "funcCalc.h"
#include "errcalc.h"

using namespace std;
int main(int argc, char *argv[])
{	
	//declartion of vars
	ifstream in;
	int num_of_paris = 0 ;

	vector < tuple<double ,double > > dataVec, dataVec2;

	Newton<double > my_newton;
	double  temp1 = 0 , temp2 = 0;

	if (argc < 3)
    cout << endl << "not enough inputs :(" << endl ;
  else  if (argc > 3)    
    cout << endl << "too many inputs :(" << endl ;
  else
  {
		// opening the file from command line		
		in.open(argv[2]);
		argc = 0;
		in >> num_of_paris;

		//checking if file stream was sucessful
  	if (!in) 
    	cout << endl << "invailed file :("  << endl;
		else
		{
			num_of_paris = atoi(argv[1]);
			Cheby<double> chev; 
			MyArray <tuple <double,double>> ChevSpace = chev(num_of_paris);
			cout << endl << "#1 Mr.Chevy's values " << endl << endl;
			for (int i = 0 ; i < ChevSpace.getSize() ; i++)
			{
				cout.precision(8);
				cout << get<0>(ChevSpace[i]) << " " << get<1>(ChevSpace[i]) << endl ;
				dataVec.push_back(make_tuple(get<0>(ChevSpace[i]),get<1>(ChevSpace[i])));
			}
			
			cout << endl << "#2 coefficients " << endl << endl;
			Newton<double> chevPoly;
			chevPoly.AddValues(dataVec);
			chevPoly.coefficientsPrint();
			

			cout << endl << "#3 interpolant values " << endl << endl;
 			for (float i = 0.1 ; i <= 0.9 ; i += 0.2)
 				cout << chevPoly.interpolantVals(i) << endl;

 			cout << endl << "#4 true values " << endl << endl;
 			FuncCalc<double> tempFunc;
			for (float i = 0.1 ; i <= 0.9 ; i += 0.2)
				cout << tempFunc(i) << endl;
		
			Errcalc<double> err;

			cout << endl << "#5 absloue error values " << endl << endl;
 			for (float i = 0.1 ; i <= 0.9 ; i += 0.2)
 				cout << err.absError(tempFunc(i),chevPoly.interpolantVals(i)) << endl;

 			cout << endl << "#6 relative error values " << endl << endl;
 			for (float i = 0.1 ; i <= 0.9 ; i += 0.2)
 				cout << err.relError(tempFunc(i),chevPoly.interpolantVals(i)) << endl;

 			cout << endl << "#7 comparison " << endl << endl;
 			for (int i = 0; i < num_of_paris ; i++)
			{
				in >> temp1	;
				in >> temp2 ;
				dataVec2.push_back(make_tuple(temp1,temp2));
			}
			my_newton.AddValues(dataVec2);
			for (float i = 0.1 ; i <= 0.9 ; i += 0.2)
				cout << err.relError( my_newton.interpolantVals(i),
				chevPoly.interpolantVals(i)) << endl;
		}
	}

	in.close();

	return 0;
}
