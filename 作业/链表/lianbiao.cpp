#include"stdio.h"
#include <stdlib.h>
typedef struct List_Node{
	int info;
	struct List_Node *next;
}node; 


//β�巨������ͷ���ĵ�����
node* Creat_Node()
{
	node *head,*pre,*p;
	int x;
	head=(node*)malloc(sizeof(node));;
	head->next=NULL;
	pre=head;
	printf("���������ֵ,��0����:");
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



 //������
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



//��ֵ���� 
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
			printf("λ��Ϊ%d\n",i);
		}
		p=p->next;	
	}
	printf("�ҵ�%d������%d��ֵ\n",num,v);
	return num;
};



//����Ԫ�� 
void InsertItem(node *head, int loc, int num)
{
	node *p, *pre, *s;
	int i=0;
	if (loc>Count_Node(head)||loc<0)
	{
		printf("����λ�ô���\n");
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



//ɾ��Ԫ�� 
int deleteItem(node *head, int loc)
{
	node *p, *pre;
	int i=1, num=0;
	if (loc>Count_Node(head)||loc<=0)
	{
		printf("ɾ��λ�ô���\n");
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


//��ʾ����
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
	printf("   1:����һ������\n");
	printf("   2:������ֵ(����λ�úͲ������)\n");
	printf("   3:ɾ��Ԫ��(����ɾ��Ԫ�ص�λ��)\n");
	printf("   4:����(����Ҫ���ҵ����)\n");
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
		printf("��ѡ��\n");
		scanf("%d",&choice);
switch (choice)
{
case 0:
	menu();
	break;
case 1:
	printf("��������\n");
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
	printf("ɾ����Ԫ��Ϊ%d",deleteItem(head,x));
	listprint(head);
	menu();
	break;
case 4:
    printf("����Ų���\n������Ҫ���ҵ����\n");
	scanf("%d",&x);
	printf("�ҵ�����ĿΪ%d\n",FindByValue(head,x));
    listprint(head);
	menu();
	break;
default:
	break;
}
	}
}
