//DESCRIPTION: Stores 2 and the primes that contain only odd digits in a sorted set.  Then, for each prime, it checks all cyclic permutations to determine if the criterion is satisfied.

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

set<int> primes;
int p10[] = { 1, 10, 100, 1000, 10000, 100000 };

bool ic(int a)
{
	int nd; // number of digits
	int t = 10;
	for (nd = 1; nd <= 6; nd++)
	{
		if (t > a)
			break;
		t *= 10;
	}

	for (int i = 0; i < (nd - 1); i++)
	{
		a = (a % 10) * p10[nd - 1] + (a / 10);
		if (find(primes.begin(), primes.end(), a) == primes.end())
			return false;
	}

	return true;
}

bool iod(int a)
{
	while (a != 0)
	{
		if ((a % 2) == 0)
			return false;
		a /= 10;
	}

	return true;
}

int main()
{
	ifstream file("primes.txt");
	int p = 0;
	primes.insert(2);
	while (p < 1000000)
	{
		file >> p;
		if (iod(p))
			primes.insert(p);
	}
	file.close();

	int count = 0;
	for (set<int>::iterator i = primes.begin(); i != primes.end(); i++)
	{
		if (ic(*i))
			count++;
	}

	cout << count;

	cin.get();
	return 0;
}