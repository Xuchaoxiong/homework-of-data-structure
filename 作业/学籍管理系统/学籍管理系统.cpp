#include "stdio.h" 
#include "stdlib.h" 
#include "string.h" 
int shoudsave=0; /* */ 
struct student 
{ 
char num[10];/* ѧ�� */ 
char name[20]; 
char sex[4]; 
int cgrade; 
int mgrade; 
int egrade; 
int totle; 
int ave; 
}term; 

typedef struct node 
{ 
struct student data; 
struct node *next; 
}Node,*Link; 

void menu() 
{ 
printf("\t1�Ǽ�ѧ������\t\t\t\t\t2ɾ��ѧ������\n"); 
printf("\t3��ѯѧ������\t\t\t\t\t4�޸�ѧ������\n"); 
printf("\t5����ѧ������\t\t\t\t\t6��ӡ�ɼ�\n");
  printf("\t0�˳�\n");
} 

void printstart() 
{ 
printf("-----------------------------------------------------------------------\n"); 
} 
void Wrong() 
{ 
printf("\n��ʾ:�������!\n"); 
} 





//����ɼ�
void printe(Node *p)/* �������������Ӣ�� */ 
{ 
printf("%s\t%s\t%s\t%d\t%d\t%d\t %d\t %d\n",p->data.num,p->data.name,p->data.sex,p->data.egrade,p->data.mgrade,p->data.cgrade,p->data.totle,p->data.ave); 
} 




//��ѯ
Node* Locate(Link l,char findmess[],char nameornum[]) /* �ú������ڶ�λ�����з���Ҫ��Ľӵ㣬�����ظ�ָ�� */ 
{ 
Node *r; 
if(strcmp(nameornum,"num")==0) /* ��ѧ�Ų�ѯ */ 
{ 
r=l->next; 
while(r!=NULL) 
{ 
if(strcmp(r->data.num,findmess)==0) 
return r; 
r=r->next; 
} 
} 
else if(strcmp(nameornum,"name")==0) /* ��������ѯ */ 
{ 
r=l->next; 
while(r!=NULL) 
{ 
if(strcmp(r->data.name,findmess)==0) 
return r; 
r=r->next; 
} 
} 
return 0; 
} 



//����ѧ��
Link Add(Link l) 
{ 
Node *p,*r,*s; 
char num[10]; 
r=l; 
s=l->next; 
while(r->next!=NULL) 
r=r->next; /* ��ָ��������ĩβ */ 
while(1) 
{ 
printf("��������ѧ��(��'0'������һ���˵�:)"); 
scanf("%s",num); 
if(strcmp(num,"0")==0) 
break; 
while(s) 
{ 
if(strcmp(s->data.num,num)==0) 
{ 
printf("=====>��ʾ:ѧ��Ϊ'%s'��ѧ���Ѿ�����,��Ҫ�޸�����ѡ��'4 �޸�'!\n",num); 
printstart(); 
printf(" ѧ��\t ���� �Ա� ���� ��ѧ Ӣ�� ����� ����\n"); 
printe(s); 
printstart(); 
printf("\n"); 
return 0; 
} 
s=s->next; 
} 

p=(Node *)malloc(sizeof(Node)); 

strcpy(p->data.num,num); 
printf("������������:"); 
scanf("%s",p->data.name); 
getchar(); 
printf("���������Ա�:"); 
scanf("%s",p->data.sex); 
getchar(); 
printf("�����������ܳɼ�:"); 
scanf("%d",&p->data.cgrade); 
getchar(); 
printf("����������ѧ�ɼ�:"); 
scanf("%d",&p->data.mgrade); 
getchar(); 
printf("��������Ӣ��ɼ�:"); 
scanf("%d",&p->data.egrade); 
getchar(); 
printf("�������������ɼ�:"); 
scanf("%d",&p->data.totle); 
getchar(); 
printf("����������ӳɼ�:"); 
scanf("%d",&p->data.ave); 
/* ��Ϣ�����Ѿ���� */ 
p->next=NULL; 
r->next=p; 
r=p; 
shoudsave=1; 
} 
return l;
} 



//��ѯѧ�� 

void Qur(Link l) 
{ 
int sel; 
char findmess[20]; 
Node *p; 

if(!l->next) 
{ 
printf("\n=====>��ʾ:û�����Ͽ��Բ�ѯ!\n"); 
return; 

} 
printf("\n=====>1��ѧ�Ų���\n=====>2����������\n"); 
scanf("%d",&sel); 
if(sel==1)/* ѧ�� */ 
{ 
printf("��������Ҫ���ҵ�ѧ��:"); 
scanf("%s",findmess); 
p=Locate(l,findmess,"num"); 
if(p) 
{ 
printf("\t\t\t\t���ҽ��\n"); 
printstart(); 
printf(" ѧ��\t ���� �Ա� ���� ��ѧ Ӣ�� ����� ����\n"); 
printe(p); 
printstart(); 
} 
else 
printf("\n��ʾ:û���ҵ���ѧ��!\n"); 
} 
else if(sel==2) /* ���� */ 
{ 
printf("��������Ҫ���ҵ�����:"); 
scanf("%s",findmess); 
p=Locate(l,findmess,"name"); 
if(p) 
{ 
printf("\t\t\t\t���ҽ��\n"); 
printstart(); 
printf(" ѧ��\t ���� �Ա� ���� ��ѧ Ӣ�� ����� ����\n"); 
printe(p); 
printstart(); 
} 
else 
printf("\n��ʾ:û���ҵ���ѧ��!\n"); 
} 
else 
Wrong(); 

} 


