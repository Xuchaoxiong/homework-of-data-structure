#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#define INFINITY 1000








//迪杰斯特拉算法

void shortestpath_DIJ(int n,int arcs[10][10],int D[10],int p[10][10],int final[10])
{
	//用Dijkstra算法求有向网G的v0顶点到其余顶点v的最短路径平p[v]及其带权长度D[V]
	int v0,w,i,min;
	int v;
	v0 = 0;
	for(v=0;v<n;v++)            //循环 初始化
	{
		final[v]= 0;D[v]=arcs[v0][v];
		for(w=0;w<n;++w) p[v][w]=-1;   //设空路径
		if (D[v]<INFINITY){p[v][0]=v0;p[v][1]=v;}
	}//for
	D[v0]=0;final[v0]=1;       //初始化,v0顶点属于S集
	//开始主循环，每次求得v0到某个v顶点的最短路径，并加v到S集
    for(i=1;i<n;i++)
	{
		min= INFINITY;                  //当前所知离v0顶点的最近距离
	for(w=0;w<n;w++)
	{
		if(!final[w])
		{
			//这个过程最终选出的点 是选出当前v-s中与s有关联边且权值最小的点
		if(D[w]<min){v=w;min=D[w];}
		}
	}
final[v]=1; //选出该点加到集合s中
for(w=0;w<n;w++)// 更新当前最短路径和距离
{
	if(!final[w]&&(min+arcs[v][w]<D[w]))
{
	D[w]=min+arcs[v][w];
	//p[w]=p[v];
for (i = 0; i < n; i++) //修改p[w]，v0到w经过的顶点包括v0到v经过的所有顶点再加上顶点w
						{
					p[w][i] = p[v][i];
					if (p[w][i] == -1) //在p[w][]第一个等于-1的地方加上顶点w
							{
						p[w][i] = w;
						break;
					}
				}

}
	}
	}

}









//显示路径


void DIJ_Print(int n,int start, int p[10][10],int final[10],int D[10],int arcs[10][10])
{int i,j;
	for (i = 0; i < n; i++) {
		if (i != 0 && D[i] != INFINITY) {
			printf("v0到v%d的最短路径长度为%d\t", i, D[i]);
			printf("v0到第v%d点的路径为： v0", i);
			for (j = 1; j < n; j++) {
				if (p[i][j]>-1)	
				  printf("->v%d", p[i][j]);
				if (p[i][j + 1] == -1)		
					printf("\n");
			}
		} else if (D[i] == INFINITY)
			printf("v0到v%d不可达\n", i);
	} //输出最短路径长度和路径

}





	




//主函数
int main()
{
	int arcs[10][10];//邻接矩阵
int D[10];//保存最短路径长度
int p[10][10];//路径
int final[10];//若final[i] = 1则说明 顶点vi已在集合S中
int n = 0;//顶点个数
int v0 = 0;//源点
int v,w;
int start;
int i,j;
	printf("请输入当前图的节点数:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("输入%d行%d列邻阶矩阵的权值:",i,j);
			scanf("%d", &arcs[i][j]);
		}
	}
	shortestpath_DIJ(n,arcs,D,p,final);
	printf("请输入起始点:");
	scanf("%d",&start);
	DIJ_Print(n, start,p, final, D, arcs);
	for (i=0;i<n;i++) printf("D[%d]=%d\n",i,D[i]);
	return 0;
}

