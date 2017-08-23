#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#define INFINITY 1000








//�Ͻ�˹�����㷨

void shortestpath_DIJ(int n,int arcs[10][10],int D[10],int p[10][10],int final[10])
{
	//��Dijkstra�㷨��������G��v0���㵽���ඥ��v�����·��ƽp[v]�����Ȩ����D[V]
	int v0,w,i,min;
	int v;
	v0 = 0;
	for(v=0;v<n;v++)            //ѭ�� ��ʼ��
	{
		final[v]= 0;D[v]=arcs[v0][v];
		for(w=0;w<n;++w) p[v][w]=-1;   //���·��
		if (D[v]<INFINITY){p[v][0]=v0;p[v][1]=v;}
	}//for
	D[v0]=0;final[v0]=1;       //��ʼ��,v0��������S��
	//��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��������v��S��
    for(i=1;i<n;i++)
	{
		min= INFINITY;                  //��ǰ��֪��v0������������
	for(w=0;w<n;w++)
	{
		if(!final[w])
		{
			//�����������ѡ���ĵ� ��ѡ����ǰv-s����s�й�������Ȩֵ��С�ĵ�
		if(D[w]<min){v=w;min=D[w];}
		}
	}
final[v]=1; //ѡ���õ�ӵ�����s��
for(w=0;w<n;w++)// ���µ�ǰ���·���;���
{
	if(!final[w]&&(min+arcs[v][w]<D[w]))
{
	D[w]=min+arcs[v][w];
	//p[w]=p[v];
for (i = 0; i < n; i++) //�޸�p[w]��v0��w�����Ķ������v0��v���������ж����ټ��϶���w
						{
					p[w][i] = p[v][i];
					if (p[w][i] == -1) //��p[w][]��һ������-1�ĵط����϶���w
							{
						p[w][i] = w;
						break;
					}
				}

}
	}
	}

}









//��ʾ·��


void DIJ_Print(int n,int start, int p[10][10],int final[10],int D[10],int arcs[10][10])
{int i,j;
	for (i = 0; i < n; i++) {
		if (i != 0 && D[i] != INFINITY) {
			printf("v0��v%d�����·������Ϊ%d\t", i, D[i]);
			printf("v0����v%d���·��Ϊ�� v0", i);
			for (j = 1; j < n; j++) {
				if (p[i][j]>-1)	
				  printf("->v%d", p[i][j]);
				if (p[i][j + 1] == -1)		
					printf("\n");
			}
		} else if (D[i] == INFINITY)
			printf("v0��v%d���ɴ�\n", i);
	} //������·�����Ⱥ�·��

}





	




//������
int main()
{
	int arcs[10][10];//�ڽӾ���
int D[10];//�������·������
int p[10][10];//·��
int final[10];//��final[i] = 1��˵�� ����vi���ڼ���S��
int n = 0;//�������
int v0 = 0;//Դ��
int v,w;
int start;
int i,j;
	printf("�����뵱ǰͼ�Ľڵ���:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("����%d��%d���ڽ׾����Ȩֵ:",i,j);
			scanf("%d", &arcs[i][j]);
		}
	}
	shortestpath_DIJ(n,arcs,D,p,final);
	printf("��������ʼ��:");
	scanf("%d",&start);
	DIJ_Print(n, start,p, final, D, arcs);
	for (i=0;i<n;i++) printf("D[%d]=%d\n",i,D[i]);
	return 0;
}

