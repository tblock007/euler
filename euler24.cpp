//DESCRIPTION: Determine digits of the permutation from left to right by checking how many full cycles of the remaining digits occur in the steps that remain.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> perm; 

	int factorial[9];
	factorial[0] = 1;
	for (int i = 1; i < 9; i++)
	{
		factorial[i] = factorial[i - 1] * (i + 1);
	}

	vector<int> rd;
	for (int i = 0; i < 10; i++)
		rd.push_back(i);

	int n = 1000000 - 1; //number of permutations left after the 1st
	int cycle;

	for (int i = 0; i < 10; i++)
	{
		cycle = n / factorial[8 - i];
		n = n % factorial[8 - i];
		perm.push_back(rd[cycle]);
		rd.erase(rd.begin() + cycle);
	}

	for (int i = 0; i < perm.size(); i++)
		cout << perm[i];

	cin.get();
	return 0;
}