#include <iostream>  
using namespace std;
#ifndef GUIDE_H_INCLUDED  
#define GUIDE_H_INCLUDED  
#define MX 1000          //最大值 无穷  
#define NUM  6            //最大顶点个数  
typedef int adjmatrix[NUM][NUM];
typedef int path[NUM][NUM];
typedef int Dist[NUM];//v0到vi的的距离  
int ps[NUM] = { 0 }; //最短路径值  
int final[NUM];//final[i]=1代表已经求出v0到vi的最短路径  
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
	//用迪杰斯特拉算法求解v0到其余个点的最短路径，p[v][w]代表v0到v经过w  


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
	//开始主循环  
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
					p[w][pos] = p[v][pos];//借助最短路径到达w点  

				}
				p[w][w] = 1;//经过w点  
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
			cout << "距离：" << ps[i] << "\t";
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

	Dist D;       //D[i]表示从start到i的最短距离；  
	path P;       //P[i,j]表示从start到i的最短路径上会经过j  
	int t[NUM] = { 0 };
	int n = 0;
	cout << "输入出发点 (0~5 空格分隔)" << endl;
	cin >> start;
	if (start >= 0 && start<6)
	{
		//调用迪杰斯特拉算法  
		ShorttestPath_DIJ(arcs, start, P, D);
		cout << "从" << start;
		cout << "到其他各点的最短路径长度 ：" << endl;
		//调用迪杰斯特拉打印算法  
		DIJ_Print(start, P);

	}//endif  
	else
		cout << "没有这个地方！" << endl;
}


//============== mian文件 =============  

int main()
{
	char choose = 0;
	cout << "************************" << endl;
	cout << "    a.x到其他点的最短路径        " << endl;
	cout << "    b.退出            " << endl;
	cout << "    版本号v1.8        " << endl;
	cout << "************************" << endl;
	cin >> choose;
	while (choose != 'b')
	{
		if (choose == 'a')
		{
			ShortestPath();
			cout << "===========================" << endl;
			cout << "  a.x到y的最短路径 b.退出  " << endl;
			cout << "===========================" << endl;
		}
		else if (choose != 'a' || choose != 'b')    cout << "输入错误，请重新输入：";
		cin >> choose;
	}
	return 0;
}