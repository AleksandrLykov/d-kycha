#include "sets.h"

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	int n;
	cout << "ААААЛЛГОРИТМ КРУУУУУУСКаЛЯ" << endl;
	cout << "Введите количество вершин" << endl;

	cin >> n;

	cout << "Введите количество ребер" << endl;
	int m;
	cin >> m;
	Graph<int> *graph = new Graph<int> (n,m);
	
	cout << "Будем генерировать граф" << endl;
	cout << "Введите минимальное и максимальное значение веса графа" << endl;
	int min, max;
	cin >> min;
	cin >> max;
	graph->createGraph(min, max);
	system ("cls");
	
	cout << "Получился вот такой вот граф: " << endl<<endl;
	graph->print();

	cout << "Применяем алгоритм Крускала.." << endl;
	Graph<int> *res = new Graph<int> (n,m);
	sets<int> *a = new sets<int> (n);

	res = a->kruskal(graph);
	cout << endl << endl;
	res->print();
}
