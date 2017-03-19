//DESCRIPTION: Brute force approach, but with smarter bounds checking to reduce the search space.  For a given perimeter p, the length of the hypotenuse must be between p/(1+sqrt(2)) ~ 0.41p (theta = 45 degrees) and p/2 (theta = 0 or 90 degrees).

#include <iostream>

using namespace std;

int main()
{
	int hl, hh;
	int count, maxc = 0, maxp;

	int max = 0;
	for (int p = 12; p <= 1000; p++)
	{
		count = 0;

		hl = 41 * p / 100;
		hh = p / 2;

		for (int h = hl; h <= hh; h++)
		{
			for (int a = 1; a <= ((p - h) / 2); a++)
			{
				int b = p - h - a;

				if ((a*a + b*b) == h*h)
					count++;

			}
		}

		if (count > maxc)
		{
			maxc = count;
			maxp = p;
		}
	}

	cout << maxp;
	cin.get();
	return 0;
}