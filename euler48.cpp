//DESCRIPTION: Brute force, but with an extra step of taking mod 10^10 with each step to keep things small.  Note that naive fast exponentiation does not work for the opow() function here, because you can still overflow a 64-bit long.

#include <iostream>

using namespace std;

long long opow(int b, int e)
{
	long long result = b;

	for (int i = 1; i < e; i++)
	{
		result = (result * b) % 10000000000;
	}

	return result;
}


int main()
{
	long long sum = 0;
	
	for (int i = 1; i <= 1000; i++)
	{
		sum = (sum + opow(i, i)) % 10000000000;
	}

	cout << sum;

	cin.get();
	return 0;
}