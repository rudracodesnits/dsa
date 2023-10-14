#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};
// *first = NULL;
// *second = NULL;
// *third = NULL;
struct node* first=NULL;
void create (int A[],int n)
{
  int i;
  struct node *t,*last;
  first=(struct node*)malloc(sizeof(struct node));
  first->data=A[0];
  first->next=NULL;
  last=first;
  for(i=1;i<n;i++)
  {
    t=(struct node*)malloc(sizeof(struct node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
}

int isloop(struct node* f)
{
  struct node*p,*q;
  p=q=f;
  do
  {
    p=p->next;
    q=q->next;
    q=q?q->next:q;
  } while (p&&q && p!=q);
    if(p==q)
    return 1;
    else 
    return 0;
}

int main()
{
  struct node *t1,*t2;
  int A[]={10,20,30,40,50};
  create(A,5);
  t1=first->next->next;
  t2=first->next->next->next->next;
  t2->next=t1;
  printf("%d\n", isloop(first));
  return 0;
}