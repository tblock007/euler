//DESCRIPTION: Exploits the fact that we know the sequence will have 9 one-digit numbers, 90 two-digit numbers, 900 three-digit numbers, etc.

#include <iostream>

using namespace std;

int d[] = {9, 180, 2700, 36000, 450000, 5400000};
int p10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

int digit(int a)
{
	int n = a;

	if (n < 10)
		return n;

	for (int i = 0; i < 6; i++)
	{
		if ((n - d[i]) > 0)
		{
			n -= d[i];
		}
		else
		{
			int m = i - ((n - 1) % (i + 1));
			n = ((n - 1) / (i + 1));


			int base = p10[i] + n;

			for (int j = 0; j < m; j++)
				base /= 10;
			return (base % 10);
		}
	}

	return -1;
}

int main()
{
	int product = digit(1) * digit(10) * digit(100) * digit(1000) * digit(10000) * digit(100000) * digit(1000000);

	cout << product;

	cin.get();
	return 0;
}