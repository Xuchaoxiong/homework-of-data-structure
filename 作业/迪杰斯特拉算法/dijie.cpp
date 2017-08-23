#include <iostream>  
using namespace std;
#ifndef GUIDE_H_INCLUDED  
#define GUIDE_H_INCLUDED  
#define MX 1000          //���ֵ ����  
#define NUM  6            //��󶥵����  
typedef int adjmatrix[NUM][NUM];
typedef int path[NUM][NUM];
typedef int Dist[NUM];//v0��vi�ĵľ���  
int ps[NUM] = { 0 }; //���·��ֵ  
int final[NUM];//final[i]=1�����Ѿ����v0��vi�����·��  
const int vexs[NUM] = { 0, 1, 2, 3, 4, 5 };
int arcs[NUM][NUM] = {
	{ MX, MX, 10, MX, 30, 100 },
	{ MX, MX, 5, MX, MX, MX },
	{ MX, MX, MX, 50, MX, MX },
	{ MX, MX, MX, MX, MX, 10 },
	{ MX, MX, MX, 20, MX, 60 },
	{ MX, MX, MX, MX, MX, MX }
};

#endif  

//=====================================================  
void ShorttestPath_DIJ(adjmatrix arc, int v, path &p, Dist &d)
{
	//�õϽ�˹�����㷨���v0�������������·����p[v][w]����v0��v����w  


	int w = 0;
	for (int nv = 0; nv<NUM; nv++)
	{
		final[nv] = 0;
		d[nv] = arc[v][nv];
		ps[nv] = d[nv];
		for (int w = 0; w<NUM; w++) p[nv][w] = false;
		if (d[nv]<MX)
		{
			p[nv][v] = 1;
			p[nv][nv] = 1;
		}
	}//for  
	d[v] = 0;
	final[v] = 1;
	int min = MX;
	//��ʼ��ѭ��  
	for (int i = 1; i<NUM; ++i)
	{
		min = MX;
		for (w = 0; w<NUM; ++w)
		{
			if (final[w] == 0)
			{
				if (d[w]<min)
				{
					v = w;
					min = d[w];
				}
			}

		}//for  
		final[v] = 1;
		for (w = 0; w<NUM; w++)
		{
			if (final[w] == 0 && (min + arc[v][w])<d[w])
			{
				d[w] = min + arc[v][w];
				ps[w] = ps[v] + arc[v][w];
				for (int pos = 0; pos<NUM; pos++)
				{
					p[w][pos] = p[v][pos];//�������·������w��  

				}
				p[w][w] = 1;//����w��  
			}//endif  

		}//for  


	}//for  


}

void DIJ_Print(int start, path &P)
{
	for (int i = 1; i<NUM; i++)
	{
		int u = i;

		if (final[i] == 1)
		{
			cout << "���룺" << ps[i] << "\t";
			cout << start;
			int m = start;
			for (int j = 1; j<NUM; j++)
			{

				if (P[u][j] == 1)
				{
					if (arcs[m][j]>0 && arcs[m][j]<MX)
					{
						cout << "->" << j;
						m = j;
						j = 1;
					}

				}
			}
			cout << endl;
		}//endif  
	}//endfor  
}
void ShortestPath()
{
	int start = 5;

	Dist D;       //D[i]��ʾ��start��i����̾��룻  
	path P;       //P[i,j]��ʾ��start��i�����·���ϻᾭ��j  
	int t[NUM] = { 0 };
	int n = 0;
	cout << "��������� (0~5 �ո�ָ�)" << endl;
	cin >> start;
	if (start >= 0 && start<6)
	{
		//���õϽ�˹�����㷨  
		ShorttestPath_DIJ(arcs, start, P, D);
		cout << "��" << start;
		cout << "��������������·������ ��" << endl;
		//���õϽ�˹������ӡ�㷨  
		DIJ_Print(start, P);

	}//endif  
	else
		cout << "û������ط���" << endl;
}


//============== mian�ļ� =============  

int main()
{
	char choose = 0;
	cout << "************************" << endl;
	cout << "    a.x������������·��        " << endl;
	cout << "    b.�˳�            " << endl;
	cout << "    �汾��v1.8        " << endl;
	cout << "************************" << endl;
	cin >> choose;
	while (choose != 'b')
	{
		if (choose == 'a')
		{
			ShortestPath();
			cout << "===========================" << endl;
			cout << "  a.x��y�����·�� b.�˳�  " << endl;
			cout << "===========================" << endl;
		}
		else if (choose != 'a' || choose != 'b')    cout << "����������������룺";
		cin >> choose;
	}
	return 0;
}