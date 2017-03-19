//DESCRIPTION: Brute force approach.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



//generates the next number in the sequence
string nextit(string a)
{
	string rev = a;
	reverse(rev.begin(), rev.end());
	string result;
	
	char d1, d2, r;
	int c = 0;

	for (int i = rev.size() - 1; i >= 0; i--)
	{
		d1 = rev[i] - '0';
		d2 = a[i] - '0';
		r = d1 + d2 + c;
		if (r >= 10)
		{
			r = r - 10 + '0';
			c = 1;
		}
		else
		{
			r = r + '0';
			c = 0;
		}

		result.push_back(r);
	}


	if (c == 1)
		result.push_back('1');

	reverse(result.begin(), result.end());

	return result;
}


bool il(string a)
{
	string current = a;
	string rev;

	for (int i = 0; i < 49; i++)
	{
		current = nextit(current);
		rev = current;
		reverse(rev.begin(), rev.end());

		if (current.compare(rev) == 0)
			return false;
	}
	return true;
}


int main()
{
	int count = 0;
	
	for (int i = 1; i < 10000; i++)
	{
		if (il(to_string(i)))
		{
			count++;
		}
	}

	cout << count;
	cin.get();
	return 0;
}