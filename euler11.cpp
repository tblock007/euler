//DESCRIPTION: Simply checks every combination.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int array[20][20];

	ifstream file("input.txt");
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			file >> array[i][j];
		}
	}
	file.close();

	int max_product = 0;
	int product;

	//check horizontal
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			product = array[i][j] * array[i + 1][j] * array[i + 2][j] * array[i + 3][j];
			if (product > max_product)
				max_product = product;
		}
	}

	//check vertical
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			product = array[i][j] * array[i][j + 1] * array[i][j + 2] * array[i][j + 3];
			if (product > max_product)
				max_product = product;
		}
	}

	//check diagonal down-right
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			product = array[i][j] * array[i + 1][j + 1] * array[i + 2][j + 2] * array[i + 3][j + 3];
			if (product > max_product)
				max_product = product;
		}
	}

	//check diagonal down-left
	for (int i = 3; i < 20; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			product = array[i][j] * array[i - 1][j + 1] * array[i - 2][j + 2] * array[i - 3][j + 3];
			if (product > max_product)
				max_product = product;
		}
	}
	
	cout << max_product;

	cin.get();
	return 0;
}