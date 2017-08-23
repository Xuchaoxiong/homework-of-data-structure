#include <stdio.h>
#include <math.h>
#include <string.h>





//定义结构体
struct touscr
{
	int x;
	int y;
	int tim;
	float force;
	int id;
	int leth1;
	int leth2;
	double leth;
	int xy;
}tscr1[300],tscr2[300],tscr3[300],tscr10[300],tscr11[300],tscr12[300],tscr13[300],tscr20[300],tscr21[300],tscr22[300],tscr23[300],tscr30[300],tscr31[300],tscr32[300],tscr33[300];

//排序函数

int min(touscr tscr1[],int n1)
{
	int n;
	n=0;
	for (int i=1;i<=n1-1;i++)
	{
		if (tscr1[i].xy <=tscr1[n].xy )
		{
			n=i;
		}
	//	printf("%d\n",tscr1[i].xy);
	}
//	printf("%d %d\n",n,n1);
	return n;
}






//计算比例
float scale(touscr tscr[],int n1,int n)  //n1为分段点，n为长度
{
	float k1,k2;
	k1 = (float)pow((float)(tscr[n1].x - tscr[0].x), 2) + pow((float)(tscr[n1].y - tscr[0].y), 2);
	k2 = (float)pow((float)(tscr[n].x - tscr[n1].x), 2) + pow((float)(tscr[n].y - tscr[n1].y), 2);
	k1=k1/k2;
	k1=sqrt(k1);
//	printf("%d  %d\n",n1,n);
	return k1;
}





