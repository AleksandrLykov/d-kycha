#include "sets.h"

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	int n;
	cout << "������������ �������������" << endl;
	cout << "������� ���������� ������" << endl;

	cin >> n;

	cout << "������� ���������� �����" << endl;
	int m;
	cin >> m;
	Graph<int> *graph = new Graph<int> (n,m);
	
	cout << "����� ������������ ����" << endl;
	cout << "������� ����������� � ������������ �������� ���� �����" << endl;
	int min, max;
	cin >> min;
	cin >> max;
	graph->createGraph(min, max);
	system ("cls");
	
	cout << "��������� ��� ����� ��� ����: " << endl<<endl;
	graph->print();

	cout << "��������� �������� ��������.." << endl;
	Graph<int> *res = new Graph<int> (n,m);
	sets<int> *a = new sets<int> (n);

	res = a->kruskal(graph);
	cout << endl << endl;
	res->print();
}
