//DESCRIPTION: 100! has fewer digits than 200 digits (which is 100^100), so we keep track of each digit in a 200-int array.  Then, we simply implement the hand multiplication algorithm.  Note that we actually compute 99! so that the multiplier can always be assumed to have two digits, since the final factor of 100 won't change the sum of digits.

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
	digits[0] = 1;

	int d1, d2, carry1, carry2;
	for (int i = 2; i <= 99; i++)
	{
		d1 = i % 10;
		d2 = i / 10;

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

	}

	int sum = 0;
	for (int j = 0; j < 200; j++)
		sum += digits[j];

	cout << sum;



	cin.get();
	return 0;
}