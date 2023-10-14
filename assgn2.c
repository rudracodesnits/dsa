#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};
//*first=NULL;
struct node* first=NULL;
void create (int A[], int n)
{
  struct node *t, *last;
  first=(struct node*)malloc(sizeof(struct node));
  first->data=A[0];
  first->next=0;
  last=first;
  for(int i=1;i<n;i++)
  {
    t=(struct node*)malloc(sizeof(struct node));
    t->data=A[i];
    t->next=0;
    last->next=t;
    last=t;
  }
}

void reverse(struct node*p)
{
  struct node*q=NULL;
  struct node*r=NULL;
  while(p!=0){
    r=q;
    q=p;
    p=p->next;
    q->next=r;
  }
  first=q;
}

void RecursiveRev(struct node*p,struct node*q)
{ 
  if(p)
  {
    RecursiveRev(p->next,p);
    p->next=q;
  }
  else first=q;
}

void display(struct node* p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int main(){
  int A[]={10,20,30,40,50};
  create(A,5);
  //reverse(first);
  RecursiveRev(first,NULL);
  display(first);

  return 0;
}