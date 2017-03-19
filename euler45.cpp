//DESCRIPTION: First of all, every hexagonal number is a triangle number, so we only need to find numbers common to the pentagonals and the hexagonals.  Then, noting that both sequences are simply sums of arithmetic series, we can easily generate both sequences via addition.

#include <iostream>

using namespace std;

int main()
{

	long long pent = 1;
	long long hex = 1;

	long long psum = 1;
	long long hsum = 1;

	while (1)
	{
		if (pent == hex)
		{
			cout << pent << endl;
			cin.get();
		}

		if (pent < hex)
		{
			psum += 3;
			pent += psum;
		}
		else
		{
			hsum += 4;
			hex += hsum;
		}
	}
	cin.get();
	return 0;
}