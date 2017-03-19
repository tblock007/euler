//DESCRIPTION: Starts by creating a map that maps the values in the range [10,99] to a pair that contains the polygon (3 for triangle, etc.) and the last two digits used to form the 4-digit polygon number.  Then, starting from every octagon number, brute force search for possible cycles.

#include <iostream>
#include <time.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

map<int, vector<pair<int, int>>> mapping;

int main()
{
	clock_t time;
	time = clock();

	//populate map
	for (int n = 20; n <= 141; n++)
	{
		int tri = n * (n + 1) / 2;
		int square = n * n;
		int pent = n * (3 * n - 1) / 2;
		int hex = n * (2 * n - 1);
		int hept = n * (5 * n - 3) / 2;

		if (tri >= 1000 && tri <= 9999)
			mapping[tri / 100].push_back(pair<int, int>(3, tri % 100));
		if (square >= 1000 && square <= 9999)
			mapping[square / 100].push_back(pair<int, int>(4, square % 100));
		if (pent >= 1000 && pent <= 9999)
			mapping[pent / 100].push_back(pair<int, int>(5, pent % 100));
		if (hex >= 1000 && hex <= 9999)
			mapping[hex / 100].push_back(pair<int, int>(6, hex % 100));
		if (hept >= 1000 && hept <= 9999)
			mapping[hept / 100].push_back(pair<int, int>(7, hept % 100));		
	}



	// find a cycle - start with oct numbers because they have the fewest
	for (int n = 19; n <= 58; n++)
	{
		int first = (n * (3 * n - 2)) / 100;
		int last = (n * (3 * n - 2)) % 100;

		bool visited[8];
		for (int i = 0; i <= 7; i++)
			visited[i] = false;

		for (int a = 0; a < mapping[last].size(); a++)
		{
			visited[mapping[last][a].first] = true;
			int last1 = mapping[last][a].second;

			for (int b = 0; b < mapping[last1].size(); b++)
			{
				if (visited[mapping[last1][b].first])
					continue;

				visited[mapping[last1][b].first] = true;
				int last2 = mapping[last1][b].second;

				for (int c = 0; c < mapping[last2].size(); c++)
				{
					if (visited[mapping[last2][c].first])
						continue;

					visited[mapping[last2][c].first] = true;
					int last3 = mapping[last2][c].second;

					for (int d = 0; d < mapping[last3].size(); d++)
					{
						if (visited[mapping[last3][d].first])
							continue;

						visited[mapping[last3][d].first] = true;
						int last4 = mapping[last3][d].second;

						for (int e = 0; e < mapping[last4].size(); e++)
						{
							if (visited[mapping[last4][e].first])
								continue;

							if (mapping[last4][e].second == first)
							{
								int n1 = 100 * first + last;
								int n2 = 100 * last + last1;
								int n3 = 100 * last1 + last2;
								int n4 = 100 * last2 + last3;
								int n5 = 100 * last3 + last4;
								int n6 = 100 * last4 + first;
								std::cout << "Cycle found: " << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << " " << n6 << endl;
								std::cout << "Sum = " << n1 + n2 + n3 + n4 + n5 + n6;
							}
						}

						visited[mapping[last3][d].first] = false;
					}

					visited[mapping[last2][c].first] = false;
				}

				visited[mapping[last1][b].first] = false;
			}

			visited[mapping[last][a].first] = false;
		}
	}

	time = clock() - time;
	std::cout << "\nTime elapsed: " << ((double)time) / CLOCKS_PER_SEC << " seconds.";
	std::cin.get();
	return 0;
}