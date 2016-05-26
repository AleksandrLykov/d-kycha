#include <priority_queue.h>
#include <ctime>

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "ѕ»–јћ»ƒјЋ№Ќјя —ќ–“»–ќќќќќ¬ ј" << endl;
	cout << "введите арность кучи" << endl;
	int a;
	cin >> a;
	DHeap<float> *heap = new DHeap <float> (a,0);
	cout << "теперь количество" << endl;
	int b;
	cin >> b;
	int c;
	srand(time(NULL));
	for (int i=0;i<b;i++)
	{
		c = 1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(10 - 1)));
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
