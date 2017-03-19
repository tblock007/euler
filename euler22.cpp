//DESCRIPTION: Read in and compute.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	char name[256];
	vector<string> names;
	string temp;


	ifstream file("names.txt");
	while (file.good())
	{
		file.getline(name, 256, ',');
		temp = string(name);
		names.push_back(temp.substr(1, temp.length() - 2));
	}
	file.close();

	sort(names.begin(), names.end());

	int sum = 0;
	int name_score;
	for (int i = 0; i < names.size(); i++)
	{
		name_score = 0;
		for (int j = 0; j < names[i].length(); j++)
			name_score += names[i].at(j) - 'A' + 1;

		name_score *= (i + 1);

		sum += name_score;
	}

	cout << sum;

	cin.get();
	return 0;
}