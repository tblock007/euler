//DESCRIPTION: It's much easier to simply count the factors.  For each prime p less than 20, include n factors in the product where p^(n+1) > 20.

#include <iostream>

using namespace std;

int main()
{
	int answer = 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13 * 17 * 19;

	cout << answer;

	cin.get();
	return 0;
}