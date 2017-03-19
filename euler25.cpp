//DESCRIPTION: Maintain two arrays of digits to represent the large integers.  Compute the sequence until the number fills up the array of 1000 digits.

#include <iostream>

using namespace std;

int main()
{
	int digits1[1000];
	int digits2[1000];

	for (int i = 0; i < 1000; i++)
	{
		digits1[i] = 0;
		digits2[i] = 0;
	}
	digits1[0] = 1;
	digits2[0] = 1;


	int index = 2;
	int t;
	int carry = 0;


	while (digits2[999] == 0)
	{
		// add the last two numbers
		for (int d = 0; d < 1000; d++)
		{
			t = digits1[d] + digits2[d] + carry;
			if (t > 9)
			{
				t = t - 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}

			digits1[d] = digits2[d];
			digits2[d] = t;
		}

		index++;

	}

	cout << index;

	cin.get();
	return 0;
}