//DESCRIPTION: Classic dynamic programming approach.  Assumes input file is 
// piped in as stdin.

#include <iostream>
#include <time.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

bool is_magic(vi order) {
	if (order.size() != 9) {
		cout << "improper size" << endl;
		return false;
	}

	// we can fix the starting 10 (must be on the outside due to 16-digit requirement) without loss of generality
	order.insert(order.begin(), 10);

	int sum1 = order[0] + order[5] + order[6];
	int sum2 = order[1] + order[6] + order[7];
	int sum3 = order[2] + order[7] + order[8];
	int sum4 = order[3] + order[8] + order[9];
	int sum5 = order[4] + order[9] + order[5];

	if (sum1 == sum2 && sum1 == sum3 && sum1 == sum4 && sum1 == sum5) {
		return true;
	}
	return false;
}

string stringify(vi order) {
	if (order.size() != 9) {
		cout << "improper size" << endl;
		return false;
	}
	order.insert(order.begin(), 10);

	string ret = "";
	vi::iterator minit = min_element(order.begin(), order.begin() + 5);
	int start_index = minit - order.begin();
	for (int i = 0; i < 5; i++) {
		ret += to_string(order[start_index]) + to_string(order[start_index + 5]) + to_string(order[((start_index + 6) % 5) + 5]);
		start_index = (start_index + 1) % 5;
	}
	return ret;
}

int main()
{
	clock_t time;
	time = clock();


	ll max = -1;
	vi order = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	do {
		if (is_magic(order)) {
			ll s = stoll(stringify(order));
			if (s > max)
				max = s;
		}
	} while (next_permutation(order.begin(), order.end()));

	cout << max << endl;
	time = clock() - time;
	cout << "\nTime elapsed: " << ((double)time) / CLOCKS_PER_SEC;
	cin.get();
	return 0;
}