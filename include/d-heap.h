#ifndef __D_HEAP__H__
#define __D_HEAP__H__

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

template <class HType>
class DHeap
{
private:
	int d; //арность
	HType *keys;// Массив
	int kolvo;//количество
public:
	DHeap (const int, const int);
	DHeap (const DHeap<HType>&);
	~DHeap ();

	int getidx (int a);
	void trans (const int a, const int b);
	void vstavka (const int idx, const HType a);
	void vsplyt (int a);
	void pogryzh (int a);
	int minchild (int a);
	void delet ();
	void deletzadan (int a);
	void push (HType a);
	void okych ();
	void vyvod ();
	int operator == (const DHeap<HType>& a)const;
	DHeap& operator=(const DHeap<HType>& a);
	int getKolvo();
	HType getKey(int);
};

template <class HType>
DHeap<HType>::DHeap (const int arnost, const int size)
{
	if ((arnost <= 0) || (size < 0))
	throw
	exception ("введите корректные данные");
	d = arnost; 
	kolvo = size;
	keys = new HType[kolvo];
}

template <class HType>
DHeap<HType>::DHeap (const DHeap &a)
{
	keys = new HType [a.kolvo];
	d = a.d;
	kolvo = a.kolvo;
	prior = a.prior;
	for (int i=0;i<kolvo-1;i++)
		keys[i] = a.keys[i];
}

template <class HType>
DHeap<HType>::~DHeap ()
{
	delete []keys;
}

template <class HType>
int DHeap<HType>::getidx (int a)
{
	int p;
	return p = (a-1)/d;
}

template <class HType>
void DHeap<HType>::trans (const int a, const int b) 
{
	if ((a > kolvo-1) || (b > kolvo-1))
	throw
	exception ("введите корректный индекс");

	HType tmp = keys[a];
	keys[a] = keys[b];
	keys[b] = tmp;
}

template <class HType>
void DHeap<HType>::vstavka (const int idx, const HType a)
{
	if (idx > kolvo - 1)
		throw;
	keys[idx] = a;
}

template <class HType>
void DHeap<HType>::vsplyt (int a) 
{
	if (a > kolvo-1)
	throw
	exception ("введите корректный индекс");

	int p = getidx (a);
	while ((p >= 0) && (keys[p] > keys[a]))
	{
		if (p == 0)
		{
			trans(a,p);
			return;
		}
		trans(a,p);
		a = p;
		p = getidx (a);
	}
}

template <class HType>
int DHeap<HType>::minchild (int a) 
{
	int l;
	if (a*d + 1>= kolvo)
		return (-1);
	int f = a*d + 1;
	int minc = f;
	if (a*d+d > kolvo-1)
		l = kolvo-1;
	else l = a*d+d;
	for (int k=f;k<=l;k++)
		if (keys[k]<keys[minc])
			minc = k;
	return minc;
}

template <class HType>
void DHeap<HType>::pogryzh (int a)
{
	if (a > kolvo-1)
	throw
	exception ("введите корректный индекс");

	int c = minchild(a);
	while ((c!=-1) && (keys[c] < keys[a]))
	{
		trans (c,a);
		a = c;
		c = minchild (a);
	}
}

template <class HType>
void DHeap<HType>::delet ()
{
	keys[0] = keys[kolvo - 1];
	kolvo --;
	pogryzh(0);
}

template <class HType>
void DHeap<HType>::deletzadan (int a)
{
	if (a == 0)
	{
		delet();
		return;
	}

	if (a > kolvo-1)
	throw
	exception ("введите корректный индекс");
	
	keys[a] = keys[kolvo-1];
	kolvo --;
	pogryzh(a);
}

template <class HType>
void DHeap<HType>::push (HType a)
{
	kolvo ++;
	HType *tmp = new HType[kolvo];
	for (int i=0;i<kolvo-1;i++)
		tmp[i] = keys[i];
	tmp[kolvo - 1] = a;
	keys = tmp;
	vsplyt(kolvo-1);
}

template <class HType>
void DHeap<HType>::okych ()
{
	if (kolvo == 0)
		throw
		exception ("D-куча пуста");
	for (int i=kolvo-1; i>=0;i--)
		pogryzh(i);
}

template <class HType>
int DHeap<HType>::operator==(const DHeap<HType>& a)const
{
	if (a.kolvo != kolvo)
		return 0;
	for (int i=0;i<a.kolvo;i++)
	{
		if (keys[i] != a.keys[i])
			return 0;
	}
	return 1;
}

template <class HType>
void DHeap<HType>::vyvod()
{
	int level=0, tmp = 0;
	while (tmp < kolvo)
	{
		tmp += pow (d,level);
		level++;
	}
	int k=1, z=0;
	cout << " " << keys[0] << endl;
	for (int i = 1; i < level;i++)
	{
		for (int j = k; (j<k+pow(d,i)) && (j < kolvo); j++)
			cout << keys[j] << "  ";
		cout << endl;
		if (k + pow(d,i) > kolvo)
				k = kolvo;
			else k += pow(d,i);
	}
}

template <class HType>
DHeap<HType>& DHeap<HType>::operator=(const DHeap<HType>& a)
{
	d = a.d;
	kolvo = a.kolvo;
	for (int i=0;i<kolvo;i++)
		keys[i] = a.keys[i];
	return *this;
}

template <class HType>
int DHeap<HType>::getKolvo ()
{
	return kolvo;
}

template <class HType>
HType DHeap<HType>::getKey (int a)
{
	return keys[a];
}

#endif