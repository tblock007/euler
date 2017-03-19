//DESCRIPTION: Dynamic programming approach.

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	long long tracking[20];
	long long maxsum[20];
	int read[20];
	int maxvalue;

	for (int i = 0; i < 20; i++)
	{
		tracking[i] = 0;
		maxsum[i] = 0;
		read[i] = 0;
	}

	ifstream file("input.txt");

	for (int row = 0; row < 15; row++)
	{
		for (int i = 0; i <= row; i++)
		{
			file >> read[i];
			maxsum[i] = max(tracking[i],tracking[i-1]) + read[i];
		}

		maxvalue = 0;
		for (int i = 0; i <= row; i++)
		{
			tracking[i] = maxsum[i];
			if (maxsum[i] > maxvalue)
				maxvalue = maxsum[i];
		}
		
	}

	file.close();

	cout << maxvalue;

	cin.get();
	return 0;
}