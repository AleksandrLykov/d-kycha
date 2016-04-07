#include <d-heap.h>


template <class HType>
struct TypeQueue
{
	DHeap<HType>* arr; //������ �� ��� ���
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
	HQueue();
	~HQueue();
	HQueue(const HQueue&);

	void push(const DHeap<HType>&);
	void pop();
	int isEmpty();
	int isFull();
	DHeap<HType>* top();
};

template <class HType>
HQueue<HType>::HQueue ()
{
	ar->arr = new DHeap<HType>;
	ar->prior = 0;
	MaxSize = 32;
	kolvo = 0;
}

template <class HType>
HQueue<HType>::~HQueue ()
{
	delete [ar];
}

 template <class HType>
 HQueue<HType>::HQueue(const HQueue& a)
 {
	 ar->

 template <class HType>
 void HQueue<HType>::push(const DHeap<HType>& a, int b)
 {
	 if (isFull())
		 throw exception ("������� �����������");
	int tmp;

