//DESCRIPTION: Some quick reasoning reveals that the base of the exponent must be less than 10, because 10^n has (n+1) digits.  For each base from 1 to 9 (note that they are all a first power), we need to find the first x such that (b/10)^x < 0.1.  Then, the base will contribute (x-1) to the overall count.

#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
	clock_t time;
	time = clock();

	int count = 0;
	for (int b = 1; b <= 9; b++)
	{
		double base = (b / 10.0);
		double x = log(0.1) / log(base);
		count = count + (int)x;
	}

	cout << count << endl;


	time = clock() - time;
	cout << "Time elapsed: " << ((double)time) / CLOCKS_PER_SEC;
	cin.get();
	return 0;
}