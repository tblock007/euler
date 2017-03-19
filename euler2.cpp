//DESCRIPTION: Again, nice and simple.

#include <iostream>

using namespace std;

int main()
{
	int sum = 2; //start at 2 because the loop is going to exclude the second term in the sequence

	int prev1 = 1;
	int prev2 = 2;
	
	int curr = prev1 + prev2;

	while (curr < 4000000)
	{
		if ((curr % 2) == 0)
			sum += curr;
		
		prev1 = prev2;
		prev2 = curr;
		
		curr = prev1 + prev2;
	} 

	cout << sum;
	cin.get();

	return 0;
}