//��ӡ�ɼ�
void dayin(Link l)
{
	node *p;
	p=l->next;
printstart(); 
printf(" ѧ��\t ���� �Ա� ���� ��ѧ Ӣ�� ����� ����\n"); 
while (p!=NULL)
{
	printe(p);
	p=p->next;
}
printstart(); 
}



//ɾ��ѧ��
void Del(Link l) /* ɾ�� */ 
{ 
int sel; 
Node *p,*r; 
char findmess[20]; 
if(!l->next) 
{ 
printf("\n=====>��ʾ:û�����Ͽ���ɾ��!\n"); 
return; 
} 
printf("\n=====>1��ѧ��ɾ��\n=====>2������ɾ��\n"); 
scanf("%d",&sel); 
if(sel==1) 
{ 
printf("��������Ҫɾ����ѧ��:"); 
scanf("%s",findmess); 
p=Locate(l,findmess,"num"); 
if(p) 
{ 
r=l; 
while(r->next!=p) 
r=r->next; 
r->next=p->next; 
free(p); 
printf("\n=====>��ʾ:��ѧ���Ѿ��ɹ�ɾ��!\n"); 
shoudsave=1; 
} 
else 
printf("\n��ʾ:û���ҵ���ѧ��!\n"); 
} 
else if(sel==2) 
{ 
printf("��������Ҫɾ��������:"); 
scanf("%s",findmess); 
p=Locate(l,findmess,"name"); 
if(p) 
{ 
r=l; 
while(r->next!=p) 
r=r->next; 
r->next=p->next; 
free(p); 
printf("\n=====>��ʾ:��ѧ���Ѿ��ɹ�ɾ��!\n"); 
shoudsave=1; 
} 
else 
printf("\n��ʾ:û���ҵ���ѧ��!\n"); 
} 
else 
Wrong(); 
} 



//����
void save(Link L){
	FILE *fp;
	Node *p;
	p=L->next;
	if((fp=fopen("stu.dat","w+"))==NULL)
	{
		printf("cannot open file\n");
	return;
	}
while (p!=NULL)
{
fprintf(fp,"%s\t%s\t%s\t%d\t%d\t%d\t %d\t %d\n",p->data.num,p->data.name,p->data.sex,p->data.egrade,p->data.mgrade,p->data.cgrade,p->data.totle,p->data.ave); 
	p=p->next;
}

	fclose(fp);
}





//�޸�ѧ��
void Modify(Link l) 
{ 
Node *p; 
char findmess[20]; 
if(!l->next) 
{ 
printf("\n=====>��ʾ:û�����Ͽ����޸�!\n"); 
return; 
} 
printf("��������Ҫ�޸ĵ�ѧ��ѧ��:"); 
scanf("%s",findmess); 
p=Locate(l,findmess,"num"); 
if(p) 
{ 
printf("����������ѧ��(ԭ����%s):",p->data.num); 
scanf("%s",p->data.num); 
printf("��������������(ԭ����%s):",p->data.name); 
scanf("%s",p->data.name); 
getchar(); 
printf("�����������Ա�(ԭ����%s):",p->data.sex); 
scanf("%s",p->data.sex); 
printf("���������µ����ܳɼ�(ԭ����%d��):",p->data.cgrade); 
scanf("%d",&p->data.cgrade); 
getchar(); 
printf("���������µ���ѧ�ɼ�(ԭ����%d��):",p->data.mgrade); 
scanf("%d",&p->data.mgrade); 
getchar(); 
printf("���������µ�Ӣ��ɼ�(ԭ����%d��):",p->data.egrade); 
scanf("%d",&p->data.egrade); 
printf("���������µļ�����ɼ�(ԭ����%d��):",p->data.totle); 
scanf("%d",&p->data.mgrade); 
getchar(); 
printf("���������µĵ��ӳɼ�(ԭ����%d��):",p->data.ave); 
scanf("%d",&p->data.mgrade); 
printf("\n=====>��ʾ:�����޸ĳɹ�!\n"); 
shoudsave=1; 
} 
else 
printf("\n��ʾ:û���ҵ���ѧ��!\n"); 

} 

void Disp(Link l) 
{ 
int count=0; 
Node *p; 
p=l->next; 

if(!p) 
{ 
printf("\n=====>��ʾ:û�����Ͽ�����ʾ!\n"); 
return; 
} 
printf("\t\t\t\t��ʾ���\n"); 
printstart(); 
printf(" ѧ��\t ���� �Ա� ���� ��ѧ Ӣ�� ����� ����\n"); 
printf("\n"); 
while(p) 
{ 
printe(p); 
p=p->next; 
} 
printstart(); 
printf("\n"); 
} 








//������
void main()
{
 

Link l;
int sel; 
char ch; 
char jian; 

int count=0; 
Node *p,*r;  
l=(Node*)malloc(sizeof(Node)); 
l->next=NULL; 
r=l; 

while(1) 
{
	menu(); 
printf("����ѡ�����:");
scanf("%d",&sel); 
if(sel==0) 
{  
printf("\n=====>��ʾ:���Ѿ��˳�ϵͳ,�ټ�!\n"); 
break; 
} 
switch(sel) 
{ 
case 1:l=Add(l);dayin(l);break; /* ����ѧ�� */ 
case 2:Del(l);dayin(l);break;/* ɾ��ѧ�� */ 
case 3:Qur(l);break;/* ��ѯѧ�� */ 
case 4:Modify(l);dayin(l);break;/* �޸�ѧ�� */ 
case 5:save(l);break;
case 6:dayin(l);break;
case 9:printf("\t\t\t==========������Ϣ==========\n");break; 
default: Wrong();getchar();break; 
} 
} 
} 