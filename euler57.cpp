//DESCRIPTION: Some quick analysis reveals that the fraction following n / d is simply (n + 2d) / (n + d).  It is therefore trivial to generate the sequence and count the number of fractions that satisfy the criterion.  To deal with overflow, we store the numerator and denominator as strings and do the addition manually.

#include <iostream>
#include <string>

using namespace std;

string sum(string a, string b)
{
	string result;

	int c = 0;
	int r;
	for (int i = 0; i < a.size(); i++)
	{
		r = a[i] - '0' + b[i] - '0' + c;
		if (r >= 10)
		{
			r -= 10;
			c = 1;
		}
		else
		{
			c = 0;
		}
		result.push_back(r + '0');
	}

	if (c == 1)
		result.push_back(1);

	return result;
}

int digits(string a)
{
	int i = a.size() - 1;
	while (i >= 0)
	{
		if (a[i] != '0')
			break;
		i--;
	}
	return (i + 1);
}

int main()
{
	string n;
	string d;
	string temp;

	n.push_back('1');
	d.push_back('1');
	
	for (int i = 1; i < 500; i++)
	{
		n.push_back('0');
		d.push_back('0');
	}


	int count = 0;

	for (int i = 0; i < 1000; i++)
	{
		
		temp = sum(n, d);
		n = sum(temp, d);
		d = temp;
		
		if (digits(n) > digits(d))
		{
			count++;
		}
	}

	cout << count;
	cin.get();
	return 0;
}