//DESCRIPTION: Note that 9-digit and 8-digit pandigital numbers will always be divisible by 3, and therefore cannot be prime.  We only need to check 1-, 4-, and 7-digit numbers.

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool ipd47(int a)
{
	string n = to_string(a);
	sort(n.begin(), n.end());

	if ((n.compare("1234") == 0) || (n.compare("1234567") == 0))
		return true;

	return false;
}



int main()
{
	ifstream file("primes.txt");
	int t = 0;

	int max = 0;

	while (t < 7654321)
	{
		file >> t;
		if (((t >= 1234) && (t <= 4321)) || ((t >= 1234567) && (t <= 7654321)))
		{
			if (ipd47(t))
				max = t;
		}
	}
	file.close();

	cout << max;
	cin.get();
	return 0;
}