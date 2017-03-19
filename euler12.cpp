//DESCRIPTION: We recognize that computing the number of divisors of some number is essentially a combinatorics problem in selecting prime factors.  With this in mind, it is a reasonable assumption that the first triangle number with 500 divisors will have a prime factorization that consists of only the first few primes.  Here, we choose ten, and exploit this assumption to quickly prime factor each candidate triangle number.

#include <iostream>
#include <vector>

using namespace std;

const int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
vector<int> factor(int a);

int main()
{
	int n = 2;
	int nd;
	int triangle;
	vector<int> exponents;

	while (1)
	{
		triangle = n * (n - 1) / 2;
		exponents = factor(triangle);

		nd = 1;
		for (int i = 0; i < 10; i++)
		{
			nd *= (exponents[i] + 1);
		}
		
		if (nd > 500)
		{
			cout << triangle;
			cin.get();
			return 0;
		}

		n++;
	}

	cin.get();
	return 0;
}

vector<int> factor(int a)
{
	vector<int> exponents(10);

	int tbf = a;

	int exp;

	for (int i = 0; i < 10; i++)
	{
		exp = 0;
		while ((tbf % primes[i]) == 0)
		{
			tbf /= primes[i];
			exp++;
		}
		exponents[i] = exp;
	}

	return exponents;
}