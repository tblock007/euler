//DESCRIPTION: From examination of the cases n=0 and n=1, three things are clear that help us reduce the search space.  b must be a positive prime.  a must be odd.  If a is negative, it must satisfy |a| < (b-1).  From there, we simply search all pairs.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int max = 0;
	int fa, fb;
	bool sp;

	bool is_prime[1000000];
	for (int i = 0; i < 1000000; i++)
		is_prime[i] = false;
	
	int t;
	ifstream file("primes.txt");
	for (int i = 0; i < 78498; i++)  // primes less than a million
	{
		file >> t;
		is_prime[t - 1] = true;
	}
	file.close();

	for (int b = 1; b < 1000; b++)
	{
		if (!is_prime[b - 1])
			continue;

		for (int a = 999; -1 * a < (b - 1); a = a - 2)
		{
			sp = true;
			int n = 0;

			while (sp)
			{
				if (!is_prime[n*n + a*n + b - 1])
					sp = false;
				n++;
			}


			if (n > max)
			{
				max = n;
				fa = a;
				fb = b;
			}
		}
	}

	cout << fa * fb;

	cin.get();
	return 0;
}