//DESCRIPTION: Two analyses help us decrypt this message.  First, we do a count to determine the frequencies of each ASCII character in each set.  Then, we run through the test lowercase letters and see which ones map to expected characters.  Of the possible candidates, only the SPACE character makes sense as the most frequent character, so we try the resulting mapping as our first guess, which turns out to be correct.

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector<char> cipher;

int decrypt_print(char k1, char k2, char k3)
{
	int sum = 0;

	cout << endl;
	cout << "Decrypting with key " << k1 << k2 << k3 << ": " << endl;

	int c = 1;
	char dec;
	for (int i = 0; i < cipher.size(); i++)
	{
		if (c % 3 == 1)
			dec = (char) (cipher[i] ^ k1);
		else if (c % 3 == 2)
			dec = (char) (cipher[i] ^ k2);
		else if (c % 3 == 0)
			dec = (char) (cipher[i] ^ k3);
		c++;
		cout << dec;
		sum += dec;
	}

	cout << endl;

	return sum;
}

int main()
{
	map<char, int> count1, count2, count3;

	cout << "Reading file..." << endl;
	ifstream file("cipher.txt");
	int t;
	int c = 2;
	char delim;
	file >> t;
	count1[t]++;
	cipher.push_back((char) t);
	while (file.good())
	{
		file >> delim >> t;

		if (c % 3 == 1)
			count1[t]++;
		else if (c % 3 == 2)
			count2[t]++;
		else
			count3[t]++;
		c++;
		cipher.push_back((char) t);
	}
	file.close();

	//undo duplicated element
	cipher.pop_back();
	c--;
	if (c % 3 == 1)
		count1[t]--;
	else if (c % 3 == 2)
		count2[t]--;
	else
		count3[t]--;
	cout << "Done reading file." << endl << endl;

	cout << "Frequency analysis:" << endl << endl;
	cout << "First set:" << endl;
	for (map<char, int>::iterator i = count1.begin(); i != count1.end(); i++)
	{
		cout << (int)i->first << " : " << i->second;

		if (i->second > 50)
			cout << " **";
		cout << endl;
	}
	cout << endl;

	cout << "Second set:" << endl;
	for (map<char, int>::iterator i = count2.begin(); i != count2.end(); i++)
	{
		cout << (int)i->first << " : " << i->second;

		if (i->second > 50)
			cout << " **";
		cout << endl;
	}
	cout << endl;

	cout << "Third set:" << endl;
	for (map<char, int>::iterator i = count3.begin(); i != count3.end(); i++)
	{
		cout << (int)i->first << " : " << i->second;

		if (i->second > 50)
			cout << " **";
		cout << endl;
	}
	cout << endl << endl;


	cout << "Possible candidates for first letter:" << endl;
	for (char test = 'a'; test <= 'z'; test++)
	{
		bool flag = true;
		for (map<char, int>::iterator i = count1.begin(); i != count1.end(); i++)
		{
			char dec = i->first ^ test;
			if ((dec <= 31) || (dec >= 126))
				flag = false;
		}
		if (flag)
			cout << test << "->" << (char) (test ^ 71) << "  ";
	}
	cout << endl;

	cout << "Possible candidates for second letter:" << endl;
	for (char test = 'a'; test <= 'z'; test++)
	{
		bool flag = true;
		for (map<char, int>::iterator i = count2.begin(); i != count2.end(); i++)
		{
			char dec = i->first ^ test;
			if ((dec <= 31) || (dec >= 126))
				flag = false;
		}
		if (flag)
			cout << test << "->" << (char) (test ^ 79) << "  ";
	}
	cout << endl;

	cout << "Possible candidates for third letter, and resulting decryption of most frequent character:" << endl;
	for (char test = 'a'; test <= 'z'; test++)
	{
		bool flag = true;
		for (map<char, int>::iterator i = count3.begin(); i != count3.end(); i++)
		{
			char dec = i->first ^ test;
			if ((dec <= 31) || (dec >= 126))
				flag = false;
		}
		if (flag)
			cout << test << "->" << (char) (test ^ 68) << "  ";
	}
	cout << endl;

	int sum = decrypt_print('g', 'o', 'd');

	cout << sum;
	cin.get();
	return 0;
}