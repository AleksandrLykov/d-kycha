#include "sets.h"
#include "queue_AVL.h"

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	int z;
	cout << "��������� ��������" << endl;
	cout << "������� ��� ������������ �������: " << endl;
	cout << "1) d-����" << endl;
	cout << "2) ��� �����o" << endl;
	cout << "3) �������" << endl;
	cin >> z;
	switch (z)
	{
	case 1:
		{
			system ("cls");
			int n;
			cout << "������� ���������� ������" << endl;		
			cin >> n;		
			cout << "������� ���������� �����" << endl;
			int m;
			cin >> m;

			Graph<float> *graph = new Graph<float> (n,m);
		
			int l;
			cout << "����� ������������ ���� (1) ��� ������� (2)?" << endl;
			cin >> l;
			switch (l)
			{
			case 1:
				{
				cout << "������� ����������� � ������������ �������� ����" << endl;
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
					cout << "������� ������, ���� � ���" << endl;
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
		
			cout << "��������� ��� ����� ��� ����: " << endl<<endl;
			graph->print();
		
			cout << "��������� �������� ��������.." << endl;
			Graph<float> *res = new Graph<float> (n,m);
			sets<float> *a = new sets<float> (n);

			res = a->kruskal(graph);
			cout << endl << endl;
			res->print();
		}
		break;
	case 2:
		{
			system ("cls");
			cout << "������� ���������� ��������� � ������" << endl;
			int a;
			cin >> a;
			BQueue<int> *avl = new BQueue<int>();
			cout << "����� ������������ ������ (1) ��� ������� (2)?" << endl;
			int b;
			cin >> b;
			if (b == 1)
			{
				cout << "������� ����������� � ������������ ��������" << endl;
				int min, max;
				cin >> min;
				cin >> max;
				if (min > max)
					throw 
					exception ("������� ������ ���� ������ ���������");

				srand(time(NULL));
				for (int i=0; i<a;i++)
					avl->push(min + static_cast <int> (rand()) /( static_cast <int> (RAND_MAX/(max - min))));
			}
			if (b == 2)
			{
				int c;
				for (int i=0; i<a;i++)
				{
					cout << "������� " << i << "-� �������" << endl;
					cin >> c;
					avl->push(c);
				}
			}

			system ("cls");
			cout << "������ �������� ���: " << endl;
			avl->print();


		}
	}
}
