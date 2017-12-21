#include "echform.h"

//the constructor reads the augmented matrix form the user.
echform::echform()
{
	cout << "Enter dimension \"N\" of matrix N*N  \n "; cin >> nRows;
	nColumns = nRows + 1;
	matrix = new int*[nRows];
	for (int i = 0; i < nRows; i++)
		matrix[i] = new int[nColumns];
	for (int R = 0; R < nRows; R++)
		for (int C = 0; C < nColumns; C++)
		{
			cout << "   Enter value of cell: [" << R + 1 << "]" << "[" << C + 1 << "]:  ";
			cin >> matrix[R][C];
		}
}

//function that reduces the augmented matrix M to reduced echelon form.
void echform::quikmafs(int ** m, int x, int y)
{
	int lead = 0, **matrix = m, rows = x, col = y;
	while (lead < rows)
	{
		if (matrix[0][0] == 0)
			swap(matrix[0], matrix[1]);
		float d, m;
		for (int r = 0; r < rows; r++)
		{
			d = matrix[lead][lead];
			m = matrix[r][lead] / matrix[lead][lead];
			for (int c = 0; c < col; c++)
			{
				if (r == lead)
					matrix[r][c] /= d;
				else
					matrix[r][c] -= matrix[lead][c] * m;
			}
		}
		lead++;
	}
}

/*
the following function is a function I made when I encountered an error that wouldn't calculate
the reduced echelon form to the end, and I saw that it calculates it correctly when I call the function 
once more and pass the incomplete reduced augmented matrix to it. However, it doesn't always work,
so does the function itself on its own. This is just a temp fix until I figure out where I messed 
things up. 
*/
void echform::EchForm()
{
	quikmafs(matrix, nRows, nColumns);
	quikmafs(matrix, nRows, nColumns);
	printmat();

}

//function that prints the augmented matrix, reduced to low echelon form (supposedly).
void echform::printmat()
{
	cout << "\n\tYour matrix reduced in echelon form:\n" << endl;
	for (int R = 0; R <nRows; R++)
	{
		cout << "\t  ";
		for (int C = 0; C <nColumns; C++)
			cout << matrix[R][C] << "  ";
		cout << endl;
	}
	cout << endl;
}

echform::~echform()
{
	delete[] matrix;
}
