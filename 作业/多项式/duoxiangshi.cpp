#include"stdio.h"
#include <stdlib.h>
typedef struct LNode
{
	int coef;
	int expn;
	struct LNode *next;
}LNode;







//β�巨������ͷ���ĵ�����
LNode* Creat_LNode()
{
	LNode *head,*pre,*p;
	int x;
	int y;
	head=(LNode*)malloc(sizeof(LNode));;
	head->next=NULL;
	pre=head;
	printf("���������ֵ,��0����:");
	while((scanf("%d%d",&y,&x))&&x!=0)
	{
		p=(LNode*)malloc(sizeof(LNode));
		p->expn=x;
		p->coef=y;
		p->next=pre->next;
		pre->next=p;
		pre=pre->next;
	}
	return head;
};







//��ӡ����ʽ
void listprint(LNode *head)
{
	if (!head){
		printf("NULL\n");
		return ;
	}
	LNode *p=head->next;
	while(p!=NULL)
	{
		if (p->next)
		printf(" %dX^%d+",p->coef,p->expn);
		else printf("%dX^%d\n",p->coef,p->expn);
		p=p->next;
	};
};







//������
int length(LNode *head)
{int n=0;
	LNode *p;
	p=head;
while (p!=NULL)
{
	n++;
	p=p->next;
}
return n;
};








//����ʽ���
LNode* addlist(LNode *head1,LNode *head2)
{
LNode *p,*q,*s,*r,*head3;
 int x;
 p=head1->next;
 q=head2->next;
head3=(LNode*)malloc(sizeof(LNode));
 r=head3;
 while(p!=NULL&&q!=NULL)
 {
  if(p->expn==q->expn)
  {
   x=p->coef+q->coef;
   if(x!=0)
   {
    s=(LNode*)malloc(sizeof(LNode));
    s->coef=x;
    s->expn=p->expn;
    r->next=s;
    r=s;
   }
   p=p->next;
   q=q->next;
  }
  else if(p->expn>q->expn)
   {
    s=(LNode*)malloc(sizeof(LNode));
    s->expn=q->expn;
    s->coef=q->coef;
    r->next=s;
    r=s;
    q=q->next;
   }
  else
  {
   s=(LNode*)malloc(sizeof(LNode));
   s->expn=p->expn;
   s->coef=p->coef;
   r->next=s;
   r=s;
   p=p->next;
  }
    }
  while(p!=NULL)
  {
   s=(LNode*)malloc(sizeof(LNode));
   s->expn=p->expn;
   s->coef=p->coef;
   r->next=s;
   r=s;
   p=p->next;
  }
  while(q!=NULL)
  {
   s=(LNode*)malloc(sizeof(LNode));
   s->expn=q->expn;
   s->coef=q->coef;
   r->next=s;
   r=s;
   q=q->next;
  }
  r->next=NULL;
  return head3;
              
}





void main()
{while (true){
LNode *head1=NULL;
LNode *head2=NULL;
LNode *head=NULL;
printf("�������һ������ʽ\n");
head1=Creat_LNode();
listprint(head1);
printf("������ڶ�������ʽ\n");
head2=Creat_LNode();
listprint(head2);
printf("����ʽ��ӵ�\n");
head=addlist(head1,head2);
listprint(head);
}
}





	






