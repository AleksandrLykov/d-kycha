#include <queue.h>

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "ПИРАМИДАЛЬНАЯ СОРТИРОООООВКА" << endl;
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
		cout << "Введите " << i << "-й элемент кучи" << endl;
		cin >> c;
		heap->push(c);
	}
	system("cls");
	cout << "Ваша куча получилась вот такая(не очень красивый вывод, но терпимо): " << endl;
	heap->vyvod();

	cout << "Сортируем?? (1 - да, 2 - нет, просто кучу захотели посмотреть) " << endl;
	cin >> a;
	switch (a)
	{
	case 1:
		cout << "Отлично)) " << endl;
		break;
	case 2:
		cout << "Ну вот (" << endl;
		return;
	default:
		cout << "либо 1, либо 2!" << endl;
	}

	cout << "После окучивания куча выглядит вот так: " << endl;
	heap->okych();
	heap->vyvod();
	cout << "После сортировки уже вот так: " << endl;
	
	heap->Sort();
	heap->vyvod();

}
