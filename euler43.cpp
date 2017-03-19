//DESCRIPTION: We reduce the search space as follows.  d6 cannot be 0, beause that would require d7 = d8 for divisibility by 11.  d6 then must be 5 for divisibility by 5.  d6d7d8 must therefore be one of {506, 517, 528, 539, 561, 572, 583, 594}.  Furthermore, we can use trial and error with divisibility by 7 to determine that d5d6d78 must be one of {3506, 6517, 9528, 0561, 7561, 3572, 6583, 2594}.  We reduce further by enforcing d4 even, and use a sum of d3+d4+d5 check to eliminate candidates based on divisibility by 3.

#include <iostream>

using namespace std;


bool used[10];

void cand5678(int n, int* d5, int* d7, int* d8)
{
	switch (n)
	{
	case 1: *d5 = 3; *d7 = 0; *d8 = 6; used[3] = true; used[0] = true; used[6] = true; return;
	case 2: *d5 = 6; *d7 = 1; *d8 = 7; used[6] = true; used[1] = true; used[7] = true; return;
	case 3: *d5 = 9; *d7 = 2; *d8 = 8; used[9] = true; used[2] = true; used[8] = true; return;
	case 4: *d5 = 0; *d7 = 6; *d8 = 1; used[0] = true; used[6] = true; used[1] = true; return;
	case 5: *d5 = 7; *d7 = 6; *d8 = 1; used[7] = true; used[6] = true; used[1] = true; return;
	case 6: *d5 = 3; *d7 = 7; *d8 = 2; used[3] = true; used[7] = true; used[2] = true; return;
	case 7: *d5 = 6; *d7 = 8; *d8 = 3; used[6] = true; used[8] = true; used[3] = true; return;
	case 8: *d5 = 2; *d7 = 9; *d8 = 4; used[2] = true; used[9] = true; used[4] = true; return;
	}

	return;
}


int main()
{
	long long sum = 0;

	int d[10];
	d[5] = 5;

	for (int n = 1; n <= 8; n++)
	{
		for (int i = 0; i < 10; i++)
			used[i] = false;
		used[5] = true;

		cand5678(n, &d[4], &d[6], &d[7]);

		for (int d4 = 0; d4 <= 8; d4 += 2)
		{
			if (used[d4])
				continue;
			d[3] = d4; // at this point, d4,d5,d6,d7,d8 are set
			used[d4] = true;

			for (int d3 = 0; d3 <= 9; d3++)
			{
				if (used[d3] || (((d3 + d[3] + d[4]) % 3 != 0)))
					continue;
				d[2] = d3; // at this point, d3,d4,d5,d6,d7,d8 are set
				used[d3] = true;

				for (int d9 = 0; d9 <= 9; d9++)
				{
					if (used[d9] || (((100 * d[6] + 10 * d[7] + d9) % 13) != 0))
						continue;
					d[8] = d9; // at this point, d3,d4,d5,d6,d7,d8,d9 are set
					used[d9] = true;

					for (int d10 = 0; d10 <= 9; d10++)
					{
						if (used[d10] || (((100 * d[7] + 10 * d[8] + d10) % 17) != 0))
							continue;
						d[9] = d10; // at this point, d3,d4,d5,d6,d7,d8,d9,d10 are set
						used[d10] = true;

						for (int d2 = 0; d2 <= 9; d2++)
						{
							if (used[d2])
								continue;
							d[1] = d2; // at this point d2,d3,d4,d5,d6,d7,d8,d9,d10 are set
							used[d2] = true;

							for (int d1 = 1; d1 <= 9; d1++)
							{
								if (used[d1])
									continue;
								d[0] = d1;
								used[d1] = true;

								long long c = 0;
								for (int ii = 0; ii < 10; ii++)
								{
									c = 10 * c + d[ii];
								}
								sum += c;

								used[d1] = false;
							}
							used[d2] = false;
						}
						used[d10] = false;
					}
					used[d9] = false;
				}
				used[d3] = false;
			}
			used[d4] = false;
		}
	}

	cout << sum;

	cin.get();
	return 0;
}