//DESCRIPTION: Simple brute force approach.

#include <iostream>

using namespace std;

int main()
{
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 1; i <= 100; i++)
	{
		sum1 += i;
		sum2 += i*i;
	}

	sum1 = sum1 * sum1;

	cout << (sum1 - sum2);

	cin.get();
	return 0;
}