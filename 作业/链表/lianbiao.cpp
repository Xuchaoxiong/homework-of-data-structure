#include"stdio.h"
#include <stdlib.h>
typedef struct List_Node{
	int info;
	struct List_Node *next;
}node; 


//尾插法建立带头结点的单链表
node* Creat_Node()
{
	node *head,*pre,*p;
	int x;
	head=(node*)malloc(sizeof(node));;
	head->next=NULL;
	pre=head;
	printf("输入各结点的值,以0结束:");
	while((scanf("%d",&x))&&x!=0)
	{
		p=(node*)malloc(sizeof(node));
		p->info=x;
		p->next=pre->next;
		pre->next=p;
		pre=pre->next;
	}
	return head;
};



 //链表长度
int Count_Node(node *head)
{
	node *p;
	
	int num=0;
	if (head==NULL)
	{
		return NULL;
	}
	p=head->next;
	while(p!=NULL)
	{
		num++;
		p=p->next;
	}
	return num;
};



//按值查找 
int FindByValue(node *head, int v)
{
	node *p;
	int i=0,num=0;
	if (head == NULL)
	{
		return 0;
	}
	p=head->next;
	while(p!=NULL)
	{
		i++;
		
		if (p->info==v)
		{
			num++;
			printf("位置为%d\n",i);
		}
		p=p->next;	
	}
	printf("找到%d个等于%d的值\n",num,v);
	return num;
};



//插入元素 
void InsertItem(node *head, int loc, int num)
{
	node *p, *pre, *s;
	int i=0;
	if (loc>Count_Node(head)||loc<0)
	{
		printf("插入位置错误\n");
		return;
	}
	if (head == NULL)
	{
		return;
	}
	pre=head;
	p = head->next;
	while(i!=loc)
	{
		i++;
		pre = p;
		p=p->next;
	}
	s=(node*)malloc(sizeof(node));
	s->info=num;
	s->next=p;
	pre->next=s;
};



//删除元素 
int deleteItem(node *head, int loc)
{
	node *p, *pre;
	int i=1, num=0;
	if (loc>Count_Node(head)||loc<=0)
	{
		printf("删除位置错误\n");
		return 0;
	}
	if (head == NULL)
	{
		return 0;
	}
	pre=head;
	p = pre->next;
	while(i!=loc)
	{
		i++;
		pre = p;
		p=p->next;
	}
	num = p->info;
	pre->next = p->next;
	p->next = NULL;
	free(p);
return num;
};


//显示链表
void listprint(node *head)
{node *p;
	p=head->next;
	while(p!=NULL)
	{if (p->next)
		printf(" %d   ",p->info);
	else printf(" %d   \n",p->info);
	p=p->next;
	}
};

void menu()
{
	printf("   1:生成一个链表\n");
	printf("   2:插入数值(插入位置和插入的数)\n");
	printf("   3:删除元素(输入删除元素的位数)\n");
	printf("   4:查找(输入要查找的序号)\n");
};
void main()
{int a[1002];
	int goon=1;
	node *head=NULL;
	int x,y;
	int flag=0;
	int choice;
	menu();
	while(goon)
	{
		printf("请选择：\n");
		scanf("%d",&choice);
switch (choice)
{
case 0:
	menu();
	break;
case 1:
	printf("创建链表\n");
	head=Creat_Node();
	listprint(head);
    menu();
	break;
case 2:
     printf("insert your mumber\n");
     scanf("%d",&x);
	 scanf("%d",&y);
     InsertItem(head,x,y);
	 listprint(head);
	 menu();
     break;
case 3:
    printf("delete your number\n");
	scanf("%d",&x);
	printf("删除的元素为%d",deleteItem(head,x));
	listprint(head);
	menu();
	break;
case 4:
    printf("按序号查找\n请输入要查找的序号\n");
	scanf("%d",&x);
	printf("找到的数目为%d\n",FindByValue(head,x));
    listprint(head);
	menu();
	break;
default:
	break;
}
	}
}
