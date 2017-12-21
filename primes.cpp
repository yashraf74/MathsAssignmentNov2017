#include "primes.h"

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
	vector<int>notprimes;
	for (int n = 0; n < 1000; n++)
	{
		p = n ^ 2 + n + 41;
		if (isprime(p) != true)
			notprimes.push_back(p);
	}
	sort(notprimes.begin(), notprimes.end());
	notprimes.erase(unique(notprimes.begin(), notprimes.end()), notprimes.end());

	for (int i = 0; i != notprimes.size(); i++)
		cout << notprimes[i] << "  is not a prime. " << endl;
}
