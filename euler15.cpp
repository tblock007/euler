//DESCRIPTION: Dynamic programming approach that determines the number of paths to the left node and the upper node, and then sums to get number of paths to the current node.

#include <iostream>

using namespace std;


long long p[21][21];


long long paths(int i, int j)
{
	if ((i == 0) || (j == 0))
		return 1;

	if (p[i][j] != 0)
		return p[i][j];

	p[i][j] = (paths(i - 1, j) + paths(i, j - 1));
	return p[i][j];
}


int main()
{
	cout << paths(20, 20);

	cin.get();
	return 0;
}

