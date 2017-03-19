#include <iostream>

using namespace std;

#ifndef BIG_INT_H
#define BIG_INT_H

#define BIG_INT_SIZE 5000

class big_int
{
public:
	big_int();
	~big_int();


	void set(long long a);
	void big_int::operator=(long long a);

	void static add(big_int& a, big_int& b, big_int& c);
	void static multiply(big_int& a, big_int& b, big_int& c, int size_b);
	void static sdm(big_int& a, int d, big_int& c, int offset);
	void print();
	int sum_digits();
	int size();

private:
	int n[BIG_INT_SIZE];
};

#endif
