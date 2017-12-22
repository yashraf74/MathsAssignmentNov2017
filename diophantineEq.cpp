#include "diophantineEq.h"

//the constructors creates 4 arrays for 4 variables with all the integers <= 430000 raised to the power of 4.
diophantineEq::diophantineEq()
{
	cout << "\t**DOES A^4 + B^4 + C^4 HAS A SOLUTION FOR A, B, C, D?**\n\n";
	arrA = new double[430000]; //array to store all the powers of 4 for var A
	arrB = new double[430000]; //array to store all the powers of 4 for var B
	arrC = new double[430000]; //array to store all the powers of 4 for var C
	arrD = new double[430000]; //array to store all the powers of 4 for var D
	for (int count = 0; count <= 430000; count++)
	{
		arrA[count] = pow(a, 4);
		arrB[count] = pow(b, 4);
		arrC[count] = pow(b, 4);
		arrD[count] = pow(b, 4);
		a++; b++; c++; d++;
	}
}

//function that checks for the variables that will satisfy the equation: ( a^4 + b^4 + c^4 = d^4 ).
void diophantineEq::calcDiophEq()
{
	while (l != 430000)
	{
		if (i == 430000) {
			i = 0; j++;
		}
		if (j == 430000) {
			i = 0; j = 0; k++;
		}
		if (k == 430000) {
			i = 0; j = 0; k = 0; l++;
		}
		e = arrA[i] + arrB[j] + arrC[k];
		f = arrD[l];
		if (e == f && arrA[i] != arrB[j] != arrC[k] != arrD[l])
		{
			valA = arrA[i]; valB = arrB[j]; valC = arrC[k]; valD = arrD[l];
			break;
		}
		i++;
	}

	cout << "value of A is:  " << valA << endl;
	cout << "value of B is:  " << valB << endl;
	cout << "value of C is:  " << valC << endl;
	cout << "value of D is:  " << valD << endl;
	
}

diophantineEq::~diophantineEq()
{
	delete[] arrA;
	delete[] arrB;
	delete[] arrC;
	delete[] arrD;
}
