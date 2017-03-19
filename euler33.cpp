//DESCRIPTION: Since the problem is limited to reduced fractions that have one digit in the numerator and denominator, we can simply iterate through these fractions.  In order to reduce the search space further, we note that we can never use the digit 0, and in order to avoid trivial cases, the cancelled digit must be in the tens digit on one side, and the unit digit in the other.

#include <iostream>

using namespace std;

int main()
{
	int np = 1;
	int dp = 1;
	
	for (int n = 1; n <= 8; n++)
	{
		for (int d = n + 1; d <= 9; d++)
		{
			for (int a = 1; a <= 9; a++)
			{
				//check appending to n, prepending to d
				if (((n * (10 * a + d)) == ((10 * n + a) * d)))
				{
					np *= n;
					dp *= d;
				}

				//check preprending to n, appending to d
				if (((n * (10 * d + a)) == ((10 * a + n) * d)))
				{
					np *= n;
					dp *= d;
				}
			}


		}
	}

	cout << np << endl << dp << endl;

	cin.get();
	return 0;
}