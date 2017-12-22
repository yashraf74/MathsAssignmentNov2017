#include "primes.h"
#include "diophantineEq.h"
#include "echform.h"
#include "matrixmultip.h"
#include "sets.h"
#include "matrixpower.h"

void main()
{
	int choice = 0; char quit = 'a';
	while (choice != -1)
	{
		system("CLS");
		cout << " Please enter a task number from the following tasks: \n\n";
		cout << "\t(1) Prove that a^4 + b^4 + c^4 = d^4 has a sloution for a, b, c, and d.\n";
		cout << "\t(2) Multiply two matrices together.\n";
		cout << "\t(3) Raise a matrix to a power.\n";
		cout << "\t(4) Solving a system of linear equations; reduce the augmented matrix to reduced echelon form\n";
		cout << "\t(7) Operations on sets.\n";
		cout << "\t(8) Is P, such that: P = n^2 + 2n + 41, not a prime? (for n<1000).\n";
		cout << "\t  **ENTER -1 TO QUIT**\n  ";
		cin >> choice;
		if (choice == -1)
			break;
		while (choice < 1 || choice > 8 || choice == 5 || choice ==6)
		{
			cout << "\n Wrong choice. Please choose from the displayed numbers only.\n  ";
			cin >> choice;
		}

		//if statements to choose task "class";
		{
			if (choice == 1)
			{
				system("CLS");
				// TASK 1:
				diophantineEq obj1;
				obj1.calcDiophEq();
			}
			if (choice == 2)
			{
				system("CLS");
				//TASK 2:
				matrixmultip obj2;
				obj2.printresult();
			}
			if (choice == 3)
			{
				system("CLS");
				// TASK 3:
				matrixpower obj3;
				obj3.quikmafs();
			}
			if (choice == 4)
			{
				system("CLS");
				// TASK 4:echform obj4;
				echform obj4;
				obj4.EchForm();
			}
			if (choice == 7)
			{
				system("CLS");
				// TASK 7:
				sets obj7;
				obj7.choose();
			}
			if (choice == 8)
			{
				system("CLS");
				// TASK 8:
				primes obj8;
				obj8.primechecker();
			}
		}

		cout << "\n  **Rerun the program? (Y/N)**\n  ";
		while (choice != -1)
		{
			cin >> quit;
			if (quit == 'y' || quit == 'Y') {
				choice = 0;
				break;
			}
			else if (quit == 'n' || quit == 'N')
				choice = -1;
			else
				cout << "  Enter \"Y\" to rerun program, or \"N\" to quit. \n  ";
		}
	}
}
