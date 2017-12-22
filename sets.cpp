#include "sets.h"

//constructor reads the universal set, set A, and set B.
sets::sets()
{
	cout << "\t**OPERATIONS ON SETS**\N\N";
	cout << "Universal set U:\n Enter beginning and ending values for set U respectively:\n"; cin >> Ubegin >> Uend;
	if (Uend < Ubegin)
		swap(Ubegin, Uend);
	for (int i = Ubegin; i <= Uend; i++)
		setU.push_back(i);
	int choose;
	cout << " (1) Enter sets A & B as a range between 2 numbers.\n (2) Enter sets A & B element by element.\n ";
	cin >> choose;
	while (choose < 1 || choose > 2)
	{
		cout << "Wrong choice. please choose between 1 or 2.\n ";
		cin >> choose;
	}
	if (choose == 1)
	{
		cout << "Set A:\n Enter beginning and ending values for set A respectively:\n"; cin >> Abegin >> Aend;
		while (Abegin < Ubegin || Aend > Uend)
		{
			cout << "  The range you entered is out of the Universal set's range.\n";
			cout << "  Please re-enter: beginning and ending values for set A respectively:\n"; cin >> Abegin >> Aend;
		}
		for (int i = Abegin; i <= Aend; i++)
			setA.push_back(i);
		cout << "Set B:\n Enter beginning and ending values for set B respectively:\n"; cin >> Bbegin >> Bend;
		while (Bbegin < Ubegin || Bend > Uend)
		{
			cout << "  The range you entered is out of the Universal set's range.\n";
			cout << "  Please re-enter: beginning and ending values for set B respectively:\n"; cin >> Bbegin >> Bend;
		}
		for (int i = Bbegin; i <= Bend; i++)
			setB.push_back(i);
	}
	else
	{
		int valA, valB;
		cout << "Set A:\n  Enter size of set A:  "; cin >> Abegin;
		cout << "  Enter values for set A: \n";
		for (int i = 1; i <= Abegin; i++)
		{
			cin >> valA;
			while (valA < Ubegin || valA > Uend)
			{
				cout << "  The value you entered is out of the Universal set's range.\n";
				cout << "  Please re-enter: values for set A: \n"; cin >> valA;
			}
			setA.push_back(valA);
		}
		cout << "Set B:\n  Enter size of set B:  "; cin >> Bbegin;
		cout << "  Enter values for set B: \n";
		for (int i = 1; i <= Bbegin; i++)
		{
			cin >> valB;
			while (valB < Ubegin || valB > Uend)
			{
				cout << "  The value you entered is out of the Universal set's range.\n";
				cout << "  Please re-enter: values for set B: \n"; cin >> valB;
			}
			setB.push_back(valB);
		}
	}
	sort(setA.begin(), setA.end());
	sort(setB.begin(), setB.end());
	cout << "\n Choose the operation you want to do on sets A and B: \n  (1) set A union set B \"AUB\" \n";
	cout << "  (2) set A intersect set B \"A *and* B\" \n  (3) set A differnece set B \"A-B\" \n";
	cout << "  (4) set B difference set A \"B-A\" \n  (5) set A complement \"A`\"\n  (6) set B complement \"B`\"\n ";
}

//function that acts as a menu to choose operation from.
void sets::choose()
{
	int choose, exit = 0; cin >> choose;
	while (exit != -1)
	{
		while (choose < 1 || choose > 6)
		{
			cout << "Wrong choice. Choose between 1 and 6.\n ";
			cin >> choose;
		}
		switch (choose)
		{
		case (1):
			Union();
			break;
		case (2):
			intersect();
			break;
		case (3):
			diff(setA, setB);
			break;
		case (4):
			diff(setB, setA);
			break;
		case (5):
			complement(setA);
			break;
		case (6):
			complement(setB);
			break;
		}
		cout << "\n Do another operation?\n  (enter \"-1\" to exit)\n ";
		cin >> choose; exit = choose;
	}
}

//function that calculates set A union set B, stores output in set R.
void sets::Union()
{
	setR.erase(setR.begin(), setR.end());
	for (int i = 0; i < setA.size(); i++)
			setR.push_back(setA[i]);
	for (int i = 0; i < setB.size(); i++)
	{
		if (!ispresent(setB[i], setA))
			setR.push_back(setB[i]);
	}
	printR();
}

//function that calculates set A intersect set B, stores output in set R.
void sets::intersect()
{
	setR.erase(setR.begin(), setR.end());
	for (int i = 0; i < setA.size(); i++)
		if (ispresent(setA[i], setB))
			setR.push_back(setA[i]);
	for (int i = 0; i < setB.size(); i++)
		if (ispresent(setB[i], setA) && !ispresent(setB[i],setR))
			setR.push_back(setB[i]);
	printR();
}

//function that calculates set X difference set Y (A-B or B-A), stores output in set R. 
void sets::diff(vector<int> x, vector<int> y)
{
	setR.erase(setR.begin(), setR.end());
	for (int i = 0; i < x.size(); i++)
		if (!ispresent(x[i], y))
			setR.push_back(x[i]);
	printR();
}

//function that calculates complement of set X (A` or B`), stores output in set R.
void sets::complement(vector<int>x)
{
	setR.erase(setR.begin(), setR.end());
	for (int i = 0; i < setU.size(); i++)
		if (!ispresent(setU[i],x))
			setR.push_back(setU[i]);
	printR();
}

//function that prints out the set R.
void sets::printR()
{
	if (setR.empty())
		cout << "\n The result is an empty set:\n  {}\n";
	else
	{
		sort(setR.begin(), setR.end());
		cout << "\n The result is the following set:\n  {";
		for (int i = 0; i < setR.size(); i++)
			cout << setR[i] << ", ";
		cout << "} \n";
	}
}

//this function helps in implementing other functions; checks if value X is present in vector Y.
bool sets::ispresent(int x, vector<int> y)
{
	for (int i = 0; i < y.size(); i++)
		if (x == y[i])
			return true;
	return false;
}

sets::~sets()
{
	setA.erase(setA.begin(), setA.end());
	setB.erase(setB.begin(), setB.end());
	setU.erase(setU.begin(), setU.end());
	setR.erase(setR.begin(), setR.end());
}
