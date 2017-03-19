//DESCRIPTION: For 100 terms, we take 33 groups of the continued fraction of e.  In other words, that last three terms we include are 1, 66, 1.  It is simple to construct the 100th convergent by starting from the 100th term in the sequence, and following (n/d) -> (d/ds+n), where s is the partial value.

#include <iostream>
#include <time.h>
#include "big_int.h"

using namespace std;

int main()
{
	clock_t time;
	time = clock();

	big_int n;
	big_int d;
	big_int s;
	big_int t;
	big_int temp;

	n.set(0);
	d.set(1);

	for (int k = 33; k >= 1; k--)
	{
		s = 1;
		t = n;
		n = d;
		big_int::multiply(d, s, temp, s.size());
		big_int::add(temp, t, d);

		s = 2 * k;
		t = n;
		n = d;
		big_int::multiply(d, s, temp, s.size());
		big_int::add(temp, t, d);

		s = 1;
		t = n;
		n = d;
		big_int::multiply(d, s, temp, s.size());
		big_int::add(temp, t, d);
	}

	s = 2;
	big_int::multiply(d, s, temp, s.size());
	big_int::add(n, temp, n);
	cout << "Numerator: ";
	n.print();
	cout << endl;
	cout << "Sum of digits: " << n.sum_digits();
	


	time = clock() - time;
	cout << "\nTime elapsed: " << ((double)time) / CLOCKS_PER_SEC;
	cin.get();
	return 0;
}