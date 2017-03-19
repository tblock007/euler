//DESCRIPTION: Such a product must be the result of a one-digit times a four-digit or a two-digit times a three-digit, so we have a reduces search space.  After that, apply brute force.  This probably runs a little slower than most solutions due to the string sorting, but still runs in well under a minute.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool ip(int a, int b)
{
	int p = a*b;

	string s = to_string(a) + to_string(b) + to_string(p);
	sort(s.begin(), s.end());

	if (s.compare("123456789") == 0)
	{
		return true;
	}

	return false;
}

int main()
{
	vector<int> products;

	for (int i = 1; i <= 9; i++)
		for (int j = 1234; j <= 9876; j++)
			if (ip(i, j) && (find(products.begin(), products.end(), i*j) == products.end()))
				products.push_back(i*j);

	for (int i = 12; i <= 98; i++)
		for (int j = 123; j <= 987; j++)
			if (ip(i, j) && (find(products.begin(), products.end(), i*j) == products.end()))
				products.push_back(i*j);

	int sum = 0;
	for (int i = 0; i < products.size(); i++)
		sum += products[i];
	
	cout << sum;

	cin.get();
	return 0;
}