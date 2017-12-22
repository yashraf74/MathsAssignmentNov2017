#include "matrixpower.h"

//the constructor reads the matrix and it's power, and calls the function that calculates the power.
matrixpower::matrixpower()
{
	cout << "\t**RAISE A MATRIX TO n POWER**\n\n";
	cout << "Matrix: \n";
	cout << "Enter dimension \"N\" of matrix N*N  \n "; cin >> matrows;
	matcols = matrows;
	matrix = new int*[matrows];
	for (int i = 0; i < matrows; i++)
		matrix[i] = new int[matcols];
	for (int R = 0; R < matrows; R++)
		for (int C = 0; C < matcols; C++)
		{
			cout << "\tenter value of cell: [" << R + 1 << "]" << "[" << C + 1 << "]:  ";
			cin >> matrix[R][C];
		}
	result = new int*[matrows];
	for (int i = 0; i < matrows; i++)
		result[i] = new int[matcols];
	temp = new int*[matrows];
	for (int i = 0; i < matrows; i++)
		temp[i] = new int[matcols];
	for (int R = 0; R < matrows; R++)
		for (int C = 0; C < matcols; C++)
			temp[R][C] = matrix[R][C];
	cout << " Enter the power you want for the matrix to be multiplied by:  "; cin >> npower;
}

//function that does the actual calculation and stores the output in another matrix.
void matrixpower::quikmafs()
{
	if (npower == 0)
		printidentity();
	else if (npower < 0)
	{
		/*
		here should go the code of multiplying the inverse of matrix M by "n" times [(M^-1)^n].
		but since that there's something wrong in my implementation of that function (found in
		echform.cpp), then I won't implement it here as it may result in more errors I wouldn't
		be able to handle.
		*/
	}
	else if (npower == 1)
		printresult(matrix);
	else if (npower > 0)
	{
		for (int i = 1; i < npower; i++)
		{
			for (int R = 0; R < matrows; R++)
				for (int C = 0; C < matcols; C++)
				{
					int a = 0;
					for (int j = 0; j < matrows; j++)
						a += (temp[R][j] * matrix[j][C]);
					result[R][C] = a;
				}
			for (int R = 0; R < matrows; R++)
				for (int C = 0; C < matcols; C++)
					temp[R][C] = result[R][C];
		}
		printresult(result);
	}
}

//function to print out the result (output)
void matrixpower::printresult(int**x)
{
	cout << "\n   Matrix M^n equals:\n" << endl;
	for (int R = 0; R < matrows; R++)
	{
		cout << "\t";
		for (int C = 0; C < matcols; C++)
			cout << x[R][C] << "  ";
		cout << endl;
	}
	cout << endl;
}


//function to print out the identity matrix "whenever n = 0".
void matrixpower::printidentity()
{
	cout << "\n   Matrix M^n equals:\n" << endl;
	for (int R = 0; R <matrows; R++)
	{
		cout << "\t";
		for (int C = 0; C < matcols; C++)
		{
			if (R == C)
				cout << 1 << "  ";
			else
				cout << 0 << "  ";
		}
		cout << endl;
	}
	cout << endl;
}


matrixpower::~matrixpower()
{
	delete[] matrix;
	delete[] result;
}
