//DESCRIPTION: Brute force checks, which is fine because of the small search space.  We check for permutations first because it eliminates candidates more quickly.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool ip(int a, int b)
{
	string c1 = to_string(a);
	string c2 = to_string(b);

	sort(c1.begin(), c1.end());
	sort(c2.begin(), c2.end());

	if (c1.compare(c2) == 0)
		return true;

	return false;
}

int main()
{
	vector<int> primes;

	ifstream file("primes.txt");
	int t = 0;
	while (t <= 9973) // last four-digit prime
	{
		file >> t;
		if (t > 1487)
			primes.push_back(t);
	}

	for (int i = 0; i < primes.size(); i++)
	{
		for (int j = i + 1; j < primes.size(); j++)
		{
			int diff = primes[j] - primes[i];
			if (diff + primes[j] > 9999)
				break;

			if (!ip(primes[i], primes[j]) || !ip(primes[i],primes[j]+diff))
				continue;

			int p3 = 0;
			for (int k = j + 1; k < primes.size(); k++)
			{
				if (primes[k] > diff + primes[j])
					break;

				if (primes[k] == diff + primes[j])
				{
					p3 = primes[k];
					break;
				}
			}

			if (p3 != 0)
			{
				cout << primes[i] << primes[j] << p3 << endl;
				cin.get();
				return 0;
			}
		}
	}

	cin.get();
	return 0;
}