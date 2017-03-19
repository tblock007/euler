//DESCRIPTION: Implements Zeller's Congruence to determine the day of the week of the first of every month within the given range.

#include <iostream>

using namespace std;

int main()
{
	int count = 0;

	int w;
	int mm;
	int c;
	int yy; //modified year
	int yyy; //modified year of the century

	int d = 1;
	for (int y = 1901; y <= 2000; y++)
	{
		for (int m = 3; m <= 14; m++)
		{
			if (m > 12)
				yy = y - 1;
			else
				yy = y;
			yyy = yy % 100;
			
			c = yy / 100;
			mm = (13 * (m + 1)) / 5;

			w = (d + mm + yyy + (yyy / 4) + (c / 4) + 5*c) % 7;

			if (w == 1)
			{
				count++;
			}
		}
	}

	cout << count;

	cin.get();
	return 0;
}