#include <queue.h>

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "������������� ��������������" << endl;
	cout << "������� ������� ����" << endl;
	int a;
	cin >> a;
	DHeap<int> *heap = new DHeap <int> (a,0);
	cout << "������ ����������" << endl;
	int b;
	cin >> b;
	int c;
	for (int i=0;i<b;i++)
	{
		c = 1 + rand() % 5;
		heap->push(c);
	}
	system("cls");
	cout << "���� ���� ���������� ��� �����(�� ����� �������� �����, �� �������): " << endl;
	heap->vyvod();

	cout << "����� ���������� ��� ��� ���: " << endl;
	heap->okych();
	heap->Sort();
	heap->vyvod();

}
