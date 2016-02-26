#ifndef __DKYCHA_H__
#define __DKYCHA_H__

#include <cstdlib>
#include <iostream>

using namespace std;

class DKycha
{
private:
	int d;
	int *keys;
	int kolvo;
public:
	DKycha (const int, const int);
	DKycha (const DKycha&);
	~DKycha ();
	int getidx (int a);
	void trans (const int a, const int b);
	void vsplyt (int a);
	void pogryzh (int a);
	void minchild (int a);
	void delet ();
	void deletzadan (int a);
	void push (int a);
	void okych ();
	void sort ();
};

#endif