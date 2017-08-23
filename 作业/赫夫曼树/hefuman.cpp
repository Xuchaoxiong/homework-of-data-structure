#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>


typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char * * HuffmanCode;





//构建赫夫曼树
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
	HuffmanTree p;
	int m,i;
	if (n<=1) return;
	m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	i=1;
	for(p=HT;i<=n;++i,++p,++w) {
		(*p).weight=*w;(*p).lchild=0;(*p).parent=0;(*p).rchild=0;
	};
	for(;i<=m;++i,++p){
	(*p).weight=0;(*p).lchild=0;(*p).parent=0;(*p).rchild=0;
	}

	for(i=n+1;i<=m;++i){
		HT[i].parent=i;HT[i+1].parent=i;
		HT[i].lchild=i;HT[i].rchild=i+1;
		HT[i].weight=w[i+n]+w[i+n+1];
	};

	
	


//求赫夫曼编码
HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
int f,start,c;
char cd[100];
cd[n-1]='\0';
for (i=1;i<=n;++i){
	start=n-1;
	c=i;
	for(f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		if(HT[f].lchild==c) cd[--start]='0';
		else cd[--start]='1';
		HC[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],cd+start);
}
delete cd;
}

//输入函数
void zimu(char *a){
}



void quanzhi(int *b){
	printf("请输入此字母的权值:\n");
	scanf("%d",b);
}



	
//主函数
	void main(){
		int i,j,t,n;
		printf("请输入分别输入字符的个数:\n");
		std::cin>>n;
		std::cout<<n<<std::endl;
		fflush(stdout);
		HuffmanTree HT;
        char **HC;
		char k;
		char a[100];
		int b[100];
		for(i=0;i<=n;i++){
			printf("请输入你要编码的字母:\n");
			fflush(stdin);	
			scanf("%C",a);
			quanzhi(b+i);
		};
		for(i=0;i<=n;i++){
			for(j=0;j<=n-i;j++){
				if(b[j]>b[j+1])
				{t=b[j];b[j]=b[j+1];b[j+1]=t;k=a[j];a[j]=a[j+1];a[j+1]=k;};
			};
		}
		HuffmanCoding(HT,HC,b,n);
	}














