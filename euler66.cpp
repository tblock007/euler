//DESCRIPTION: A brute force approach can be easily implemented, but will be incredibly slow, if it finds the answer at all.  Instead, we recognize that the Diophantine equation as a Pell Equation that can be solved by determining the continued fraction of sqrt(D).  The (x,y) pair that solves the Pell equation for a given D is given by the numerator and denominator of a certain convergent, determined by the period of the partial quotients.  

#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>

#include "big_int.h"

using namespace std;

int main()
{
	clock_t time;
	time = clock();

	big_int max;
	max = 9;
	int cand = 5;
	int s = 2;
	for (int D = 277; D <= 1000; D++)
	{
		if (s*s == D)
		{
			s++;
			continue;
		}

		double sD = sqrt(D);


		//determine the x and y pair via convergent algorithm
		vector<double> r;

		r.push_back(sD);
		int target = 2 * floor(r[0]);

		int p = 1;
		while (true)
		{
			r.push_back(1 / (r[p - 1] - floor(r[p - 1])));
			if (((int)r[p]) == target)
				break;
			p++;
		}
		// problem in this algorithm - accurate of r terms?  find better way to generate continued fraction?

		cout << p << endl;
		for (int t = 0; t < r.size(); t++)
		{
			cout << r[t] << endl;
		}
		cin.get();

		int t;
		if (p % 2 == 0)
			t = p - 1;
		else
			t = 2 * (p - 1) + 1;
		
		// now determine the numerator and denominator
		vector<big_int> x;
		vector<big_int> y;
		big_int r0;
		big_int r1;
		r0 = (long long)floor(r[0]);
		r1 = (long long)floor(r[1]);
		x.push_back(r0);
		x.push_back(r0 * r1 + big_int(1));
		y.push_back(big_int(1));
		y.push_back(r1);
		
		for (int i = 2; i <= t; i++)
		{
			big_int ai;
			if (i >= r.size())
			{
				ai = (long long) floor(r[i - r.size() + 1]);
			}
			else
			{
				ai = (long long) floor(r[i]);
			}

			x.push_back(ai * x[i - 1] + x[i - 2]);
			y.push_back(ai * y[i - 1] + y[i - 2]);
		}

		if (x[t].compare(max) == 1)
		{
			cand = D;
			max = x[t];

			cout << D << " ";
			x[t].print();
			cout << endl;
		}
	}

	cout << cand;

	time = clock() - time;
	cout << "\nTime elapsed: " << ((double)time) / CLOCKS_PER_SEC;
	cin.get();
	return 0;
}