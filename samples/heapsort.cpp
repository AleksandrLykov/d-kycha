#include <queue.h>

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "ѕ»–јћ»ƒјЋ№Ќјя —ќ–“»–ќќќќќ¬ ј" << endl;
	cout << "введите арность кучи" << endl;
	int a;
	cin >> a;
	DHeap<int> *heap = new DHeap <int> (a,0);
	cout << "теперь количество" << endl;
	int b;
	cin >> b;
	int c;
	for (int i=0;i<b;i++)
	{
		c = 1 + rand() % 5;
		heap->push(c);
	}
	system("cls");
	cout << "¬аша куча получилась вот така€(не очень красивый вывод, но терпимо): " << endl;
	heap->vyvod();

	cout << "ѕосле сортировки уже вот так: " << endl;
	heap->okych();
	heap->Sort();
	heap->vyvod();

}
