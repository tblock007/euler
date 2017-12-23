//DESCRIPTION: We exploit the observation that tot(n) can be obtained 
// by multiplying n by (p - 1) / p for each prime p that divides n.  This 
// implies that we can multiply the smallest primes together until we exceed 
// 1000000.  The result will maximize the quotient.

#include <iostream>
#include <time.h>
#include <math.h>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

bitset<10000010> pf;
vi primes;

void sieve(ll n) {
	pf.set();
	pf[0] = pf[1] = false;
	for (ll i = 2; i <= n; i++) {
		if (pf[i]) {
			for (ll j = i * i; j <= n; j += i) {
				pf[j] = false;
			}
			primes.push_back((int)i);
		}
	}

}


int main()
{
	sieve(1000000);

	ll prod = 1;
	for (int i = 0; i < primes.size(); i++) {
		prod *= primes[i];
		if (prod > 1000000) {
			prod /= primes[i];
			break;
		}
	}

	cout << prod << endl;
	cin.get();

	return 0;
}