//DESCRIPTION: Classic dynamic programming approach.  Assumes input file is 
// piped in as stdin.

#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main()
{
	clock_t time;
	time = clock();

	vvll optimal = vvll(101, vll(101, 0)); // stores the max sum ending at a given position in the row

	for (int i = 1; i < 101; i++) {
		for (int j = 1; j <= i; j++) {
			ll temp; cin >> temp;
			optimal[i][j] = temp + max(optimal[i - 1][j - 1], optimal[i - 1][j]);
		}
	}

	cout << *(max_element(optimal[100].begin(), optimal[100].end())) << endl;

	time = clock() - time;
	cout << "\nTime elapsed: " << ((double)time) / CLOCKS_PER_SEC;
	cin.get();
	return 0;
}