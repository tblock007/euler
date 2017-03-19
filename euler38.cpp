//DESCRIPTION: We know from the problem that the answer is greater than 918273645.  Since the first product is a multiplication by unity, the integer must start with 9.  It cannot be 2 digits because (1,2,3) would be 8 digits while (1,2,3,4) would be 11.  Similarly, it cannot be 3 digits.  It follows that the answer must be the concatenated product of 9xxx and (1,2), which can now be solved by brute force.

#include <iostream>

using namespace std;

int ipdp(int a)
{
	bool hit[9] = { false, false, false, false, false, false, false, false, false };

	int n = a;
	while (n != 0)
	{
		if ((hit[(n % 10) - 1]) || (n % 10) == 0)
			return false;
		else
			hit[(n % 10) - 1] = true;

		n /= 10;
	}

	n = 2 * a;
	while (n != 0)
	{
		if ((hit[(n % 10) - 1]) || (n % 10) == 0)
			return false;
		else
			hit[(n % 10) - 1] = true;

		n /= 10;
	}

	return true;
}

int main()
{
	int n;

	for (int i = 9876; i >= 9123; i--)
	{
		if (ipdp(i))
		{
			cout << i << 2 * i << endl;
			break;
		}
	}

	cin.get();
	return 0;
}