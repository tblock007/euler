//DESCRIPTION: Here we exploit the list of primes generated in problem #3, assumed to be contained in primes.txt

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream file("primes.txt");
	int n = 0;

	for (int i = 1; i <= 10001; i++)
	{
		file >> n;
	}
	file.close();

	cout << n;

	cin.get();
	return 0;
}