#include "d-kycha.h"

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

void DKycha::trans (const int a, const int b) 
{
