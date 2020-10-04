#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
  struct node *pre;
  int info;
  struct node *next;
} *start;
void create(int data)
{
  struct node *temp,*q;
  temp=malloc(sizeof(struct node));
  temp->info=data;
  if(start==NULL)
  {
    temp->pre=NULL;
    temp->next=NULL;
    start=temp;
  }
  else
  {
    q=start;
    while(q->next!=NULL)
      q=q->next;
    q->next=temp;
    temp->pre=q;
    temp->next=NULL;
  }
}
void search(int data)
{
  int i=0;
  struct node *q;
  q=start;
  while(q!=NULL)
  {
    if(q->info==data)
     {
      printf("The element is found at %d\n",i+1);
      return;
     }
    q=q->next;
    i++;
  }
printf("element not found\n");
}
void display()
{
  struct node *q;
  if(start==NULL)
    printf("The list is empty\n");
  else
  {
    q=start;
    printf("The List is:\n");
    while(q!=NULL)
     {
       printf("%d\t",q->info);
       q=q->next;
     }
  }
  printf("\n");
}
void delete_node(int data)
{
  struct node *q,*temp;
  q=start;
  if(start->info==data)
  {
   temp=start;
   start=q->next;
   start->pre=NULL;
   free(temp);
   return;
  }
  else
  {
   while(q->next->next!=NULL)
   {
    if(q->next->info==data)
    {
     temp=q->next;
     q->next=temp->next;
     temp->next->pre=q;
     free(temp);
     return;
    }
  q=q->next;
   }
  if(q->next->info==data)
  {
   temp=q->next;
   q->next=NULL;
   free(temp);
  }
  }
}
void insert(int data,int pos)
{
  struct node *q,*temp;
  int i;
  q=start;
  for(i=0;i<pos-2;i++)
  {
    q=q->next;
  }
    if(q==NULL)
    {
      printf("Invalid position");
      return;
    }
    else
    {
    temp=malloc(sizeof(struct node));
    temp->info=data;
    q->next->pre=temp;
    temp->next=q->next;
    q->next=temp;
    temp->pre=q;
    }
}
void main()
{
  int c,n,i,e,d,p,a,r;
  printf("Doubly Linked List\n");
  printf("1.Create the list\n");
  printf("2.Insert node at a position\n");
  printf("3.Delete node\n");
  printf("4.Search node\n");
   start=NULL;
  while(1)
  {
    printf("Enter choice:\n");
    scanf("%d",&c);
    switch(c)
    {
      case 1: printf("Enter the number of elements:");
              scanf("%d",&n);
              for(i=0;i<n;i++)
                {
                  printf("Element:");
                  scanf("%d",&e);
                  create(e);
                }
              display();
              break;
      case 2:printf("Enter the data to be inserted:");
             scanf("%d",&d);
             printf("Enter the position:");
             scanf("%d",&p);
             insert(d,p);
             display();
             break;
      case 3:printf("Enter the element to be deleted:");
             scanf("%d",&r);
             delete_node(r);
             display();
             break;
      case 4:printf("Enter the data to be searched:");
             scanf("%d",&a);
             search(a);
             break;
    }
  }

}
