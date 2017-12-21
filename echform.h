#pragma once
#include <iostream>
using namespace std;

class echform
{
	int nRows, nColumns;
	int **matrix;

public:
	echform();
	void EchForm();
	~echform();
private:
	void quikmafs(int **m, int x, int y);
	void printmat();
};

