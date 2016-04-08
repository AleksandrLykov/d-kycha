#include <d-heap.h>


template <class HType>
struct TypeQueue
{
	DHeap<HType> *arr; //��� ����
	int prior; //���������
};

template <class HType>
class HQueue
{
private:
	TypeQueue<HType>* ar; // �������
	int MaxSize; // ������������ ������
	int kolvo; //���������� ��-��� � �������
public:
	HQueue(int, int, int);
	~HQueue();

	void push(const DHeap<HType>&, int);
	void pop();
	int isEmpty();
	int isFull();
	DHeap<HType>* top();
};

template <class HType>
HQueue<HType>::HQueue (int max, int arnost, int kolvo)
{	
	if ((arnost <= 0) || (kolvo< 0) || (max < 0))
	throw
	exception ("������� ���������� ������");
	MaxSize = max;
	this->kolvo = 0;
	ar = new TypeQueue<HType> [MaxSize];
	ar->prior = 0;
	ar->arr = new DHeap<HType> (arnost, kolvo);
}

template <class HType>
HQueue<HType>::~HQueue ()
{
	delete [ar];
}

 template <class HType>
 void HQueue<HType>::push(const DHeap<HType> &a, int b)
{
	 if (isFull())
		 throw exception ("������� �����������");
	ar[kolvo].arr = a;
	ar[kolvo].prior = b;

	int i = kolvo;
	TypeQueue<HType> tmp;
	while ((i > 0) && (ar[kolvo].prior < ar[i].prior))
	{
		tmp = ar[kolvo];
		ar[kolvo] = ar[i];
		ar[i] = tmp;
		i--;
	}
	kolvo++;	
}

