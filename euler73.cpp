//DESCRIPTION: A brute force approach, which is possible since d is relatively small.  
// For each denominator, count the number of numerators such that the resulting fraction 
// is a simple fraction between 1/3 and 1/2.

#include <iostream>
#include <time.h>
#include <set>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main()
{
	clock_t time;
	time = clock();

	int count = 0;
	for (int d = 2; d <= 12000; d++) {

		// compute the starting and ending numerators to check
		int start = (d / 3) + 1; // start at the numerator just above 1/3
		int end = d / 2;
		if (2 * end == d) {
			end--; // if denominator is even, then discount the computed end and only go to one before instead
		}

		for (int n = start; n <= end; n++) {
			if (gcd(n, d) == 1) {
				count++;
			}
		}
	}

	cout << count << endl;	

	time = clock() - time;
	cout << "\nTime elapsed: " << ((double)time) / CLOCKS_PER_SEC;
	cin.get();
	return 0;
}