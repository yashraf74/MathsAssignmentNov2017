#pragma once
#include <iostream>
using namespace std;

class matrixmultip
{
	int mat1rows, mat1cols, mat2rows, mat2cols, resultrows, resultcols;
	int **matrix1, **matrix2, **result;
	void quikmafs();

public:
	matrixmultip();
	void printresult();
	~matrixmultip();
};

