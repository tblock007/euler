//DESCRIPTION: For each prime, keep track of all 2-prime, 3-prime, and 4-prime sets that can be made for the prime and primes smaller than it.  It just so happens that the first 5-prime set found in this way has the lowest sum, but this is not guaranteed.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> primes;
vector<vector<int>> s2;
vector<vector<int>> s3;
vector<vector<int>> s4;

bool ip(int a)
{
	for (int i = 0; primes[i] * primes[i] <= a; i++)
	{
		if (a % primes[i] == 0)
			return false;
	}
	return true;
	
}

int concat(int a, int b)
{
	string result = to_string(a) + to_string(b);
	return stoi(result);
}

int main()
{

	int t = 0;
	ifstream file("primes.txt");
	while (t < 100000)
	{
		file >> t;
		primes.push_back(t);
	}

	// for each prime starting at 3
	for (int c = 1; c < primes.size(); c++)
	{
		// check for new 2-sets
		for (int d = 1; d < c; d++)
		{
			if (ip(concat(primes[c], primes[d])) && ip(concat(primes[d], primes[c])))
			{
				vector<int> n;
				n.push_back(primes[d]); 
				n.push_back(primes[c]);
				s2.push_back(n);
			}			
		}

		// check for new 3-sets
		for (int i2 = 0; i2 < s2.size(); i2++)
		{
			if (ip(concat(primes[c], s2[i2][0])) && ip(concat(s2[i2][0], primes[c])) && ip(concat(primes[c], s2[i2][1])) && ip(concat(s2[i2][1], primes[c])))
			{
				vector<int> n;
				n.push_back(s2[i2][0]);
				n.push_back(s2[i2][1]);
				n.push_back(primes[c]);
				s3.push_back(n);
			}

		}

		// check for new 4-sets
		for (int i3 = 0; i3 < s3.size(); i3++)
		{
			if (ip(concat(primes[c], s3[i3][0])) && ip(concat(s3[i3][0], primes[c])) && ip(concat(primes[c], s3[i3][1])) && ip(concat(s3[i3][1], primes[c])) && ip(concat(primes[c], s3[i3][2])) && ip(concat(s3[i3][2], primes[c])))
			{
				vector<int> n;
				n.push_back(s3[i3][0]);
				n.push_back(s3[i3][1]);
				n.push_back(s3[i3][2]);
				n.push_back(primes[c]);
				s4.push_back(n);
			}
		}

		// check for new 5-sets
		for (int i4 = 0; i4 < s4.size(); i4++)
		{
			if (ip(concat(primes[c], s4[i4][0])) && ip(concat(s4[i4][0], primes[c])) && ip(concat(primes[c], s4[i4][1])) && ip(concat(s4[i4][1], primes[c])) && ip(concat(primes[c], s4[i4][2])) && ip(concat(s4[i4][2], primes[c])) && ip(concat(primes[c], s4[i4][3])) && ip(concat(s4[i4][3], primes[c])))
			{
				cout << "FOUND " << primes[c] << " " << s4[i4][0] << " " << s4[i4][1] << " " << s4[i4][2] << " " << s4[i4][3] << " => " << primes[c] + s4[i4][0] + s4[i4][1] + s4[i4][2] + s4[i4][3] << endl;
				cin.get();
			}
		}

		
	}

	cin.get();
	return 0;
}