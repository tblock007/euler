//DESCRIPTION: Dynamic programming approach.

#include <iostream>

using namespace std;

int ways[8][200]; //[i][j] gives number of ways to make (j+1) using lowest (i+1) coins

int numways(int c, int j)
{
	if ((j < 0) || (c <= 0))
		return 0;

	if (j == 0)
		return 1;

	if (ways[c - 1][j - 1] != -1)
		return ways[c - 1][j - 1];
	
	int w = 0;
	if (c >= 1) w += numways(1, j - 1);
	if (c >= 2) w += numways(2, j - 2);
	if (c >= 3) w += numways(3, j - 5);
	if (c >= 4) w += numways(4, j - 10);
	if (c >= 5) w += numways(5, j - 20);
	if (c >= 6) w += numways(6, j - 50);
	if (c >= 7) w += numways(7, j - 100);
	if (c >= 8) w += numways(8, j - 200);
	
	ways[c - 1][j - 1] = w;
	return w;
}

int main()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 200; j++)
			ways[i][j] = -1;

	for (int i = 0; i < 8; i++)
	{
		ways[i][0] = 1;
	}

	for (int j = 0; j < 200; j++)
	{
		ways[0][j] = 1;
	}

	cout << numways(8, 200);

	cin.get();
	return 0;
}