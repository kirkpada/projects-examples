/************************************************************************************
 * ** Program: number_convert.cpp
 * ** Author: Daniel Kirkpatrick
 * ** Date: 10/11/2013
 * ** Description: Convert a binary 8 digit number, decimal number or octal number
 * **		   to either a binary 8 digit number, decimal number or octal number
 * ** Input: An 8 digit binary number, decimal number or octal number
 * ** Output: An 8 digit binary number, decimal number or octal number
 * **********************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int binIn1, binIn2, binIn3, binIn4, binIn5, binIn6, binIn7, binIn8;
 	int binOut1, binOut2, binOut3, binOut4, binOut5, binOut6, binOut7, binOut8;
	int binTotal;
	int decIn, decOct;
	int decBin[8];
	int conDecBin[8];
	int octalIn, octDecSum;
	int octBin[8];
	int conOctBin[8];
	int count;

	//Have the user input 1 or 0 and using for loop output correct decimal value
	cout << "Enter the 1st (left most) number of the binary number: ";
	cin >> binIn1;
	if(binIn1 == 1){
		binOut1 = 128;
	}
	else
		binOut1 = 0;

	cout << "Enter the 2nd number of the binary number: ";
	cin >> binIn2;
	if(binIn2 == 1){
		binOut2 = 64;
	}
	else
		binOut2 = 0;	
	
	cout << "Enter the 3rd number of the binary number: ";
	cin >> binIn3;
	if(binIn3 == 1){
		binOut3 = 32;
	}
	else
		binOut3 = 0;

	cout << "Enter the 4th number of the binary number: ";
	cin >> binIn4;
	if(binIn4 == 1){
		binOut4 = 16;
	}
	else
		binOut4 = 0;

	cout << "Enter the 5th number of the binary number: ";
	cin >> binIn5;
	if(binIn5 == 1){
		binOut5 = 8;
	}
	else
		binOut5 = 0;

	cout << "Enter the 6th number of the binary number: ";
	cin >> binIn6;
	if(binIn6 == 1){
		binOut6 = 4;
	}
	else
		binOut6 = 0;

	cout << "Enter the 7th number of the binary number: ";
	cin >> binIn7;
	if(binIn7 == 1){
		binOut7 = 2;
	}
	else 
		binOut7 = 0;

	cout << "Enter the 8th number of the binary number: ";
	cin >> binIn8;
	if(binIn8 == 1){
		binOut8 = 1;
	}
	else
		binOut8 = 0;

	//Add all the binary -> decimal numbers together
	binTotal = binOut1 + binOut2 + binOut3 + binOut4 + binOut5 + binOut6 + binOut7 + binOut8;
	
	//Print the binary -> total
	cout << "The decimal conversion is: " << binTotal << endl;

	//Get input for dec -> binary/octal conversion 
	cout << "Now enter a decimal value that is less then 255: ";
	cin >> decIn;

	//Decimal conversion to 8 digit binary number
	cout << "Decimal -> Binary: ";
	for(count = 7; count >= 0; count--){
		conDecBin[count] = decIn/pow(2,count);
		decBin[count] = conDecBin[count]%2; 
		cout << decBin[count];
	}
	cout << endl;
	
	//Decimal conversion to octal nubmer
	cout << oct << "Decimal -> Octal: " << decIn << endl;	
	
	//Get input for oct -> binary/decimal conversion
	cout << "Finally, enter an octal value that is less then 377: ";
	cin >> oct >> octalIn;	

	//Octal conversion to decimal number
	cout << dec << "Octal -> Decimal: " << octalIn << endl;	

	//Octal conversion to 8 digit binary number using cin decimal conversion
	cout << "Octal -> Binary: ";
	for(count = 7; count >= 0; count--){
		conOctBin[count] = octalIn/pow(2,count);
		octBin[count] = conOctBin[count]%2;
		cout << octBin[count];
	}	

	cout << endl;

	return 0;
}
