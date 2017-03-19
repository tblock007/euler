//DESCRIPTION: Overflow is clearly a problem here.  Instead of adding directly, we first note that when adding a hundred 50-digit numbers, the last 35 digits are very unlikely to have an effect on the first 10 digits of the sum.  Therefore, we only read in the first 15 digits of each number and add them.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string input;
	long long sum = 0;

	ifstream file("input.txt");
	for (int i = 0; i < 100; i++)
	{
		getline(file, input);
		sum += stoll(input.substr(0, 15));
	}
	file.close();

	string output = to_string(sum);
	cout << output.substr(0, 10);

	cin.get();
	return 0;
}