//DESCRIPTION: The main design of this solution involves creating a "score" for each hand such that the better hand always has the higher score.  This is done by summing to create an integer where the most significant digits represent the hand, and then lower digits are used for breaking ties between hands.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int map(char a)
{
	switch (a)
	{
	case 'A': return 14;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case 'T': return 10;
	case 'J': return 11;
	case 'Q': return 12;
	case 'K': return 13;
	case 'D': return 1;
	case 'C': return 2;
	case 'H': return 3;
	case 'S': return 4;
	}

	return 0;
}



//returns a score representing the strength of the hand
//11th and 12th digits show the hand: royal flush = 10; straight flush = 09, etc.
//9th and 10th digits show the main tiebreaker: pair of eights = 08, straight 7-J = 11, 2-2-4-4-4 = 04, etc.
//7th and 8th digits show successive tiebreakers, etc.
//there is potential for the need for five tiebreakers
long long score(string c1, string c2, string c3, string c4, string c5)
{
	int h, t1, t2, t3, t4, t5;
	h = t1 = t2 = t3 = t4 = t5 = 0;

	int repeat1 = 0, n1 = 0;
	int repeat2 = 0, n2 = 0;

	vector<int> numbers;
	vector<int> suits;

	bool straight = false;
	bool flush = false;

	numbers.push_back(map(c1[0])); suits.push_back(map(c1[1]));
	numbers.push_back(map(c2[0])); suits.push_back(map(c2[1]));
	numbers.push_back(map(c3[0])); suits.push_back(map(c3[1]));
	numbers.push_back(map(c4[0])); suits.push_back(map(c4[1]));
	numbers.push_back(map(c5[0])); suits.push_back(map(c5[1]));

	sort(numbers.begin(), numbers.end());

	int temp;
	for (int val = 2; val <= 14; val++)
	{
		temp = count(numbers.begin(), numbers.end(), val);
		if (temp > repeat1)
		{
			repeat1 = temp;
			n1 = val;
		}
	}

	for (int val = 2; val <= 14; val++)
	{
		if (val == n1)
			continue;

		temp = count(numbers.begin(), numbers.end(), val);
		if (temp > repeat2)
		{
			repeat2 = temp;
			n2 = val;
		}
	}

	if ((suits[0] == suits[1]) && (suits[0] == suits[2]) && (suits[0] == suits[3]) && (suits[0] == suits[4]))
		flush = true;

	if ((numbers[3] == numbers[2] + 1) && (numbers[2] == numbers[1] + 1) && (numbers[1] == numbers[0] + 1))
	{
		if ((numbers[4] == numbers[3] + 1) || (numbers[4] == numbers[0] + 12)) //to account for ace being high and low
			straight = true;
	}

	if (straight && flush && (numbers[4] == 14))
	{
		h = 10;
	}
	else if (straight && flush)
	{
		h = 9;
		t1 = numbers[4];
	}
	else if (repeat1 == 4)
	{
		h = 8;
		t1 = n1;
	}
	else if (repeat1 == 3 && repeat2 == 2)
	{
		h = 7;
		t1 = n1;
	}
	else if (flush)
	{
		h = 6;
		t1 = numbers[4];
		t2 = numbers[3];
		t3 = numbers[2];
		t4 = numbers[1];
		t5 = numbers[0];
	}
	else if (straight)
	{
		h = 5;
		t1 = numbers[4];
	}
	else if (repeat1 == 3)
	{
		h = 4;
		t1 = numbers[4];
	}
	else if (repeat1 == 2 && repeat2 == 2)
	{
		h = 3;
		t1 = max(n1, n2);
		t2 = min(n1, n2);
		for (int i = 0; i < 5; i++)
			if ((numbers[i] != n1) && (numbers[i] != n2))
				t3 = numbers[i];
	}
	else if (repeat1 == 2)
	{
		h = 2;
		t1 = n1;
		vector<int> remaining;
		for (int i = 0; i < 5; i++)
			if (numbers[i] != n1)
				remaining.push_back(numbers[i]);

		t2 = remaining[2];
		t3 = remaining[1];
		t4 = remaining[0];
	}
	else
	{
		h = 1;
		t1 = numbers[4];
		t2 = numbers[3];
		t3 = numbers[2];
		t4 = numbers[1];
		t5 = numbers[0];
	}

	return (10000000000ll * h + 100000000ll * t1 + 1000000ll * t2 + 10000ll * t3 + 100ll * t4 + t5);
}


int main()
{
	int w1 = 0;
	long long score1, score2;
	string c1, c2, c3, c4, c5;

	ifstream file("poker.txt");
	while (file.good())
	{
		file >> c1 >> c2 >> c3 >> c4 >> c5;
		score1 = score(c1, c2, c3, c4, c5);
		file >> c1 >> c2 >> c3 >> c4 >> c5;
		score2 = score(c1, c2, c3, c4, c5);


		if (score1 > score2)
			w1++;
	}
	file.close();

	cout << w1;
	cin.get();
	return 0;
}