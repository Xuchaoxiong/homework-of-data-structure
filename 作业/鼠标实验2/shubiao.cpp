#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct mouse
{
	int  type;
	int  x;
	int  y;
	int  tim;
	float v;
	float a;
}mse[565];

struct mouse2
{
	int type2;
	int x2;
	int y2;
	int tim2;
	float ave_v;
	float k;
}mse2[50],mse3[50];

struct speed
{	
	float time;
	float v;
	float a;
	float ave_v;
}spd[150];





/*/
void spdata(int n,struct mouse * mse)
{
int i;
	FILE * p;
p=fopen("mouse2.dat","r+");
mse[0].v =0;
mse[0].a =0;
fprintf(p,"%d %d %d %d %f %f",&mse[0].type ,&mse[0].x ,&mse[0].y ,&mse[0].tim ,&mse[0].v ,&mse[0].a);
    for (i=1;i<n;i++)
	{
	mse[i].v =sqrt((mse[i].x -mse[i-1].x )^2/(mse[i].tim -mse[i-1].tim )^2+(mse[i].x -mse[i-1].x )^2/(mse[i].tim -mse[i-1].tim )^2);
     mse[i].a =(mse[i].v-mse[i-1].v )/(mse[i].tim -mse[i-1].tim );
	 fprintf(p,"%d %d %d %d %f %f",&mse[i].type ,&mse[i].x ,&mse[i].y ,&mse[i].tim ,&mse[i].v ,&mse[i].a  );
	};
};

/*/

void delete1 (FILE *fp)
{
	int i;
	for (i=0;i<565;i++)                                                         //删除相同时间戳的两个点
	{
		fscanf(fp,"%d %d %d %d",&mse[i].type ,&mse[i].x,&mse[i].y,&mse[i].tim);
        if (mse[i].tim==mse[i-1].tim )
		{fscanf(fp,"%d %d %d %d",&mse[i].type ,&mse[i].x,&mse[i].y,&mse[i].tim);
		};
    
	//	printf("%d %d %d %d\n",mse[i].type,mse[i].x,mse[i].y,mse[i].tim);
	}

	fclose(fp); 
}



