//DESCRIPTION: Although it's not necessary here, I took the opportunity to generate a file of primes, since it's bound to be useful later.  Other than that, it's a simple brute force approach.  We start searching the primes from 800000 and go downwards because 800000 is greater than the square root of the given number, and we are looking or the largest prime factor.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//implement the sieve of eratosthenes to generate primes 
	const int NS = 100000000; //primes up to hundred million
	bool * marked = new bool[NS];

	//initialize
	for (int i = 0; i < NS; i++)
	{
		marked[i] = false;
	}
	marked[0] = true;

	//sieve
	for (int i = 0; i*i < NS; i++)
	{
		if (marked[i])
		{
			continue;
		}
		else
		{
			//we have encountered a prime
			for (int j = i + i + 1; j < NS; j += (i + 1))
			{
				marked[j] = true;
			}
		}
	}

	
	//file output
	ofstream file;
	file.open("primes.txt");
	for (int i = 0; i < NS; i++)
	{
		if (!marked[i])
		{
			file << (i + 1) << endl;
		}
	}
	file.close(); 
	

	for (int i = 800000; i >= 0; i--)
	{
		if (!marked[i])
		{
			if ((600851475143 % (i + 1)) == 0)
			{
				cout << (i + 1);
				cin.get();
			}
		}
	}

	cin.get();
	return 0;
}