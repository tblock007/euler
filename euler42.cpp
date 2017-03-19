//DESCRIPTION: Create a list of triangle numbers.  Then, compute the word value for each word and check if it is in the list.

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	//create lookup table for triangle numbers
	set<int> triangle;

	for (int n = 1; n <= 100; n++)
		triangle.insert(n * (n + 1) / 2)

	int count = 0;
	char word[20];

	ifstream file("words.txt");
	while (file.good())
	{
		file.getline(word, 20, ',');

		int i = 1;
		int sum = 0;
		while (word[i] != '"')
		{
			sum += word[i] - 'A' + 1;
			i++;
		}

		if (find(triangle.begin(), triangle.end(), sum) != triangle.end())
			count++;

	}
	file.close();

	cout << count;
	cin.get();
	return 0;
}