#include "sets.h"
#include "queue_bintree.h"
#include "table.h"
#include "queue_table.h"
#include <conio.h>


void main ()
{
	setlocale(LC_CTYPE, "Russian");
	int z;
	FILE *myfile;
	cout << "��������� ��������" << endl;
	cout << "������� ��� ������������ �������: " << endl;
	cout << "1) d-����" << endl;
	cout << "2) �������� �����o" << endl;
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

			Graph<typ> *graph = new Graph<typ> (n,m);
		
			int l;
			cout << "����� ������������ ���� (1), ������� (2) ��� ������ � ����� (3)?" << endl;
			cin >> l;
			switch (l)
			{
			case 1:
				{
				cout << "������� ����������� � ������������ �������� ����" << endl;
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
					cout << "������� ������, ���� � ���" << endl;
					int a,b;
					typ c;
					cin >> a;
					cin >> b;
					cin >> c;
					graph->addEdge(a,b,c);
				}
				break;	
				}
			case 3:
				{
					myfile = fopen ("C:\\file.txt", "r");
					int a = 0, b = 0 ,i = 0, tmp1 = 0, tmp2 = 0;
					typ c = 0;
					while (i < m)
					{
						fscanf (myfile, "%d%d%f\n", &a, &b, &c);
						if ((tmp1 == a) && (tmp2 == b))
							break;
						tmp1 = a;
						tmp2 = b;
						graph->addEdge (a,b,c);
						i++;
					}
					fclose(myfile);
				}
				break;
			}
	
			system ("cls");
		
			cout << "��������� ��� ����� ��� ����: " << endl<<endl;
			graph->print();
			
			cout << "��������� �������� ��������.." << endl;
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
			cout << "������� ���������� ������" << endl;		
			cin >> n;		
			cout << "������� ���������� �����" << endl;
			int m;
			cin >> m;

			Graph<typ> *graph = new Graph<typ> (n,m);
		
			int l;
			cout << "����� ������������ ���� (1), ������� (2) ��� ������ � ����� (3)?" << endl;
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
			case 3:
				{
					myfile = fopen ("C:\\file.txt", "r");
					int a = 0, b = 0 ,i = 0, tmp1 = 0, tmp2 = 0;
					typ c = 0;
					while (i < m)
					{
						fscanf (myfile, "%d%d%f\n", &a, &b, &c);
						if ((tmp1 == a) && (tmp2 == b))
							break;
						tmp1 = a;
						tmp2 = b;
						graph->addEdge (a,b,c);
						i++;
					}
					fclose(myfile);
				}
				break;
			}
	
			system ("cls");
		
			cout << "��������� ��� ����� ��� ����: " << endl<<endl;
			graph->print();
		
			cout << "��������� �������� ��������.." << endl;
			Graph<typ> *res = new Graph<typ> (n,m);
			bintree<typ> *a = new bintree<typ> ();

			graph->sort();
			res = a->kruskal(graph);
			cout << endl << endl;
			res->print();
		}
		break;
	case 3:
		{
			system ("cls");
			int n;
			cout << "������� ���������� ������" << endl;		
			cin >> n;		
			cout << "������� ���������� �����" << endl;
			int m;
			cin >> m;

			Graph<typ> *graph = new Graph<typ> (n,m);
		
			int l;
			cout << "����� ������������ ���� (1), ������� (2) ��� ������ � ����� (3)?" << endl;
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
			case 3:
				{
					myfile = fopen ("C:\\file.txt", "r");
					int a = 0, b = 0 ,i = 0, tmp1 = 0, tmp2 = 0;
					typ c = 0;
					while (i < m)
					{
						fscanf (myfile, "%d%d%f\n", &a, &b, &c);
						if ((tmp1 == a) && (tmp2 == b))
							break;
						tmp1 = a;
						tmp2 = b;
						graph->addEdge (a,b,c);
						i++;
					}
					fclose(myfile);
				}
				break;
			}
	
			system ("cls");
		
			cout << "��������� ��� ����� ��� ����: " << endl<<endl;
			graph->print();
		
			cout << "��������� �������� ��������.." << endl;
			Graph<typ> *res = new Graph<typ> (n,m);
			SortTable<typ> *a = new SortTable<typ> (m);

			graph->sort();
			res = a->kruskal(graph);
			cout << endl << endl;
			res->print();
		}
	}
}
