#include "sets.h"
#include "queue_AVL.h"
#include "table.h"

#define typ float

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	int z;
	cout << "Алгориитм Крускала" << endl;
	cout << "Введите тип приоритетной очереди: " << endl;
	cout << "1) d-куча" << endl;
	cout << "2) АВЛ деревo" << endl;
	cout << "3) таблица" << endl;
	cin >> z;
	switch (z)
	{
	case 1:
		{
			system ("cls");
			int n;
			cout << "Введите количество вершин" << endl;		
			cin >> n;		
			cout << "Введите количество ребер" << endl;
			int m;
			cin >> m;

			Graph<typ> *graph = new Graph<typ> (n,m);
		
			int l;
			cout << "Будем генерировать граф (1) или вручную (2)?" << endl;
			cin >> l;
			switch (l)
			{
			case 1:
				{
				cout << "Введите минимальное и максимальное значение веса" << endl;
				typ min, max;
				cin >> min;
				cin >> max;
				graph->createGraph(min, max);
				break;
				}
			case 2:
				{
					for (int i=0; i<m;i++)
				{
					cout << "Введите откуда, куда и вес" << endl;
					int a,b;
					typ c;
					cin >> a;
					cin >> b;
					cin >> c;
					graph->addEdge(a,b,c);
				}
				break;	
				}
			}
	
			system ("cls");
		
			cout << "Получился вот такой вот граф: " << endl<<endl;
			graph->print();
		
			cout << "Применяем алгоритм Крускала.." << endl;
			Graph<typ> *res = new Graph<typ> (n,m);
			sets<typ> *a = new sets<typ> (n);

			graph->sort();
			res = a->kruskal(graph);
			cout << endl << endl;
			res->print();
		}
		break;
	case 2:
		{
			system ("cls");
			int n;
			cout << "Введите количество вершин" << endl;		
			cin >> n;		
			cout << "Введите количество ребер" << endl;
			int m;
			cin >> m;

			Graph<typ> *graph = new Graph<typ> (n,m);
		
			int l;
			cout << "Будем генерировать граф (1) или вручную (2)?" << endl;
			cin >> l;
			switch (l)
			{
			case 1:
				{
				cout << "Введите минимальное и максимальное значение веса" << endl;
				int min, max;
				cin >> min;
				cin >> max;
				graph->createGraph(min, max);
				break;
				}
			case 2:
				{
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
			}
	
			system ("cls");
		
			cout << "Получился вот такой вот граф: " << endl<<endl;
			graph->print();
		
			cout << "Применяем алгоритм Крускала.." << endl;
			Graph<typ> *res = new Graph<typ> (n,m);
			AVL<typ> *a = new AVL<typ> ();

			res = a->kruskal(graph);
			cout << endl << endl;
			res->print();
		}
		break;
	case 3:
		{
			system ("cls");
			cout << "size" << endl;
			int s;
			cin >> s;
			ScanTable<typ> *a = new ScanTable<typ>(s);

			a->insert(1, 5);
			a->insert(2, 11);
			a->print();
		}
	}
}
