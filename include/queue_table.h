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
	TabRecord<TType>* top ();
	int isEmpty ();
	void print();
	int GetSize();
	SortTable<TType>* getTable ();
};

template <class TType>
TQueue<TType>::TQueue (int a)
{
	if (a < 0)
		throw 
		exception ("neverno");
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
	if (isEmpty() )
		throw
		exception ("neverno");
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
	return table->GetCount();
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

template <class TType>
SortTable<TType>* TQueue<TType>::getTable ()
{
	return table;
}