#ifndef __TABLE_H__
#define __TABLE_H__

#include <iostream>

using namespace std;

#define typ int

template<class TType>
class TabRecord {
protected:
	typ key; //ключ
	TType data; //идентификатор
public:
	TabRecord (typ a, TType b) {key = a; data = b;};
	typ getKey() {return key;};
	TType getData() {return data;};
};


template<class TType>
class Table {
protected:
	int size; //максимальное количество
	int count; //текущее количество записей
	int pos; //указатель
public:
	Table (int);

	virtual TabRecord<TType>* search (typ) = 0; //поиск
	virtual void insert (typ, TType) = 0; //вставка
	virtual void erase (typ) = 0; //удаление
	int	isEmpty (); //проверка на пустоту
	int	isFull (); //проверка на полноту
	virtual int getCount (); //вернуть текущее количество записей
	virtual void reset (); //указатель в начало
	virtual int	goNext (); //переход к следующей записи
	virtual int isTabEnded ();
};

template <class TType>
Table<TType>::Table (int a)
{
	size = a;
	count = 0;
	pos = 0;
}

template <class TType>
int Table<TType>::isEmpty ()
{
	if (count == 0)
		return 1;
	return 0;
}

template <class TType>
int Table<TType>::isFull ()
{
	if (count == size)
		return 1;
	return 0;
}

template <class TType>
int Table<TType>::getCount ()
{
	return count;
}

template <class TType>
void Table<TType>::reset()
{
	pos = 0;
}

template <class TType>
int Table<TType>::goNext ()
{
	if (!isTabEnded() )
	{
		pos++;
		return 1;
	}
	return 0;
}

template <class TType>
int Table<TType>::isTabEnded ()
{
	if (pos == count)
		return 1;
	return 0;
}


template<class TType>
class ScanTable : public Table<TType>
{
protected:
	TabRecord<TType>** recs;
public:
	ScanTable (int size) : Table<TType> (size) 
	{
		recs = new TabRecord<TType>*[size];
		for (int i=0; i<size; i++)
		{
			recs[i] = NULL;
		}
	};
	virtual ~ScanTable() 
	{
		for (int i=0; i<size; i++)
			delete recs[i];
		delete[]recs;
	}

	virtual TabRecord<TType>* search (typ k)
	{
		for (int i=0; i<count; i++)
			if (k == recs[i]->getKey() )
			{
				pos = i;
				return recs[i];
			}
		return NULL;
	};
	virtual void insert (typ k, TType Data)
	{
		if (isFull() )
			throw
			exception ("Таблица полна");;

		recs[count] = new TabRecord<TType>(k, Data);
		count++;
	}
	virtual void erase(typ k)
	{
		if (isEmpty () )
			return;
		if (search(k) == NULL)
			return;

		delete recs[pos];
		recs[pos] = recs[count-1];
		count--;
	}
	void print();
	virtual int GetCount()
	{
		return count;
	};
};

template <class TType>
void ScanTable<TType>::print()
{
	for (int i=0; i<count; i++)
	{
		cout << recs[i]->getKey() << "\t" << recs[i]->getData() << endl;
	}
}

template<class TType>
class SortTable : public ScanTable<TType> {	
public:
	SortTable(int size) : ScanTable<TType>(size) {};
	SortTable(const ScanTable<TType>&);
	virtual ~SortTable()
	{
		for (int i=0; i<size; i++)
			delete recs[i];
		delete[]recs;
	}
	
	virtual TabRecord<TType>* search (typ key)
	{
		int left = 0;
		int right = count - 1;
		int mid;
		while (left <= right)
		{
		mid = left + (right - left) / 2;
		if (key < recs[mid]->getKey()) {
			right = mid - 1;
			pos = left;
		}
		else if (key > recs[mid]->getKey()) {
			left = mid + 1;
			pos = left;
		}
		else
		{
			pos = mid;
			return recs[mid];
		}
	}
	return 0;
	};
	virtual void insert(typ k, TType Data)
	{
		if (isFull() )
			throw
			exception ("Таблица переполнена");
		TabRecord<TType> *tmp;
		tmp = search(k);
		for (int i=count+1; i>=pos+1; i--)
			recs[i] = recs[i-1];
		recs[pos] = new TabRecord<TType>(k,Data);
		count++;
	};
	virtual void erase(typ k)
	{
		if (isEmpty() )
			return;
		if (search(k) == NULL)
			throw
			exception ("Элемента нет такого");

		
		for (int i=pos; i<count - 1; i++)
			recs[i] = recs[i+1];
		recs[count] = NULL;
		count--;
	};

	void sort();
	TabRecord<TType>* min ();
	Graph<TType>* kruskal (Graph<TType> *&);
};

template <class TType>
SortTable<TType>::SortTable (const ScanTable<TType>& table)
{
	size = table.size;
	pos = 0;
	count = table.count;
	recs = new TabRecord<TType>*[size];

	for (int i=0; i<count; i++)
		recs[i] = new TabRecord<TType>(table.recs[i]->getKey(), table.recs[i]->getData() );

	sort();
}

template <class TType>
void SortTable<TType>::sort ()
{
	TabRecord<TType> *tmp;
	for (int i=0; i<count; i++)
		for (int j = i+1; j<count; j++)
			if (recs[i]->getKey() > recs[j]->getKey() )
			{
				tmp = recs[i];
				recs[i] = recs[j];
				recs[j] = tmp;
			}
};

template <class TType>
TabRecord<TType>* SortTable<TType>::min ()
{
	return recs[0];
}



template <class TType>
Graph<TType>* SortTable<TType>::kruskal (Graph<TType>*& gr)
{
	int n = gr->getKolvo();
	int m = gr->getRealSize();
	Graph<TType> *tree = new Graph<TType>(n,m);

	sets<TType> *set = new sets<TType>(n);
	for (int i=0; i<n; i++)
		set->makesets(i);

	TQueue<edge<TType>*> *queue = new TQueue<edge<TType>*>(m);
	for (int i=0; i<m; i++)
		queue->push (gr->getMinEdge(i)->weight ,gr->getMinEdge(i));

	int treeEdgeSize = 0;
	edge<TType>* tmp2 = new edge<TType>(0,0,0);
	TabRecord<edge<TType>*>* tmp = new TabRecord<edge<TType>*>(0,tmp2);

	while ((treeEdgeSize < n-1) && (!queue->isEmpty()))
	{
		tmp = queue->top();
		queue->pop();
		TType weight = tmp->getKey();
		tmp2 = tmp->getData();
		int N = tmp2->o;
		int K = tmp2->k;
		
		int An = set->findsets(N);
		int Ak = set->findsets(K);
		if (An != Ak)
		{
			set->unionsets(An, Ak);
			tree->addEdge(N, K, weight);
			treeEdgeSize++;
		}
	}

	return tree;
}

#endif