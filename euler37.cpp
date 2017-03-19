//DESCRIPTION: Similar approach to problem 35.  Read in primes while filtering out potential candidates (all odd digits except for the first, which could be 2) and then run the truncation test.  Upper bound of 1000000 for the 11 primes was a guess that happens to work.

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

set<int> primes;
int p10[] = { 1, 10, 100, 1000, 10000, 1000000 };

bool it(int a)
{
	int nd;

	if (a > 99999) nd = 6;
	else if (a > 9999) nd = 5;
	else if (a > 999) nd = 4;
	else if (a > 99) nd = 3;
	else if (a > 9) nd = 2;
	else return false;

	//check left truncation
	int n = a;
	for (int i = 0; i < nd - 1; i++)
	{
		n = n % p10[nd - 1 - i];
		if (find(primes.begin(), primes.end(), n) == primes.end())
			return false;
	}

	//check right truncation
	n = a;
	while (n > 9)
	{
		n /= 10;
		if (find(primes.begin(), primes.end(), n) == primes.end())
			return false;
	}

	return true;
}

bool icand(int a)
{
	while (a != 0)
	{
		if (a == 2)
			return true;

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
	while (p < 1000000)
	{
		file >> p;
		if (icand(p))
			primes.insert(p);
	}
	primes.erase(p);
	file.close();

	int sum = 0;
	for (set<int>::iterator i = primes.begin(); i != primes.end(); i++)
	{
		if (it(*i))
			sum += *i;
	}

	cout << sum;

	cin.get();
	return 0;
}