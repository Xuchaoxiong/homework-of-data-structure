#include <stdio.h> 
#include <malloc.h> 
struct poly //���ýṹ�� 
{ 
 int xi; 
 int zhi; 
 struct poly *next; 
}; 
struct poly *jianli(void) //�������� 
{ 
 struct poly *p1,*head1,*p2; 
 head1=(struct poly*)malloc(sizeof(poly)); 
 p1=(struct poly*)malloc(sizeof(poly)); 
 scanf("%d %d",&p1->xi,&p1->zhi); 
 head1->next=p1; 
 p1->next=NULL; 
 while(1) 
 { 
  p2=(struct poly*)malloc(sizeof(poly)); 
  scanf("%d %d",&p2->xi,&p2->zhi); 
  if(p2->xi==0) if(p2->zhi==0) {free(p2);break;} 
  p1->next=p2; 
  p2->next=NULL; 
  p1=p2; 
 } 
 return(head1); 
} 
struct poly *jisuan(struct poly *head1,struct poly *head2) //����ʽ����� 
{ 
 struct poly *p1,*p2,*r1,*r2; 
 r1=head1; 
 p1=head1->next; 
 r2=p2=head2->next; 
 while(p1&&p2) 
 { 
  if(p1->zhi==p2->zhi) 
  { 
   p1->xi=(p1->xi)+(p2->xi); 
   p2=p2->next; 
   free(r2); 
   r2=p2; 
   r1=p1; 
   p1=p1->next; 
  } 
  else if(p1->zhi>p2->zhi) 
  {
   r2->next=p1; 
   r1->next=r2; 
   p2=p2->next; 
   r2=p2; 
  } 
  else 
   if(p1->zhi<p2->zhi) 
   { 
    r1=p1; p1=p1->next; 
   } 
 } 
 if(p1) free(head2); 
 else { 
  r1->next=p2; 
  free(head2); 
 } 
 return(head1); 
} 
void print(poly *head) 
{ 
 struct poly *p; 
 p=head->next; 
 while(p) 
 { 
  printf("%d %d\t",p->xi,p->zhi); 
  p=p->next; 
 } 
} 
void main() 
{ 
 struct poly *head1,*head2,*p; 
 while (1)
 {
 printf("���������ʽ��ÿһ���ϵ����ָ������0 0Ϊ������־:\n"); 
 head1=jianli(); 
 printf("\n��������һ������ʽ��ÿһ���ϵ����ָ������0 0Ϊ������־:\n"); 
 head2=jianli(); 
 p=jisuan(head1,head2); 
 printf("\n�ϲ���:\n"); 
 print(p); 
}
}