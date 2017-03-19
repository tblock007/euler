//DESCRIPTION: Just a little bit of recursion - not much room for anything clever.

#include <iostream>

using namespace std;

int letter_count(int a)
{
	//handle special cases
	switch (a)
	{
	case 0: return 0; // auxiliary case for recursion
	case 1: return 3;
	case 2: return 3;
	case 3: return 5;
	case 4: return 4;
	case 5: return 4;
	case 6: return 3;
	case 7: return 5;
	case 8: return 5;
	case 9: return 4;
	case 10: return 3;
	case 11: return 6;
	case 12: return 6;
	case 13: return 8;
	case 14: return 8;
	case 15: return 7;
	case 16: return 7;
	case 17: return 9;
	case 18: return 8;
	case 19: return 8;
	case 20: return 6;
	case 30: return 6;
	case 40: return 5;
	case 50: return 5;
	case 60: return 5;
	case 70: return 7;
	case 80: return 6;
	case 90: return 6;
	case 1000: return 11;
	}

	//if it's not a special case, read digit by digit

	//hundreds digit
	int h = a / 100;
	int r = a % 100;

	if (h != 0)
	{
		if (r != 0)
			return (letter_count(h) + 7 + 3 + letter_count(r));
		else
			return (letter_count(h) + 7);
	}


	//tens digit, with a guaranteed to be less than 100
	int t = a / 10;
	r = a % 10;

	return (letter_count(t * 10) + letter_count(r));


}

int main()
{
	int sum = 0;

	for (int i = 1; i <= 1000; i++)
	{
		sum += letter_count(i);
	}

	cout << sum;
	cin.get();
	return 0;
}