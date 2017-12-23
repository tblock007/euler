//DESCRIPTION: Since the sequence is strictly increasing, the fraction 
// directly to the left will be closest fraction to 3/7.  We can therefore 
// simply scan the denominators and determine the numerator that gives the 
// closest to 3/7 without exceeding.  Then, we simply take the result that 
// resulted in the lowest error.

#include <iostream>
#include <time.h>
#include <math.h>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef long long ll;



int main()
{
	clock_t time;
	time = clock();

	double mind = 1e300;
	ll ans = -1;
	for (ll d = 2; d <= 1000000; d++) {
		if (d % 7 == 0) {
			continue; // these won't be proper fractions
		}
		double exact = d * 3.0 / 7.0;
		ll numerator = floor(exact);
		double dist = (3.0 / 7.0) - ((double)numerator / d);
		if (dist < mind) {
			mind = dist;
			ans = numerator;
		}
	}
	
	cout << ans << endl;
	time = clock() - time;
	cout << "\nTime elapsed: " << ((double)time) / CLOCKS_PER_SEC << " seconds.";
	cin.get();

	return 0;
}