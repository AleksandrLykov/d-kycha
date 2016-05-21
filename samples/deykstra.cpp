#include "graphs.h"
#include "hqueue.h"

typedef int typ;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "АЛГОРИТМ ДЕЙКСТРЫ" << endl << endl;
	cout << "Введите количество вершин" << endl;
	int n;
	cin >> n;

	cout << "Введите количество ребер" << endl;
	int m;
	cin >> m;
	Graph<typ> *graph = new Graph<typ> (n,m);
		typ *P = new typ(n); //кратчайший путь
		for (int i=0; i<=n;i++)
			P[i] = 0;
	cout << "Будем генерировать граф" << endl;
	cout << "Введите минимальное и максимальное значение веса графа" << endl;
	typ min, max;
	cin >> min;
	cin >> max;
	graph->createGraph(min, max);
	system ("cls");
	
	cout << "Получился вот такой вот граф: " << endl<<endl;
	graph->print();

	cout << "Введите стартовую вершину" << endl;
	int a;
	cin >> a; 
	cout << "Применяем алгоритм.." << endl << endl;
	typ *dist = graph->deykstra(a,P);

	cout << "Ответ: " << endl << endl;	
	
	for (int i=0; i<n;i++)
		cout << i << ' ';
	cout << "- номера вершин" <<  endl << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == MAX_HTYPE)
			cout << 0 << ' ';
		else
			cout << dist[i] << ' ' ;
	cout << "- кратчайшие пути" <<  endl << endl;
	for (int i=0;i<n;i++)
			cout << P[i] << ' ';
	cout << "- предшествующие вершины " <<  endl << endl;

}	
