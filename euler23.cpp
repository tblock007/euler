//DESCRIPTION: Get a vector of abundant numbers and use it to figure out which numbers are able to expressed as a sum.

#include <iostream>
#include <vector>

using namespace std;

int sum_divisors(int a)
{
	int sum = 1;

	int i;
	for (i = 2; i*i < a; i++)
	{
		if (a % i == 0)
		{
			sum += i;
			sum += a / i;
		}
	}

	if (i*i == a)
		sum += i;

	return sum;
}

int main()
{
	bool marked[28123];
	for (int i = 0; i < 28123; i++)
		marked[i] = false;

	vector<int> abundant;
	int sum = 0;

	for (int i = 12; i < 28123; i++)
		if (sum_divisors(i) > i)
			abundant.push_back(i);

	int n = abundant.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if ((abundant[i] + abundant[j]) <= 28123)
				marked[abundant[i] + abundant[j] - 1] = true;
		}
	}

	for (int i = 0; i < 28123; i++)
		if (!marked[i])
		{
			sum += (i + 1);
		}
	
	cout << sum;

	cin.get();
	return 0;
}