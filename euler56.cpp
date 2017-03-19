//DESCRIPTION: Uses the hand multiplication algorithm developed for problem 20 to iterate through all combinations.

#include <iostream>

using namespace std;

int sdm(int* output, int a, int b, int carry) // computes a*b + carry, places the unit value in output and returns the carry
{
	int result = a*b + carry;
	*output = result % 10;
	return result / 10;
}

int main()
{
	int digits[200];
	int pp1[200];
	int pp2[200];

	for (int i = 0; i < 200; i++)
	{
		digits[i] = 0;
		pp1[i] = 0;
		pp2[i] = 0;
	}
	digits[0] = 9;
	digits[1] = 9;

	int d1, d2, carry1, carry2, sum;
	int max = 0;

	for (int a = 2; a <= 99; a++)
	{
		for (int i = 0; i < 200; i++)
		{
			digits[i] = 0;
			pp1[i] = 0;
			pp2[i] = 0;
		}
		digits[0] = a % 10;
		digits[1] = a / 10;

		d1 = a % 10;
		d2 = a / 10;

		for (int b = 2; b <= 99; b++)
		{
			//compute the partial products
			carry1 = 0;
			carry2 = 0;
			for (int j = 0; j < 200; j++)
			{
				carry1 = sdm(&pp1[j], digits[j], d1, carry1);
				carry2 = sdm(&pp2[j + 1], digits[j], d2, carry2);
			}

			//sum the partial products
			carry1 = 0;
			for (int j = 0; j < 200; j++)
			{
				digits[j] = pp1[j] + pp2[j] + carry1;
				carry1 = 0;
				if (digits[j] > 9)
				{
					digits[j] = digits[j] % 10;
					carry1 = 1;
				}
			}
			
			sum = 0;
			for (int j = 0; j < 200; j++)
			{
				sum += digits[j];
			}
			if (sum > max)
			{
				max = sum;
			}

		}
	}
	cout << max;
	cin.get();
	return 0;
}