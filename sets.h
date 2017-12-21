#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class sets
{
private:
	vector <int> setA, setB, setU, setR;
	int Abegin, Aend, Bbegin, Bend, Ubegin, Uend, Rbegin, Rend;
	void Union();
	void intersect();
	void diff(vector<int> x, vector<int> y);
	void complement(vector<int>x);
	void printR();
	bool ispresent(int x, vector<int>y);
public:
	sets();
	void choose();
	~sets();
};