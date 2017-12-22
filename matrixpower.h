#pragma once
#include <iostream>
using namespace std;
class matrixpower
{
	int matrows, matcols, npower;
	int **matrix, **temp, **result;
	void quikmafs();
	void printresult(int**x);
	void printidentity();

public:
	matrixpower();
	~matrixpower();
};

