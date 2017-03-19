//DESCRIPTION: We can determine whether a number is a pentagon number via quadratic formula.  This gives us constant time evaluation, which allows the entire algorithm to remain quadratic time.  We simply iterate through all pentagonal difference, and stop when we find two pentagonal numbers for that difference that also form a pentagonal sum.

#include <iostream>
#include <math.h>

using namespace std;


bool ip(int a)
{
	int sdet = (int) sqrt(1 + 24 * a) + 0.01;

	if ((sdet * sdet == (1 + 24 * a)) && ((1 + sdet) % 6 == 0))
		return true;

	return false;
}

int main()
{
	int nd = 2;
	while (1)
	{
		int pentdiff = nd * (3 * nd - 1) / 2;
		for (int nt = nd - 1; (nt * (3 * nt - 1) / 2) + pentdiff >= ((nd + 1) * (3 * nd + 2) / 2); nt--)
		{
			int pentt = nt * (3 * nt - 1) / 2;

			//check difference
			if (!ip(pentt + pentdiff))
				continue;

			//check sum
			if (ip(pentt + pentt + pentdiff))
			{
				cout << pentdiff;
				cin.get();
				return 0;
			}
		}
		nd += 1;
	}

	cin.get();
	return 0;
}