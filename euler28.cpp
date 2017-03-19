//DESCRIPTION: Some simple analysis of the spiral reveals a simple arithmetic-like series for the diagonals, which can be divided into sets of four. For each set of four, rather than add each number individually, we can just compute the average of the four and add.

#include <iostream>

using namespace std;

int main()
{
	int sum = 1;
	int d = 2;
	int m = 0;

	int a = 1; // a tracks the values from the center to the upper-right diagonal
	while (a < 1001*1001)
	{
		m = a + 5 * d / 2; // average of the next four terms to be added
		sum += 4 * m;
		a += 4 * d;
		d += 2;
	}

	cout << sum;
	cin.get();
	return 0;
}