//DESCRIPTION: Minimizing n/phi(n) is equivalent to minimizing the 
// product of (p / (p - 1)) for all prime divisors of n.  A quick 
// program shows that there are no solutions when n only has one prime 
// divisor (i.e., when n is a power of p).  Then, since (p / (p - 1)) > 1 
// for any p, the best we can do occurs when n has two distinct prime factors 
// that are close to sqrt(n).  Some more trial and error shows that 
// numbers with the desired property are not that dense, so we restrict our 
// search to primes less than 5000, which should capture some pairs of primes 
// around sqrt(10000000) ~ 3000.  Thankfully, this does produce an answer.

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

bool is_permutation(string a, string b) {
	vi ac = vi(10, 0);
	vi bc = vi(10, 0);
	for (char c : a) {
		ac[c - '0']++;
	}
	for (char c : b) {
		bc[c - '0']++;
	}
	return (ac == bc);
}


int main()
{
	clock_t time;
	time = clock();

	sieve(10000000);

	/* 
	//running this shows that there are no solutions in the provided range that are powers of primes
	// try powers of primes, starting at primes[4] = 11
	for (int i = 4; i < primes.size(); i++) {
		if (i % 100 == 0)
			cout << "trying " << primes[i] << endl;
		ll prod = primes[i];
		while (prod < 10000000) {
			if (is_permutation(to_string(prod), to_string(prod / primes[i] * (primes[i] - 1)))) {
				cout << prod << "; phi is " << (prod / primes[i] * (primes[i] - 1)) << endl;
				cin.get();
			}
			prod *= primes[i];
		}
	}
	*/

	// try numbers that have two distinct prime factors
	// the 669th prime is 4999, which is a reasonable upper bound, given that we expect the optimal pair to 
	// be around sqrt(10000000) ~ 3000
	// the 169th prime is 1009, which is a reasonable lower bound
	ll minn = 1;
	ll mind = 1e9;
	ll ans = -1;
	for (int i = 669; i >= 169; i--) {
		for (int j = i - 1; j >= 169; j--) {
			//cout << "primes are " << primes[i] << " " << primes[j] << endl;
			ll denom = primes[i] * primes[j];
			ll nom = (primes[i] - 1) * (primes[j] - 1);

			ll base = primes[i];
			while (base < 10000000) {
				ll prod = base * primes[j];
				while (prod < 10000000) {
					//cout << "trying " << prod << endl;
					//cin.get();
					if (is_permutation(to_string(prod), to_string(prod / denom * nom))) {
						if (denom * minn < nom * mind) {
							mind = denom;
							minn = nom;
							ans = prod;
						}
					}
					prod *= primes[j];
				}
				base *= primes[i];
			}
			
		}
	}

	cout << ans << endl; 
	time = clock() - time;
	cout << "\nTime elapsed: " << ((double)time) / CLOCKS_PER_SEC << " seconds.";
	cin.get();

	return 0;
}