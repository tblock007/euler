//DESCRIPTION: Some quick checking tells us that 7-digit numbers can never satisfy the criterion because 7* 9^5 is not 7 digits.  In fact, an upper bound on our search space is 6* 9^5 = 354294.

#include <iostream>

using namespace std;

int sum_of_fifth(int a)
{
	int n = a;
	int d; 
	int sum = 0;

	while (n > 0)
	{
		d = n % 10;
		sum += d * d * d * d * d;
		n /= 10;
	}

	return sum;
}

int main()
{
	int sum = 0;
	for (int a = 10; a <= 354294; a++)
	{
		if (a == sum_of_fifth(a))
			sum += a;
	}

	cout << sum;

	cin.get();
	return 0;
}