//主函数
int main()
{
	//定义三个文件的文件指针
	
	FILE *fpts1;
	FILE *fpts2;
	FILE *fpts3;

	/*/
	FILE *fpts10;
	FILE *fpts11;
	FILE *fpts12;
	FILE *fpts13;
	FILE *fpts20;
	FILE *fpts21;
	FILE *fpts22;
	FILE *fpts23;
	FILE *fpts30;
	FILE *fpts31;
	FILE *fpts32;
	FILE *fpts33;

	
	fpts10=fopen("ts10.dat","rb+");
	fpts11=fopen("ts11.dat","rb+");
	fpts12=fopen("ts12.dat","rb+");
	fpts13=fopen("ts13.dat","rb+");
	fpts20=fopen("ts20.dat","rb+");
	fpts21=fopen("ts21.dat","rb+");
	fpts22=fopen("ts22.dat","rb+");
	fpts23=fopen("ts23.dat","rb+");
	fpts30=fopen("ts30.dat","rb+");
	fpts31=fopen("ts31.dat","rb+");
	fpts32=fopen("ts32.dat","rb+");
	fpts33=fopen("ts33.dat","rb+");


/*/
	
	fpts1 = fopen("ts1.dat", "r+");
	fpts2 = fopen("ts2.dat", "r+");
	fpts3 = fopen("ts3.dat", "r+");
	
	int i, j;
	//定义三个样本的数目
	int n1=0;                         //样本1的数据数目
	int n2=0;                         //样本2的数据数目
	int n3=0;                         //样本3的数据数目
    int n10,n11,n12,n13,n20,n21,n22,n23,n30,n31,n32,n33;
	n10=n11=n12=n13=n20=n21=n22=n23=n30=n31=n32=n33=0;           //赋初值
	int fen[3][3];
	float prop[3][3];
	//为3个样本赋值
	if (fpts1==NULL)
	{
		printf("error");
		return -1;
	}

	for (i=0;i<=300;i++)
	{
		fscanf(fpts1,"%d %d %d %f %d %d %d",&(tscr1[i].x) ,&(tscr1[i].y) ,&tscr1[i].tim ,&tscr1[i].force ,&tscr1[i].id ,&tscr1[i].leth1 ,&tscr1[i].leth2 );
		tscr1[i].leth=sqrt((float)tscr1[i].x*tscr1[i].x+tscr1[i].y*tscr1[i].y);
		tscr1[i].xy=tscr1[i].x*tscr1[i].y;
		if (tscr1[i].x==0&&i!=0)
		{
			break;
		}
		else
		{
			n1++;
		}
	}
	
		for (i=0;i<=300;i++)
	{
		fscanf(fpts2,"%d %d %d %f %d %d %d",&tscr2[i].x ,&tscr2[i].y ,&tscr2[i].tim ,&tscr2[i].force ,&tscr2[i].id ,&tscr2[i].leth1 ,&tscr2[i].leth2 );
		tscr2[i].leth=sqrt((float)tscr2[i].x*tscr2[i].x+tscr2[i].y*tscr2[i].y);
		tscr2[i].xy=tscr2[i].x*tscr2[i].y;
		if (tscr2[i].x==0)
		{
			break;
		}
		else
		{
			n2++;
		}
	}


			for (i=0;i<=300;i++)
	{
		fscanf(fpts3,"%d %d %d %f %d %d %d",&tscr3[i].x ,&tscr3[i].y ,&tscr3[i].tim ,&tscr3[i].force ,&tscr3[i].id ,&tscr3[i].leth1 ,&tscr3[i].leth2 );
		tscr3[i].leth=sqrt((float)tscr3[i].x*tscr3[i].x+tscr3[i].y*tscr3[i].y);
		tscr3[i].xy=tscr3[i].x*tscr3[i].y;
		if (tscr3[i].x==0)
		{
			break;
		}
		else
		{
			n3++;
		}
	}
			
			
//分段

	    for(i=0;i<=n1-5;i++)
		{
			if (i<=3||tscr1[i].x!=tscr1[i-4].x)
		{

			switch(tscr1[i].id)
			{
			case 0:tscr10[n10].x =tscr1[i].x ;
				tscr10[n10].y =tscr1[i].y ;
				tscr10[n10].tim  =tscr1[i].tim;
				tscr10[n10].force  =tscr1[i].force ;
				tscr10[n10].id  =tscr1[i].id ;
				tscr10[n10].leth1  =tscr1[i].leth1  ;
				tscr10[n10].leth2  =tscr1[i].leth2 ;
				tscr10[n10].leth =tscr1[i].leth ;
				tscr10[n10].xy =tscr1[i].xy ;
				n10++;break;
			case 1:tscr11[n11].x =tscr1[i].x ;
				tscr11[n11].y =tscr1[i].y ;
				tscr11[n11].tim  =tscr1[i].tim;
				tscr11[n11].force  =tscr1[i].force ;
				tscr11[n11].id  =tscr1[i].id ;
				tscr11[n11].leth1  =tscr1[i].leth1  ;
				tscr11[n11].leth2  =tscr1[i].leth2 ;
				tscr11[n11].leth =tscr1[i].leth ;
				tscr11[n11].xy =tscr1[i].xy ;
				n11++;break;
			case 2:tscr12[n12].x =tscr1[i].x ;
				tscr12[n12].y =tscr1[i].y ;
				tscr12[n12].tim  =tscr1[i].tim;
				tscr12[n12].force  =tscr1[i].force ;
				tscr12[n12].id  =tscr1[i].id ;
				tscr12[n12].leth1  =tscr1[i].leth1  ;
				tscr12[n12].leth2  =tscr1[i].leth2 ;
				tscr12[n12].leth =tscr1[i].leth ;
				tscr12[n12].xy =tscr1[i].xy ;
				n12++;break;
            case 3:tscr13[n13].x =tscr1[i].x ;
				tscr13[n13].y =tscr1[i].y ;
				tscr13[n13].tim  =tscr1[i].tim;
				tscr13[n13].force  =tscr1[i].force ;
				tscr13[n13].id  =tscr1[i].id ;
				tscr13[n13].leth1  =tscr1[i].leth1  ;
				tscr13[n13].leth2  =tscr1[i].leth2 ;
				tscr13[n13].leth =tscr1[i].leth ;
				tscr13[n13].xy =tscr1[i].xy ;
				n13++;break;
			}
		}


		}



	for(i=0;i<=n2-5;i++)
	{
			if (i<=3||tscr2[i].x!=tscr2[i-4].x)
			{
			switch(tscr2[i].id)
			{
			case 0:tscr20[n20].x =tscr2[i].x ;
				tscr20[n20].y =tscr2[i].y ;
				tscr20[n20].tim  =tscr2[i].tim;
				tscr20[n20].force  =tscr2[i].force ;
				tscr20[n20].id  =tscr2[i].id ;
				tscr20[n20].leth1  =tscr2[i].leth1  ;
				tscr20[n20].leth2  =tscr2[i].leth2 ;
				tscr20[n20].leth =tscr2[i].leth ;
				tscr20[n20].xy =tscr2[i].xy ;
				n20++;break;
			case 1:tscr21[n21].x =tscr2[i].x ;
				tscr21[n21].y =tscr2[i].y ;
				tscr21[n21].tim  =tscr2[i].tim;
				tscr21[n21].force  =tscr2[i].force ;
				tscr21[n21].id  =tscr2[i].id ;
				tscr21[n21].leth1  =tscr2[i].leth1  ;
				tscr21[n21].leth2  =tscr2[i].leth2 ;
				tscr21[n21].leth =tscr2[i].leth ;
				tscr21[n21].xy =tscr2[i].xy ;
				n21++;break;
			case 2:tscr22[n22].x =tscr2[i].x ;
				tscr22[n22].y =tscr2[i].y ;
				tscr22[n22].tim  =tscr2[i].tim;
				tscr22[n22].force  =tscr2[i].force ;
				tscr22[n22].id  =tscr2[i].id ;
				tscr22[n22].leth1  =tscr2[i].leth1  ;
				tscr22[n22].leth2  =tscr2[i].leth2 ;
				tscr22[n22].leth =tscr2[i].leth ;
				tscr22[n22].xy =tscr2[i].xy ;
				n22++;break;
            case 3:tscr23[n23].x =tscr2[i].x ;
				tscr23[n23].y =tscr2[i].y ;
				tscr23[n23].tim  =tscr2[i].tim;
				tscr23[n23].force  =tscr2[i].force ;
				tscr23[n23].id  =tscr2[i].id ;
				tscr23[n23].leth1  =tscr2[i].leth1  ;
				tscr23[n23].leth2  =tscr2[i].leth2 ;
				tscr23[n23].leth =tscr2[i].leth ;
				tscr23[n23].xy =tscr2[i].xy ;
				n23++;break;
			}

			}



		}


		for(i=0;i<=n3-5;i++)
	{
				if (i<=3||tscr3[i].x!=tscr3[i-4].x)
				{
			switch(tscr3[i].id)
			{
			case 0:tscr30[n30].x =tscr3[i].x ;
				tscr30[n30].y =tscr3[i].y ;
				tscr30[n30].tim  =tscr3[i].tim;
				tscr30[n30].force  =tscr3[i].force ;
				tscr30[n30].id  =tscr3[i].id ;
				tscr30[n30].leth1  =tscr3[i].leth1  ;
				tscr30[n30].leth2  =tscr3[i].leth2 ;
				tscr30[n30].leth =tscr3[i].leth ;
				tscr30[n30].xy =tscr3[i].xy ;
				n30++;break;
			case 1:tscr31[n31].x =tscr3[i].x ;
				tscr31[n31].y =tscr3[i].y ;
				tscr31[n31].tim  =tscr3[i].tim;
				tscr31[n31].force  =tscr3[i].force ;
				tscr31[n31].id  =tscr3[i].id ;
				tscr31[n31].leth1  =tscr3[i].leth1  ;
				tscr31[n31].leth2  =tscr3[i].leth2 ;
				tscr31[n31].leth =tscr3[i].leth ;
				tscr31[n31].xy =tscr3[i].xy ;
				n31++;break;
			case 2:tscr32[n32].x =tscr3[i].x ;
				tscr32[n32].y =tscr3[i].y ;
				tscr32[n32].tim  =tscr3[i].tim;
				tscr32[n32].force  =tscr3[i].force ;
				tscr32[n32].id  =tscr3[i].id ;
				tscr32[n32].leth1  =tscr3[i].leth1  ;
				tscr32[n32].leth2  =tscr3[i].leth2 ;
				tscr32[n32].leth =tscr3[i].leth ;
				tscr32[n32].xy =tscr3[i].xy ;
				n32++;break;
            case 3:tscr33[n33].x =tscr3[i].x ;
				tscr33[n33].y =tscr3[i].y ;
				tscr33[n33].tim  =tscr3[i].tim;
				tscr33[n33].force  =tscr3[i].force ;
				tscr33[n33].id  =tscr3[i].id ;
				tscr33[n33].leth1  =tscr3[i].leth1  ;
				tscr33[n33].leth2  =tscr3[i].leth2 ;
				tscr33[n33].leth =tscr3[i].leth ;
				tscr33[n33].xy =tscr3[i].xy ;
				n33++;break;
			}
				}



		}

 //分段点
		fen[1][0]=min(tscr10,n10);
		fen[1][1]=min(tscr11,n11);
		fen[1][2]=min(tscr12,n12);
		fen[1][3]=min(tscr13,n13);
		fen[2][0]=min(tscr20,n20);
		fen[2][1]=min(tscr21,n21);
		fen[2][2]=min(tscr22,n22);
		fen[2][3]=min(tscr23,n23);
		fen[3][0]=min(tscr30,n30);
		fen[3][1]=min(tscr31,n31);
		fen[3][2]=min(tscr32,n32);
		fen[3][3]=min(tscr33,n33);

       // printf("%d",fen[1][0]);


//计算比例
		prop[1][0]=scale(tscr10,fen[1][0], n10);
		prop[1][1]=scale(tscr11,fen[1][1], n11);
		prop[1][2]=scale(tscr12,fen[1][2], n12);
		prop[1][3]=scale(tscr13,fen[1][3], n13);
		prop[2][0]=scale(tscr20,fen[2][0], n20);
		prop[2][1]=scale(tscr21,fen[2][1], n21);
		prop[2][2]=scale(tscr22, fen[2][2], n22);
		prop[2][3]=scale(tscr23, fen[2][3], n23);
		prop[3][0]=scale(tscr30, fen[3][0], n30);
		prop[3][1]=scale(tscr31, fen[3][1], n31);
		prop[3][2]=scale(tscr32, fen[3][2], n32);
		prop[3][3]=scale(tscr33, fen[3][3], n33);

for (i=1;i<=3;i++)
{
	for(j=0;j<=3;j++)
	{
		printf("%f\n",prop[i][j]);
	}
}

int a1,a2,a3;
a1=22;
a2=fen[2][0];
a3=fen[3][0];
//printf("%d %d %d",a1,a2,a3);

printf("%d  %d  %d\n",tscr10[a1].x,tscr20[a2].x ,tscr30[a3].x);

     return 0;

}







