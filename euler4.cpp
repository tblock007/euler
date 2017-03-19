//DESCRIPTION: We iterate through all three-digit multiplicands in descending order to find the largest palindrome product.  We stop when all future products will be less than the current candidate, which is easily determined due to the nice monotonic behavior of x*y.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(int x);

int main()
{
	int curr = 0;
	int prod = 0;
	for (int a = 999; a >= 100; a--)
	{
		for (int b = 999; b >= a; b--)
		{
			prod = a*b;

			// if we ever reach an a value where the maximum value of the product is less than the current 
			// candidate, then we know there is no point in going further, since all further products will be 
			// less than the current candidate
			if (b == 999)
			{
				if (prod < curr)
				{
					cout << curr;
					cin.get();
					return 0;
				}
			}

			if ((prod > curr) && (is_palindrome(prod)))
			{
				curr = prod;
			}
		}
	}

	return 0;
}

bool is_palindrome(int x)
{
	string candidate = to_string(x);
	string reversed = candidate;
	reverse(reversed.begin(), reversed.end());

	if (candidate.compare(reversed) == 0)
		return true;

	return false;

}