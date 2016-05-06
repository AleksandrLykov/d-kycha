#include "sets.h"

void main ()
{
	setlocale(LC_CTYPE, "Russian");
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
		cout << "������� ����������� � ������������ �������� ����" << endl;
		int min, max;
		cin >> min;
		cin >> max;
		graph->createGraph(min, max);
		break;
	case 2:
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
