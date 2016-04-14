#include "graphs.h"
#include "queue.h"

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
	Graph<float> *graph = new Graph<float> (n,m);
	
	cout << "Будем генерировать граф" << endl;
	cout << "Введите минимальное и максимальное значение веса графа" << endl;
	float min, max;
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
	float *dist = graph->deykstra(a);

	cout << "Ответ: " << endl << endl;
	for (int i = 0; i < n; i++)
		cout << dist[i] << ' ';
	cout << endl;

}	
