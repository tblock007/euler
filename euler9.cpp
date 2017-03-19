//DESCRIPTION: Exhaustive search is quadratic time, which is acceptable for input on the order of 1000.

#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	for (a = 1; a <= 500; a++)
	{
		for (b = 1; b <= 500; b++)
		{
			c = 1000 - a - b;

			if ((a*a + b*b) == c*c)
			{
				cout << a*b*c;
				cin.get();
				return 0;
			}
		}
	}

	return 0;
}