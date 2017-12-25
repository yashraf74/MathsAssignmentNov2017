#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class diophantineEq
{
	double a = 1, b = 1, c = 1, d = 1, e, f, valA, valB, valC, valD;
	double *arrA, *arrB, *arrC, *arrD;
	int i = 0, j = 0, k = 0, l = 0;
	
	/*
	The values for the variables should be the following:
	a = 95800
	b = 217519
	c = 414560
	d = 422481
	Plug it in as initializers for the variables to check that the program is working fine.
	*/
	
public:
	diophantineEq();
	void calcDiophEq();
	~diophantineEq();
};

