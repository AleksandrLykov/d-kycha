#include "graphs.h"
#include "queue.h"

void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "�������� ��������" << endl << endl;
	cout << "������� ���������� ������" << endl;
	int n;
	cin >> n;

	cout << "������� ���������� �����" << endl;
	int m;
	cin >> m;
	Graph<float> *graph = new Graph<float> (n,m);
		float *P = new float(n); //���������� ����
		for (int i=0; i<=n;i++)
			P[i] = 0;
	cout << "����� ������������ ����" << endl;
	cout << "������� ����������� � ������������ �������� ���� �����" << endl;
	float min, max;
	cin >> min;
	cin >> max;
	graph->createGraph(min, max);
	system ("cls");
	
	cout << "��������� ��� ����� ��� ����: " << endl<<endl;
	graph->print();

	cout << "������� ��������� �������" << endl;
	int a;
	cin >> a; 
	cout << "��������� ��������.." << endl << endl;
	float *dist = graph->deykstra(a,P);

	cout << "�����: " << endl << endl;	
	
	for (int i=0; i<n;i++)
		cout << i << ' ';
	cout << "- ������ ������" <<  endl << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == MAX_HTYPE)
			cout << 0 << ' ';
		else
			cout << dist[i] << ' ' ;
	cout << "- ���������� ����" <<  endl << endl;
	for (int i=0;i<n;i++)
			cout << P[i] << ' ';
	cout << "- �������������� ������� " <<  endl << endl;

}	
