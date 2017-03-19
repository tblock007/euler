//DESCRIPTION: Generate cubes and sort them into vectors depending on the number of digits.  Then, by sorting the digits and comparing within vectors, we can count permutations.  Note that there is a possibility that this fails to return the SMALLEST sum, since we are sorting by permuted digits, but this does not happen for n = 5.

#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<long long>> cubes;
vector<long long> first;

long long sort_digits(string n3)
{
	sort(n3.begin(), n3.end());
	return stoll(n3);
}

int main()
{
	clock_t time;
	time = clock();

	for (long long n = 22; n <= 99999; n++)
	{
		string n3 = to_string(n*n*n);
		int dc = n3.length();

		if ((dc - 5) >= cubes.size())
		{
			cubes.push_back(vector<long long>());
			first.push_back(n);
		}

		cubes[dc - 5].push_back(sort_digits(n3));
	}

	// find number of digits for the cube with five cube permutations, and the sorted digits
	int d5 = 0;
	long long sorted;
	for (int n = 0; n < cubes.size(); n++)
	{
		sort(cubes[n].begin(), cubes[n].end());
		long long cand = cubes[n][0];
		int count = 1;
		for (int i = 1; i < cubes[n].size(); i++)
		{
			if (cubes[n][i] == cand)
			{
				count++;
			}
			else
			{
				count = 1;
				cand = cubes[n][i];
			}

			if (count == 5) 
			{
				d5 = (n + 5);
				sorted = cand;
				break;
			}
		}
		if (d5 != 0)
			break;
	}

	long long c = first[d5 - 5];
	while (1)
	{
		if (sorted == sort_digits(to_string(c*c*c)))
		{
			cout << (c * c * c);
			break;
		}
		c++;
	}




	time = clock() - time;
	cout << "\nTime elapsed: " << ((double)time) / CLOCKS_PER_SEC << " seconds.";
	cin.get();
	return 0;
}