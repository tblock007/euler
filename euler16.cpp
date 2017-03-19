//DESCRIPTION: Keep track of each digit individually.  2^1000 = 2^10^100 ~ 10^3^100 = 10^300, so 350 digits should be sufficient.

#include <iostream>
#include <string>

using namespace std;

bool double_digit(int * a)
{
	if (*a < 5)
	{
		*a = 2 * *a;
		return false;
	}
	else
	{
		*a = 2 * (*a - 5);
		return true;
	}
}

int main()
{
	int digits[350];
	int sum = 0;

	digits[0] = 1;
	for (int i = 1; i < 350; i++)
		digits[i] = 0;

	bool carry_flag = false;;

	for (int exp = 0; exp < 1000; exp++)
	{
		
		for (int i = 0; i < 350; i++)
		{
			if (digits[i] < 5)
			{
				digits[i] *= 2;
				if (carry_flag)
					digits[i] += 1;
				carry_flag = false;
			}
			else
			{
				digits[i] = (digits[i] - 5) * 2;
				if (carry_flag)
					digits[i] += 1;
				carry_flag = true;
			}
		}

		
	}

	for (int i = 0; i < 350; i++)
		sum += digits[i];

	cout << sum;

	cin.get();
	return 0;
}