#ifndef __TABLE_H__
#define __TABLE_H__

#include <iostream>

using namespace std;


template<class TType>
class TabRecord {
protected:
	int key; //����
	TType data; //�������������
public:
	TabRecord (int a, TType b) {key = a; data = b;};
	int getKey() {return key;};
	TType getData() {return data;};
};


template<class TType>
class Table {
protected:
	int size; //������������ ����������
	int count; //������� ���������� �������
	int pos; //���������
public:
	Table (int);

	virtual TabRecord<TType>* search (int) = 0; //�����
	virtual void insert (int, TType) = 0; //�������
	virtual void erase (int) = 0; //��������
	int	isEmpty (); //�������� �� �������
	int	isFull (); //�������� �� �������
	int getCount (); //������� ������� ���������� �������
	virtual void reset (); //��������� � ������
	virtual int	goNext (); //������� � ��������� ������
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

	virtual TabRecord<TType>* search (int k)
	{
		for (int i=0; i<count; i++)
			if (k == recs[i]->getKey() )
			{
				pos = i;
				return recs[i];
			}
		return NULL;
	};
	virtual void insert (int k, TType Data)
	{
		if (isFull() )
			throw
			exception ("������� �����");;

		recs[count] = new TabRecord<TType>(k, Data);
		count++;
	}
	virtual void erase(int k)
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
	
	virtual TabRecord<TType>* search (int k)const
	{
		int left = 0;
		int right = count - 1;
		int mid;

		while(left <= right)
		{
			mid = left + (right - left) / 2;
			if (k < recs[mid]->getKey() )
				right = mid - 1;
			else if (key > recs[mid]->getKey()) 
				left = mid + 1;
			else 
			{
				pos = mid;
				return recs[mid];
			}
			pos = right;
		}
		return NULL;
	};
	virtual void insert(int k, TType Data)
	{
		if (isFull() )
			throw
			exception ("������� �����������");
		TabRecord<TType> *tmp;
		tmp = search(k);
		for (int i=count+1; i>=pos+1; i--)
			recs[i] = recs[i-1];
		recs[pos] = new TableRecord(k,Data);
		count++;
	};
	virtual void erase(int k)
	{
		if (isEmpty() )
			return;
		if (search(k) == NULL)
			throw
			exception ("�������� ��� ������");

		delete recs[pos];
		for (int i=pos; i<count - 1; i++)
			recs[i] = recs[i+1];
		recs[count] = NULL;
		count--;
	};

	void sort();
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

#endif