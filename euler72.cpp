//DESCRIPTION: This solution is based on the observation that the number 
// of simple fractions present in the sequence of a given diameter is equal 
// to the totient function of the denominator.  THus, we simply sum up 
// the totient values of 2 to 1000000.

#include <iostream>
#include <time.h>
#include <math.h>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

bitset<1000010> pf;
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

ll tot(ll n) {
	ll ans = n;
	ll rem = n;
	for (int i = 0; primes[i] * primes[i] <= n; i++) {
		if (n % primes[i] == 0) {
			ans /= primes[i];
			ans *= primes[i] - 1;
			while (rem % primes[i] == 0) {
				rem /= primes[i];
			}
			if (rem == 1) {
				break;
			}
		}
	}
	if (rem != 1) {
		// remainder is the last prime
		ans /= rem;
		ans *= rem - 1;
	}
	return ans;
}

int main()
{
	clock_t time;
	time = clock();

	sieve(1000000);

	ll sum = 0;
	for (int d = 2; d <= 1000000; d++) {
		sum += tot(d);
	}
	cout << sum << endl;

	time = clock() - time;
	cout << "\nTime elapsed: " << ((double)time) / CLOCKS_PER_SEC << " seconds.";
	cin.get();

	return 0;
}