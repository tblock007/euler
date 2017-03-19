//DESCRIPTION: Uses bit operations to determine if the binary representation is a palindrome.  Then, generate all palindromes under 1000000 and check their binary representations.

#include <iostream>

using namespace std;

bool ibp(int a)
{
	int bm = 0b10000000000000000000; // assumed 1 <= a < 1000000

	// advance to first 1 in the binary expression
	while ((bm & a) == 0)
		bm = bm >> 1;

	int m = 0b1;
	while (bm > 1)
	{
		if ((((bm & a) == 0) && (m & a) != 0) || (((bm & a) != 0) && (m & a) == 0))
			return false;

		m = m << 1;
		bm = bm >> 1;
	}

	return true;
}

int main()
{
	int sum = 0;

	int c3, c4, c5, c6;

	// generate one- and two-digit palindromes
	for (int i = 1; i <= 9; i++)
	{
		if (ibp(i))
			sum += i;
		if (ibp(11 * i))
			sum += 11 * i;
	}

	// generate three- and four-digit palindromes
	for (int i = 10; i <= 99; i++)
	{
		c3 = 10 * i + (i / 10);
		c4 = 100 * i + 10 * (i % 10) + (i / 10);
		if (ibp(c3))
			sum += c3;
		if (ibp(c4))
			sum += c4;
	}

	// generate five- and six-digit palindromes
	for (int i = 100; i <= 999; i++)
	{
		c5 = 100 * i + 10 * ((i / 10) % 10) + (i / 100);
		c6 = 1000 * i + 100 * (i % 10) + 10 * ((i / 10) % 10) + (i / 100);
		if (ibp(c5))
			sum += c5;
		if (ibp(c6))
			sum += c6;
	}

	cout << sum;

	cin.get();
	return 0;
}