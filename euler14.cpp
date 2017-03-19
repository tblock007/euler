//DESCRIPTION: Brute force.  This could be optimized by storing a lookup table of previous values, but it should be fast enough for searching up to a million.

#include <iostream>

using namespace std;

int collatz_length(int a);

int main()
{

	int max = 0;
	int candidate = 0;
	int length = 0;

	for (int i = 2; i < 1000000; i++)
	{
		length = collatz_length(i);
		if (length > max)
		{
			max = length;
			candidate = i;
		}

	}

	cout << candidate;

	cin.get();
	return 0;
}

int collatz_length(int a)
{
	int count = 1;
	long long cand = a;

	while (cand != 1)
	{
		if ((cand % 2) == 0)
			cand /= 2;
		else
			cand = 3 * cand + 1;

		count++;
	}

	return count;
}