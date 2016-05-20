#include "table.h"

template <class TType>
class TQueue
{
private:
	SortTable<TType>* table;
public:
	TQueue(int);
	~TQueue();

	void push(typ k, TType a);
	void pop();
	int isEmpty();
	TabRecord<TType>* top();
	void print();
	int GetSize();
	int operator==(const BQueue<TType>&)const;
	SortTable<TType>* getTable ();
};

template <class TType>
TQueue<TType>::TQueue (int a)
{
	table = new SortTable<TType>(a);
}

template <class TType>
TQueue<TType>::~TQueue()
{
	delete table;
}

template <class TType>
void TQueue<TType>::push (typ k, TType a)
{
	table->insert(k, a);
}

template <class TType>
void TQueue<TType>::pop()
{
	table->erase(table->min()->getKey() );
}

template <class TType>
TabRecord<TType>* TQueue<TType>::top ()
{
	return table->min();
}

template <class TType>
int TQueue<TType>::GetSize ()
{
	return table->getCount();
}

template <class TType>
int TQueue<TType>::isEmpty()
{
	if (table->GetCount() == 0)
		return 1;
	return 0;
}

template <class TType>
void TQueue<TType>::print()
{
	table->print();
}