int main()
{
	int i,j,k;
	int m=0;
	k=0;
	float k1, k2;
	FILE * ffp;
    ffp=fopen("mouse2.dat","r+");
	FILE * fp;
	FILE * fp2;
	FILE * fpm1;
	FILE * fpm2;
	FILE * fpm3;
	FILE * fpm4;
	FILE * fpm5;
	FILE * fpm6;
	FILE * fpm7;
	FILE * fpm8;
	FILE * fpm9;
	FILE * fpm10;
	FILE * fpm11;
	FILE * fpm12;
	FILE * fpm13;
	FILE * fpm14;
	FILE * fpm15;
	FILE * fpm16;
	fpm1=fopen("danji1.dat","r+");
    fpm2=fopen("danji2.dat","r+");
    fpm3=fopen("danji3.dat","r+");
    fpm4=fopen("danji4.dat","r+");
    fpm5=fopen("danji5.dat","r+");
    fpm6=fopen("danji6.dat","r+");
    fpm7=fopen("danji7.dat","r+");
    fpm8=fopen("danji8.dat","r+");
    fpm9=fopen("danji9.dat","r+");
    fpm10=fopen("danji10.dat","r+");
    fpm11=fopen("danji11.dat","r+");
    fpm12=fopen("danji12.dat","r+");
    fpm13=fopen("danji13.dat","r+");
    fpm14=fopen("danji14.dat","r+");
    fpm15=fopen("danji15.dat","r+");
    fpm16=fopen("danji16.dat","r+");
	fp2=fopen("chuli.dat","r+");
	j=0;
	 void delete1 (FILE *fp);
	 FILE *m1;
	 FILE *m2;
	 FILE *m3;
	 m1=fopen("yangben1.dat","r+");
	 m2=fopen("yangben2.dat","r+");
	 m3=fopen("yangben3.dat","r+");
	 fp = fopen("mouse.dat", "r+");
	while (1)
	{
    printf("请输入样本名:\n");
    scanf("%d",&j);
if (j==1)
{
	fp=m1;
}
if (j==2)
{
	fp=m2;
}
if (j==3)
{
	fp=m3;
}
   delete1 (fp);

mse[0].v =0;
mse[0].a =0;
if(ffp==NULL){
	puts("error");
}
fprintf(ffp,"%d %d %d %d %f %f\n",&mse[0].type ,&mse[0].x ,&mse[0].y ,&mse[0].tim ,&mse[0].v ,&mse[0].a);
 for (i=1;i<565;i++)
 {
	 k1 = ( (float) mse[i].x - mse[i - 1].x) *(mse[i].x - mse[i - 1].x)/ ((mse[i].tim - mse[i - 1].tim) *(mse[i].tim - mse[i - 1].tim));
	 k2 = ( (float) mse[i].y - mse[i - 1].y) *(mse[i].y - mse[i - 1].y) / ((mse[i].tim - mse[i - 1].tim) *(mse[i].tim - mse[i - 1].tim)) ;
	 (float) k1;
     (float) k2;
	 mse[i].v = sqrt(k1 + k2);                                                                     //计算每个时间点的速度
     mse[i].a =( (float) mse[i].v-mse[i-1].v )/(mse[i].tim -mse[i-1].tim );                        //计算加速度
	 fprintf(ffp,"%d %d %d %d %f %f\n",&mse[i].type ,&mse[i].x ,&mse[i].y ,&mse[i].tim ,&mse[i].v ,&mse[i].a  );
	}






    for (i=0;i<565;i++)
	{
	
		if(mse[i].type ==513)
	{

		mse2[j].type2 =mse[i].type ;
		mse2[j].x2 =mse[i].x ;
		mse2[j].y2 =mse[i].y ;
		mse2[j].tim2=mse[i].tim ;
	fprintf(fp2,"%d %d %d %d\n",mse2[j].type2,mse2[j].x2,mse2[j].y2,mse2[j].tim2);	
	switch(j)              //将加速度分段
	{
	case 0:
	for(m=k;m<i;m++)
		{
			fprintf(fpm1,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;

	case 1:for(m=k;m<i;m++)
		{
			fprintf(fpm2,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 2:for(m=k;m<i;m++)
		{
			fprintf(fpm3,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 3:for(m=k;m<i;m++)
		{
			fprintf(fpm4,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 4:for(m=k;m<i;m++)
		{
			fprintf(fpm5,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 5:for(m=k;m<i;m++)
		{
			fprintf(fpm6,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 6:for(m=k;m<i;m++)
		{
			fprintf(fpm7,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 7:for(m=k;m<i;m++)
		{
			fprintf(fpm8,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 9:for(m=k;m<i;m++)
		{
			fprintf(fpm9,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 11:for(m=k;m<i;m++)
		{
			fprintf(fpm10,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 13:for(m=k;m<i;m++)
		{
			fprintf(fpm11,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 15:for(m=k;m<i;m++)
		{
			fprintf(fpm12,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 17:for(m=k;m<i;m++)
		{
			fprintf(fpm13,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 19:for(m=k;m<i;m++)
		{
			fprintf(fpm14,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 21:for(m=k;m<i;m++)
		{
			fprintf(fpm15,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	case 23:for(m=k;m<i;m++)
		{
			fprintf(fpm16,"%d %d %d %d %f %f\n",mse[m].type,mse[m].x,mse[m].y,mse[m].tim,mse[m].v,mse[m].a );
		};
		k=i;break;
	default:break;
	}
			j++;
	}

	};



k1=(mse[0].x -mse2[0].x2)*(mse[0].x -mse2[0].x2)+ (mse[0].y -mse2[0].y2)*(mse[0].y -mse2[0].y2);      
k2=mse2[0].tim2 -mse[0].tim ;
mse2[0].ave_v =sqrt(k1)/k2;                                                  //第一个单机点的平均速度



for(i=1;i<=7;i++)
{(float) mse2[i].x2;
(float) k1;
(float) k2;
	k1=( (float) mse2[i].x2 -mse2[i-1].x2)*(mse2[i].x2 -mse2[i-1].x2)+ (mse2[i].y2 -mse2[i-1].y2)*(mse2[i].y2 -mse2[i-1].y2);
	k2= (float) mse2[i].tim2 -mse2[i-1].tim2;
	mse2[i].ave_v =sqrt(k1)/k2;            //单机平均速度
	mse2[i].k=k2;
};



for(i=9;i<=23;i=i+2)
{
	k1=( (float) mse2[i].x2 -mse2[i-2].x2)*(mse2[i].x2 -mse2[i-2].x2)+ (mse2[i].y2 -mse2[i-2].y2)*(mse2[i].y2 -mse2[i-2].y2);
	k2=mse2[i].tim2 -mse2[i-2].tim2 ;
	mse2[i].ave_v =sqrt(k1)/k2;                                              //双击平均速度
mse2[i].k=k2;
};


for (j=0;j<=23;j++)
{
fprintf(fp2,"%d %d %d %d %f\n",mse2[j].type2,mse2[j].x2,mse2[j].y2,mse2[j].tim2,mse2[j].ave_v );
};


j=0;
for(i=0;i<=7;i++)
{
	mse3[j].type2 =mse2[i].type2 ;
	mse3[j].x2 =mse2[i].x2 ;
	mse3[j].y2 =mse2[i].y2 ;
	mse3[j].tim2 =mse2[i].tim2 ;
	mse3[j].ave_v =mse2[i].ave_v ;
	mse3[j].k=mse2[i].k;
	j++;
};


for(i=9;i<=23;i=i+2)
{      
	mse3[j].type2 =mse2[i].type2+1 ;
	mse3[j].x2 =mse2[i].x2 ;
	mse3[j].y2 =mse2[i].y2 ;
	mse3[j].tim2 =mse2[i].tim2 ;
	mse3[j].ave_v =mse2[i].ave_v ;
	mse3[j].k=mse2[i].k;
	j++;                                     //双击平均速度
};
int t;
float q;

	FILE * fp3;
	fp3=fopen("chuli2.dat","r+");
for(j=0;j<15;j++)
for(i=0;i<15-j;i++)
if (mse3[i].ave_v >mse3[i+1].ave_v)
{
	t=mse3[i].type2 ;mse3[i].type2 =mse3[i+1].type2;mse3[i+1].type2=t;
t=mse3[i].x2 ;mse3[i].x2 =mse3[i+1].x2;mse3[i+1].x2=t;
t=mse3[i].y2 ;mse3[i].y2 =mse3[i+1].y2;mse3[i+1].y2=t;
t=mse3[i].tim2 ;mse3[i].tim2 =mse3[i+1].tim2;mse3[i+1].tim2=t;
q=mse3[i].ave_v  ;mse3[i].ave_v =mse3[i+1].ave_v ;mse3[i+1].ave_v =q;
}



for(i=0;i<=15;i++)
{
	fprintf(fp3,"%d %d %d %d %f\n",mse3[i].type2,mse3[i].x2,mse3[i].y2,mse3[i].tim2,mse3[i].ave_v );

}




for(j=0;j<15;j++)
for(i=0;i<15-j;i++)
if (mse3[i].k >mse3[i+1].k)
{
	t=mse3[i].type2 ;mse3[i].type2 =mse3[i+1].type2;mse3[i+1].type2=t;
t=mse3[i].x2 ;mse3[i].x2 =mse3[i+1].x2;mse3[i+1].x2=t;
t=mse3[i].y2 ;mse3[i].y2 =mse3[i+1].y2;mse3[i+1].y2=t;
t=mse3[i].tim2 ;mse3[i].tim2 =mse3[i+1].tim2;mse3[i+1].tim2=t;
q=mse3[i].ave_v  ;mse3[i].ave_v =mse3[i+1].ave_v ;mse3[i+1].ave_v =q;
}

	FILE * fp4;
	fp4=fopen("chuli3.dat","r+");
for(i=0;i<=15;i++)
{
	fprintf(fp4,"%d %d %d %d %f\n",mse3[i].type2,mse3[i].x2,mse3[i].y2,mse3[i].tim2,mse3[i].k );

}

}



	return 0;
}

