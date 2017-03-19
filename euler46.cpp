//DESCRIPTION: Brute force approach.  We do not load in primes from the file here because the algorithm is doing primes checks in any case.  By storing primes as we go, we are able to search primes more quickly than if we preloaded some large number of them.

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	set<int> primes;
	primes.insert(2);
	
	bool found, prime;
	for (int c = 3; ; c += 2)
	{
		prime = true;
		for (set<int>::iterator i = primes.begin(); i != primes.end(); i++)
			if (c % *i == 0)
				prime = false;

		if (prime)
		{
			primes.insert(c);
		}
		else
		{
			found = false;
			for (int s = 1; 2 * s*s < c; s++)
			{
				if (find(primes.begin(), primes.end(), c - 2 * s*s) != primes.end())
				{
					found = true;
					break;
				}
			}

			if (!found)
			{
				cout << c;
				cin.get();
				return 0;
			}
		}
	}

	cin.get();
	return 0;
}