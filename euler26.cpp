//DESCRIPTION: For each divisor, keep track of the remainders in order to determine cycle length.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int maxd;
	int max = 0;
	int length;
	int r;
	int t;
	bool cf;

	vector<int> pd;

	for (int d = 2; d < 1000; d++)
	{
		pd.clear();
		r = 1;
		cf = false;
		while (!cf)
		{
			r = (r * 10) % d;

			if (r == 0)
			{
				t = 0;
				break;
			}

			t = 0;
			while (!cf && t < pd.size())
			{
				t++;
				if (pd[pd.size() - t] == r)
					cf = true;
			}

			pd.push_back(r);
		}

		length = t;

		if (length > max)
		{
			max = length;
			maxd = d;
		}
	}

	cout << maxd;

	cin.get();
	return 0;
}