//DESCRIPTION: We are looking for sums with 22 terms or more.  This means we can restrict our search to primes less than ~46000, since any sum of >22 terms with a prime greater than 46000 will necessarily be greater than 1000000.  Furthermore, the largest series possible has 546 terms, since 2+3+5+...3943 > 1000000, and 3943 is the 547th prime.  So, we check sequences of 546, 545, 544, etc., until we have one that satisfies the criterion.  In order to do help do this in reasonable time, we first precompute all terms in the sequence 2, 2+3, 2+3+5, etc.

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	set<int> primes;

	ifstream file("primes.txt");
	int t = 0;
	while (t < 1000000)
	{
		file >> t;
		primes.insert(t);
	}

	// compute sums 2+3+5+7+...
	vector<int> sums;
	int sum = 0;
	sums.push_back(sum);
	for (set<int>::iterator i = primes.begin(); i != primes.end(); i++)
	{
		if (*i > 46000)
		{
			break;
		}
		else
		{
			sum += *i;
			sums.push_back(sum);
		}
	}

	int n = 546;
	int s, e;

	while (1)
	{
		s = 0;
		e = s + n;
		while (sums[e] - sums[s] < 1000000)
		{
			if (find(primes.begin(), primes.end(), sums[e] - sums[s]) != primes.end())
			{
				cout << sums[e] - sums[s];
				cin.get();
				return 0;
			}
			s++;
			e++;
		}
		n--;
	}
	
	cin.get();
	return 0;
}