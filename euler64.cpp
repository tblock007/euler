//DESCRIPTION: Simple implementation of the algorithm described in the problem.  At each step, check the newly obtained fraction against all other past fractions to determine the period.  An interesting fact about these continued fractions that was learned after solving this problem: the sequence is guaranteed to repeat as soon as the whole number part is 2*floor(sqrt(n)), which would have made it easier to find the period.

#include <iostream>
#include <time.h>
#include <vector>
#include <math.h>

using namespace std;

vector<vector<int>> trips;
vector<int> it;

int main()
{
	clock_t time;
	time = clock();

	int s = 2;
	int count = 0;
	for (int n = 2; n <= 10000; n++)
	{
		trips.clear();
		if (s*s == n)
		{
			s++;
			continue;
		}
		int b = floor(sqrt(n));
		int c = 1;
		it.clear();
		it.push_back(b);
		it.push_back(1);
		trips.push_back(it);

		int d = 0;
		int e = 0;
		int A = 0;
		
		int period = -1;
		while (period == -1)
		{
			if ((n - (b*b)) % c != 0)
			{
				cout << "not divisible by c..."; cin.get();
			}
			d = (n - (b*b)) / c;
			A = floor((sqrt(n) + b) / d);
			e = -1 * (b - d * A);

			for (int i = trips.size() - 1; i >= 0; i--)
			{
				if ((e == trips[i][0]) && (d == trips[i][1]))
					period = trips.size() - i;
			}

			it.clear();
			it.push_back(e);
			it.push_back(d);
			trips.push_back(it);

			b = e;
			c = d;
		}
		
		if (period % 2 == 1)
			count++;

	}
	

	cout << count << endl;
	time = clock() - time;
	cout << "\nTime elapsed: " << ((double)time) / CLOCKS_PER_SEC;
	cin.get();
	return 0;
}