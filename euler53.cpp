//DESCRIPTION: Dynamic programming approach to compute nCr values.  For each row, we can stop as soon as we see a value greater than one million, as we can compute the number of values greater than one million at that point.

#include <iostream>

using namespace std;

long long c[101][101];

long long choose(int n, int r)
{
	if (c[n][r] != -1)
		return c[n][r];

	c[n][r] = choose(n - 1, r) + choose(n - 1, r - 1);
	return c[n][r];
}

int main()
{
	int count = 0;

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
			c[i][j] = -1;
		c[i][0] = 1;
		c[i][i] = 1;
	}


	for (int n = 0; n < 101; n++)
	{
		// find the first r value in the row that exceeds one million
		int f = 0;
		for (int r = 0; r <= n; r++)
		{
			int c = choose(n, r);
				if (c > 1000000)
				{
					f = r;
					break;
				}
		}
		

		// add the contributions from this row
		if (f != 0)
			count += n - f - f + 1;

	}

	cout << count;

	cin.get();
	return 0;
}