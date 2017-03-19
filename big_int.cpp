#include "big_int.h"



big_int::big_int()
{
	for (int i = 0; i < BIG_INT_SIZE; i++)
		n[i] = 0;
}


big_int::~big_int()
{
}


void big_int::set(long long a)
{
	for (int i = 0; i < BIG_INT_SIZE; i++)
	{
		n[i] = a % 10;
		a /= 10;
	}
}

void big_int::operator=(long long a)
{
	set(a);
}

void big_int::add(big_int& a, big_int& b, big_int& c)
{
	int carry = 0;
	int temp;
	for (int i = 0; i < BIG_INT_SIZE; i++)
	{
		temp = a.n[i] + b.n[i] + carry;
		if (temp >= 10)
		{
			c.n[i] = temp % 10;
			carry = 1;
		}
		else
		{
			c.n[i] = temp;
			carry = 0;
		}
	}
}

void big_int::multiply(big_int& a, big_int& b, big_int& c, int size_b)
{
	for (int i = 0; i < BIG_INT_SIZE; i++)
		c.n[i] = 0;

	big_int pp;
	for (int d = 0; d < size_b; d++)
	{
		sdm(a, b.n[d], pp, d);
		add(c, pp, c);
	}
	
}

void big_int::print()
{
	bool start = false;
	for (int i = BIG_INT_SIZE - 1; i >= 0; i--)
	{
		if (n[i] != 0)
		{
			start = true;
		}

		if (start)
			cout << n[i];
	}
}

int big_int::sum_digits()
{
	int sum = 0;
	for (int i = 0; i < BIG_INT_SIZE; i++)
	{
		sum += n[i];
	}
	return sum;
}

int big_int::size()
{
	for (int i = BIG_INT_SIZE - 1; i >= 0; i--)
	{
		if (n[i] != 0)
			return (i + 1);
	}
	return 0;
}

void big_int::sdm(big_int& a, int d, big_int& c, int offset)
{
	for (int i = 0; i < BIG_INT_SIZE; i++)
		c.n[i] = 0;

	int carry = 0;
	int temp;
	for (int i = 0; i < BIG_INT_SIZE; i++)
	{
		temp = a.n[i] * d + carry;
		carry = temp / 10;
		if (i+offset < BIG_INT_SIZE)
			c.n[i + offset] = temp % 10;
	}
}