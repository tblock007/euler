//DESCRIPTION: Brute force approach.  Note that to obtain the list of divisors, we only need to check up to sqrt(n).

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
	vector<int> amicable;
	int sum = 0;

	for (int i = 1; i < 10000; i++)
	{
		if (find(amicable.begin(), amicable.end(), i) == amicable.end())
		{
			if (i == sum_divisors(sum_divisors(i)) && (i != sum_divisors(i)))
			{
				amicable.push_back(i);
				amicable.push_back(sum_divisors(i));
			}
		}
	}

	for (vector<int>::iterator i = amicable.begin(); i != amicable.end(); i++)
		sum += *i;

	cout << sum;

	cin.get();
	return 0;
}