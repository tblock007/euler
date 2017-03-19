//DESCRIPTION: Again, this problem is simple with precomputed primes.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	long long sum = 0;
	int n = 0;

	ifstream file("primes.txt");

	while (n < 2000000)
	{
		sum += n;
		file >> n;
	}
	file.close();

	cout << n << endl;

	cout << sum;

	cin.get();
	return 0;
}