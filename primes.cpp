#include "primes.h"

primes::primes()
{
	cout << "\t**IS P A PRIME? (P = n^2 + n + 41; for all n < 1000)**\n\n";
}

bool primes::isprime(int n)
{
	for (int i = 2; i <= n / 2; ++i)
		if (n % i == 0)
			return false;
	return true;
}

void primes::primechecker()
{
	int p;
	vector<int>notprimes; //values foe p that aren't primes
	vector<int>valN; // value for n where p isn't a prime
	for (int n = 0; n < 1000; n++)
	{
		p = pow(n,2) + n + 41;
		if (isprime(p) != true)
		{
			notprimes.push_back(p);
			valN.push_back(n);
		}
	}
	sort(notprimes.begin(), notprimes.end());
	notprimes.erase(unique(notprimes.begin(), notprimes.end()), notprimes.end());

	for (int i = 0; i != notprimes.size(); i++)
		cout << notprimes[i] << "  is not a prime.\t" << "(at n=" << valN[i] << ")" << endl;
}
