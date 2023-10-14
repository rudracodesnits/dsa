#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
} *first=NULL;

void create(int A[],int n)
{
  struct node *t,*last;
  first=(struct node*)malloc(sizeof(struct node));
  first->data=A[0];
  first->next=0;
  last=first;
  for(int i=1;i<n;i++){
    t=(struct node*)malloc(sizeof(struct node));
    t->data=A[i];
    t->next=0;
    last->next=t;
    last=t;
  }
}
void printLoop(struct node *p)
{
  while(p!=NULL){
    printf("%d ",p->data);
    p=p->next;
 }
  printf("\n");
}
void printRec(struct node *p)
{
  if(p==NULL){
    return;
  }
  else {
    printf("%d",p->data);
    printRec(p->next);
  }
}
int main(){
  int A[]={10,20,30,40,50};
  create(A,5);
  printLoop(first);
  printRec(first);
  return 0;
}