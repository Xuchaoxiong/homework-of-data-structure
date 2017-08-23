#include "stdio.h" 
#include "stdlib.h" 
#include "string.h" 
int shoudsave=0; /* */ 
struct student 
{ 
char num[10];/* 学号 */ 
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
printf("\t1登记学生资料\t\t\t\t\t2删除学生资料\n"); 
printf("\t3查询学生资料\t\t\t\t\t4修改学生资料\n"); 
printf("\t5保存学生资料\t\t\t\t\t6打印成绩\n");
  printf("\t0退出\n");
} 

void printstart() 
{ 
printf("-----------------------------------------------------------------------\n"); 
} 
void Wrong() 
{ 
printf("\n提示:输入错误!\n"); 
} 





//输出成绩
void printe(Node *p)/* 本函数用于输出英文 */ 
{ 
printf("%s\t%s\t%s\t%d\t%d\t%d\t %d\t %d\n",p->data.num,p->data.name,p->data.sex,p->data.egrade,p->data.mgrade,p->data.cgrade,p->data.totle,p->data.ave); 
} 




//查询
Node* Locate(Link l,char findmess[],char nameornum[]) /* 该函数用于定位连表中符合要求的接点，并返回该指针 */ 
{ 
Node *r; 
if(strcmp(nameornum,"num")==0) /* 按学号查询 */ 
{ 
r=l->next; 
while(r!=NULL) 
{ 
if(strcmp(r->data.num,findmess)==0) 
return r; 
r=r->next; 
} 
} 
else if(strcmp(nameornum,"name")==0) /* 按姓名查询 */ 
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



//增加学生
Link Add(Link l) 
{ 
Node *p,*r,*s; 
char num[10]; 
r=l; 
s=l->next; 
while(r->next!=NULL) 
r=r->next; /* 将指针置于最末尾 */ 
while(1) 
{ 
printf("请你输入学号(以'0'返回上一级菜单:)"); 
scanf("%s",num); 
if(strcmp(num,"0")==0) 
break; 
while(s) 
{ 
if(strcmp(s->data.num,num)==0) 
{ 
printf("=====>提示:学号为'%s'的学生已经存在,若要修改请你选择'4 修改'!\n",num); 
printstart(); 
printf(" 学号\t 姓名 性别 马哲 数学 英语 计算机 电子\n"); 
printe(s); 
printstart(); 
printf("\n"); 
return 0; 
} 
s=s->next; 
} 

p=(Node *)malloc(sizeof(Node)); 

strcpy(p->data.num,num); 
printf("请你输入姓名:"); 
scanf("%s",p->data.name); 
getchar(); 
printf("请你输入性别:"); 
scanf("%s",p->data.sex); 
getchar(); 
printf("请你输入马哲成绩:"); 
scanf("%d",&p->data.cgrade); 
getchar(); 
printf("请你输入数学成绩:"); 
scanf("%d",&p->data.mgrade); 
getchar(); 
printf("请你输入英语成绩:"); 
scanf("%d",&p->data.egrade); 
getchar(); 
printf("请你输入计算机成绩:"); 
scanf("%d",&p->data.totle); 
getchar(); 
printf("请你输入电子成绩:"); 
scanf("%d",&p->data.ave); 
/* 信息输入已经完成 */ 
p->next=NULL; 
r->next=p; 
r=p; 
shoudsave=1; 
} 
return l;
} 



//查询学生 

void Qur(Link l) 
{ 
int sel; 
char findmess[20]; 
Node *p; 

if(!l->next) 
{ 
printf("\n=====>提示:没有资料可以查询!\n"); 
return; 

} 
printf("\n=====>1按学号查找\n=====>2按姓名查找\n"); 
scanf("%d",&sel); 
if(sel==1)/* 学号 */ 
{ 
printf("请你输入要查找的学号:"); 
scanf("%s",findmess); 
p=Locate(l,findmess,"num"); 
if(p) 
{ 
printf("\t\t\t\t查找结果\n"); 
printstart(); 
printf(" 学号\t 姓名 性别 马哲 数学 英语 计算机 电子\n"); 
printe(p); 
printstart(); 
} 
else 
printf("\n提示:没有找到该学生!\n"); 
} 
else if(sel==2) /* 姓名 */ 
{ 
printf("请你输入要查找的姓名:"); 
scanf("%s",findmess); 
p=Locate(l,findmess,"name"); 
if(p) 
{ 
printf("\t\t\t\t查找结果\n"); 
printstart(); 
printf(" 学号\t 姓名 性别 马哲 数学 英语 计算机 电子\n"); 
printe(p); 
printstart(); 
} 
else 
printf("\n提示:没有找到该学生!\n"); 
} 
else 
Wrong(); 

} 


//打印成绩
void dayin(Link l)
{
	node *p;
	p=l->next;
printstart(); 
printf(" 学号\t 姓名 性别 马哲 数学 英语 计算机 电子\n"); 
while (p!=NULL)
{
	printe(p);
	p=p->next;
}
printstart(); 
}



//删除学生
void Del(Link l) /* 删除 */ 
{ 
int sel; 
Node *p,*r; 
char findmess[20]; 
if(!l->next) 
{ 
printf("\n=====>提示:没有资料可以删除!\n"); 
return; 
} 
printf("\n=====>1按学号删除\n=====>2按姓名删除\n"); 
scanf("%d",&sel); 
if(sel==1) 
{ 
printf("请你输入要删除的学号:"); 
scanf("%s",findmess); 
p=Locate(l,findmess,"num"); 
if(p) 
{ 
r=l; 
while(r->next!=p) 
r=r->next; 
r->next=p->next; 
free(p); 
printf("\n=====>提示:该学生已经成功删除!\n"); 
shoudsave=1; 
} 
else 
printf("\n提示:没有找到该学生!\n"); 
} 
else if(sel==2) 
{ 
printf("请你输入要删除的姓名:"); 
scanf("%s",findmess); 
p=Locate(l,findmess,"name"); 
if(p) 
{ 
r=l; 
while(r->next!=p) 
r=r->next; 
r->next=p->next; 
free(p); 
printf("\n=====>提示:该学生已经成功删除!\n"); 
shoudsave=1; 
} 
else 
printf("\n提示:没有找到该学生!\n"); 
} 
else 
Wrong(); 
} 



//保存
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





//修改学生
void Modify(Link l) 
{ 
Node *p; 
char findmess[20]; 
if(!l->next) 
{ 
printf("\n=====>提示:没有资料可以修改!\n"); 
return; 
} 
printf("请你输入要修改的学生学号:"); 
scanf("%s",findmess); 
p=Locate(l,findmess,"num"); 
if(p) 
{ 
printf("请你输入新学号(原来是%s):",p->data.num); 
scanf("%s",p->data.num); 
printf("请你输入新姓名(原来是%s):",p->data.name); 
scanf("%s",p->data.name); 
getchar(); 
printf("请你输入新性别(原来是%s):",p->data.sex); 
scanf("%s",p->data.sex); 
printf("请你输入新的马哲成绩(原来是%d分):",p->data.cgrade); 
scanf("%d",&p->data.cgrade); 
getchar(); 
printf("请你输入新的数学成绩(原来是%d分):",p->data.mgrade); 
scanf("%d",&p->data.mgrade); 
getchar(); 
printf("请你输入新的英语成绩(原来是%d分):",p->data.egrade); 
scanf("%d",&p->data.egrade); 
printf("请你输入新的计算机成绩(原来是%d分):",p->data.totle); 
scanf("%d",&p->data.mgrade); 
getchar(); 
printf("请你输入新的电子成绩(原来是%d分):",p->data.ave); 
scanf("%d",&p->data.mgrade); 
printf("\n=====>提示:资料修改成功!\n"); 
shoudsave=1; 
} 
else 
printf("\n提示:没有找到该学生!\n"); 

} 

void Disp(Link l) 
{ 
int count=0; 
Node *p; 
p=l->next; 

if(!p) 
{ 
printf("\n=====>提示:没有资料可以显示!\n"); 
return; 
} 
printf("\t\t\t\t显示结果\n"); 
printstart(); 
printf(" 学号\t 姓名 性别 马哲 数学 英语 计算机 电子\n"); 
printf("\n"); 
while(p) 
{ 
printe(p); 
p=p->next; 
} 
printstart(); 
printf("\n"); 
} 








//主函数
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
printf("请你选择操作:");
scanf("%d",&sel); 
if(sel==0) 
{  
printf("\n=====>提示:你已经退出系统,再见!\n"); 
break; 
} 
switch(sel) 
{ 
case 1:l=Add(l);dayin(l);break; /* 增加学生 */ 
case 2:Del(l);dayin(l);break;/* 删除学生 */ 
case 3:Qur(l);break;/* 查询学生 */ 
case 4:Modify(l);dayin(l);break;/* 修改学生 */ 
case 5:save(l);break;
case 6:dayin(l);break;
case 9:printf("\t\t\t==========帮助信息==========\n");break; 
default: Wrong();getchar();break; 
} 
} 
} 