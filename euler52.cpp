//DESCRIPTION: In order for x and 6x to have the same digits, the first digit of x must be 1.  Otherwise, 6x would have one more digit than x.  From there, we can do a brute force search.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check6(int a)
{
	string c = to_string(a);
	string temp;
	sort(c.begin(), c.end());

	for (int i = 6; i >= 2; i--)
	{
		temp = to_string(i * a);
		sort(temp.begin(), temp.end());
		if (c.compare(temp) != 0)
			return false;
	}

	return true;
}

int main()
{
	int n = 1;
	while (1)
	{
		n *= 10;
		for (int i = n; i < 10 * n; i++)
		{
			if (check6(i))
			{
				cout << i;
				cin.get();
				return 0;
			}
		}
	}

	cin.get();
	return 0;
}