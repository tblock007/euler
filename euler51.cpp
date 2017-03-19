//DESCRIPTION: The number of digits replaced must be a multiple of 3, or else at least 3 of the resulting numbers will be divisble by 3.  We therefore can check primes in increasing order, and check the family if we find a prime with three 0's, 1's, or 2's.  We use a naive prime check here because we are doing relatively few checks.

#include <iostream>
#include <fstream>

using namespace std;

bool ip(int a)
{
	if (a % 2 == 0)
		return false;

	for (int d = 3; d*d <= a; d += 2)
	{
		if (a % d == 0)
			return false;
	}

	return true;
}

int countd(int a, int d)
{
	int count = 0;
	int digit = 1;
	int ones = 0;

	while (a != 0)
	{
		if (a % 10 == d)
		{
			count++;
			ones += digit;
		}
		digit *= 10;
		a /= 10;
	}
	
	if (count >= 3)
		return ones;
	else
		return 0;
}

int main()
{
	int min = 100000000;

	for (int f = 0; f <= 2; f++)
	{
		ifstream file("primes.txt");
		int t = 0;
		while (t < min)
		{
			file >> t;
			int ones = countd(t, f);
			if (ones != 0)
			{
				int npc = 0;
				for (int i = 1; i <= 9-f; i++)
				{
					if (!ip(t + i*ones))
						npc++;
					if (npc > 2-f)
						break;
				}
				if (npc == 2-f)
				{
					if (t < min)
						min = t;
					break;
				}
			}
		}
		file.close();
	}

	cout << min;
	cin.get();
	return 0;
}