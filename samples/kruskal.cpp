#include "sets.h"

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	int n;
	cout << "Введите количество вершин" << endl;

	cin >> n;

	cout << "Введите количество ребер" << endl;
	int m;
	cin >> m;
	Graph<float> *graph = new Graph<float> (n,m);
	
	int l;
	cout << "Будем генерировать граф (1) или вручную (2)?" << endl;
	cin >> l;
	switch (l)
	{
	case 1:
		cout << "Введите минимальное и максимальное значение веса" << endl;
		int min, max;
		cin >> min;
		cin >> max;
		graph->createGraph(min, max);
		break;
	case 2:
		for (int i=0; i<m;i++)
		{
			cout << "Введите откуда, куда и вес" << endl;
			int a,b;
			float c;
			cin >> a;
			cin >> b;
			cin >> c;
			graph->addEdge(a,b,c);
		}
		break;	
	}

	system ("cls");
	
	cout << "Получился вот такой вот граф: " << endl<<endl;
	graph->print();

	cout << "Применяем алгоритм Крускала.." << endl;
	Graph<float> *res = new Graph<float> (n,m);
	sets<float> *a = new sets<float> (n);

	res = a->kruskal(graph);
	cout << endl << endl;
	res->print();
}
