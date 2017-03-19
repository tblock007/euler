//DESCRIPTION: We start from the naive total and then subtract duplicates.  Note that the duplicates are going to occur when one base is an exponent of the other.  Since a and b are limited to 100, we only need to check duplicates for "true" bases 2, 3, 5, 6, 7, 10.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int rb[6] = { 2, 3, 5, 6, 7, 10 };
	vector<int> te; //contains all exponents of the base so we can track duplicates

	int base, be;
	int total = 99 * 99; // the naive number of combinations, from which we will subtract duplicates

	for (int i = 0; i < 6; i++)
	{
		te.clear();

		base = rb[i];
		be = 0; // the max power of the base that we need to check (ie- 6 for base 2 since 2^7 > 100)
		int bt = base;
		while (bt <= 100)
		{	
			bt *= base;
			be++;
		}


		int duplicate = 0;

		for (int j = 0; j < be; j++)
		{
			for (int b = 2; b <= 100; b++)
			{
				int oe = (j + 1) * b;
				if (find(te.begin(), te.end(), oe) != te.end())
				{
					duplicate++;
				}
				else
				{
					te.push_back(oe);
				}
			}
		}

		total -= duplicate;

	}

	cout << total;


	cin.get();
	return 0;
}