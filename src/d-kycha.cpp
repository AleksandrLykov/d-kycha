#include "dkycha.h"

DKycha::DKycha (const int arnost, const int size)
{
	d = arnost; 
	kolvo = size;
	keys = new int [kolvo];
}

DKycha::DKycha (const DKycha &a)
{
	d = a.d;
	kolvo = a.kolvo;
	for (int i=0;i<kolvo;i++)
		keys[i] = a.keys[i];
}

DKycha::~DKycha ()
{
	delete []keys;
}

int DKycha::getidx (int a)
{
	int p;
	return p = (a-1)/d;
}

void DKycha::trans (const int a, const int b) 
{
	int tmp = keys[a];
	keys[a] = keys[b];
	keys[b] = tmp;
}

void DKycha::vsplyt (int a) 
{
	int p = getidx (a);
	while ((p > 0) && (keys[p]
}
