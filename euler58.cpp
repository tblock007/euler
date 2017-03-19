//DESCRIPTION: Brute force approach.

#include <iostream>

using namespace std;

bool ip(int a)
{
	for (int d = 2; d * d <= a; d++)
	{
		if (a % d == 0)
			return false;
	}
	return true;
}


int main()
{
	int d = 1;
	int s = 1;

	int pc = 0;
	int t = 1;

	while (1)
	{
		s += 2;

		for (int i = 1; i <= 4; i++)
		{
			d += (s - 1);
			if (ip(d))
				pc++;
			t++;
		}

		if (pc * 10 < t)
		{
			cout << s;
			cin.get();
			return 0;
		}
	}

	cin.get();
	return 0;
}