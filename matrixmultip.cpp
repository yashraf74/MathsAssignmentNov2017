#include "matrixmultip.h"

//constructor reads two matrices and checks for their dimensions befor multiplication, then initalizes the "result" matrix.
matrixmultip::matrixmultip()
{
	cout << "\t**TWO MATRICES MULTIPLIER**\n\n";
	cout << "Matrix 1: \n";
	cout << "\tenter number of rows  "; cin >> mat1rows;
	cout << "\tenter number of columns  "; cin >> mat1cols;
	matrix1 = new int*[mat1rows];
	for (int i = 0; i < mat1rows; i++)
		matrix1[i] = new int[mat1cols];
	for (int R = 0; R < mat1rows; R++)
		for (int C = 0; C < mat1cols; C++)
		{
			cout << "\tenter value of cell: [" << R + 1 << "]" << "[" << C + 1 << "]:  ";
			cin >> matrix1[R][C];
		}
	cout << "\nMatrix 2: \n";
	cout << "\tenter number of rows  "; cin >> mat2rows;
	cout << "\tenter number of columns  "; cin >> mat2cols;
	while (mat1cols != mat2rows)
	{
		cout << "\a\t Dimension error!\n\t Number of rows in Matrix 2 must equal number of columns in Matrix 1.\n\t please re-enter Matrix 2's dimensions.\n";
		cout << "\tenter number of rows  "; cin >> mat2rows;
		cout << "\tenter number of columns  "; cin >> mat2cols;
	}
	matrix2 = new int*[mat2rows];
	for (int i = 0; i < mat2rows; i++)
		matrix2[i] = new int[mat2cols];
	for (int R = 0; R < mat2rows; R++)
		for (int C = 0; C < mat2cols; C++)
		{
			cout << "\tenter value of cell: [" << R + 1 << "]" << "[" << C + 1 << "]:  ";
			cin >> matrix2[R][C];
		}
	resultrows = mat1rows; resultcols = mat2cols;
	result = new int*[resultrows];
	for (int i = 0; i < resultrows; i++)
		result[i] = new int[resultcols];
}

//function that multiplies the two matrices and stores them in "result" matrix.
void matrixmultip::quikmafs()
{
	for (int R = 0; R < resultrows; R++)
		for (int C = 0; C < resultcols; C++)
		{
			int a = 0;
			for (int i = 0; i < resultrows; i++)
				a += (matrix1[R][i] * matrix2[i][C]);
			result[R][C] = a;
		}
}

//prints out the "result" matrix.
void matrixmultip::printresult()
{
	quikmafs();
	cout << "\n   Matrix1 * Matrix2 equals:\n" << endl;
	for (int R = 0; R <resultrows; R++)
	{
		cout << "\t";
		for (int C = 0; C <resultcols; C++)
			cout << result[R][C] << "  ";
		cout << endl;
	}
	cout << endl;
}

matrixmultip::~matrixmultip()
{
	delete[] matrix1;
	delete[] matrix2;
	delete[] result;
}
