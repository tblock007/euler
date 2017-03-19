//DESCRIPTION: Brute force approach.

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> primes;

int ndpf(int n)
{
	int a = n;
	vector<int> df;
	int pi = 0;

	while (a != 1)
	{		
		if (primes[pi] * primes[pi] > a)
		{
			df.push_back(a);
			a = 1;
		}

		if ((a % primes[pi]) == 0)
			df.push_back(primes[pi]);

		while ((a % primes[pi]) == 0)
			a /= primes[pi];

		pi++;
	}
	return df.size();
}


int main()
{
	
	ifstream file("primes.txt");
	int t = 0;
	while (t < 100000)
	{
		file >> t;
		primes.push_back(t);
	}
	file.close();

	int i = 2;
	int c = 0;
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;

	while (1)
	{	
		int n = ndpf(i);

		if (n == 4)
			c++;
		else
			c = 0;

		if (c == 4)
		{
			cout << (i - 3);
			cin.get();
			return 0;
		}
		
		i++;
	}

	cin.get();
	return 0;
}