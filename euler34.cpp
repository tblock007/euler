//DESCRIPTION: Brute force, other than finding an appropriate upper bound.  No 8-digit number could satisfy the criterion because 8 * 9! is only 7-digits.  Thus, we choose 7 * 9! = 2540160.

#include <iostream>

using namespace std;


int f[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int sumf(int a)
{
	int sum = 0;
	while (a != 0)
	{
		sum += f[a % 10];
		a /= 10;
	}
	return sum;
}

int main()
{
	int sum = 0;

	for (int i = 10; i <= 2540160; i++)
	{
		if (i == sumf(i))
			sum += i;
	}

	cout << sum;
	cin.get();
	return 0;
}