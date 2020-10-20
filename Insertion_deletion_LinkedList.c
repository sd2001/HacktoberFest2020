#include<stdio.h>
#include<stdlib.h>
void insert_at_beg(void); 
void insert_at_end(void); 
void delete_at_beg(void); 
void delete_at_end(void); 
struct node { 
int data; 
struct node *next; }; 
struct node *head=0,*newnode,*temp; 
void insert_at_beg() 
{ 
    newnode=(struct node*)malloc(sizeof(struct node)); 
    printf("enter the data you want to insert at the beg"); 
    scanf("%d",&newnode->data); 
    newnode->next=head; 
    head=newnode; 
} 
void insert_at_end() 
{
    newnode=(struct node*)malloc(sizeof(struct node)); 
    printf("enter the data you want insert at the end"); 
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!=0) 
    { 
       temp=temp->next; 
    } 
    temp->next=newnode;
} 
void delete_at_beg() 
{ 
    temp=head; head=head->next; 
    free(temp);
} 
void delete_at_end() 
{
    struct node *prev; 
    temp=head; 
    while(temp->next!=0) 
    {
        prev=temp; 
        temp=temp->next; 
    }
    if(temp==head)
    { 
        head=0; 
        free(temp); 
    } 
    else 
    { 
        prev->next=0; 
        free(temp); 
    } 
}
int main() 
{ 
    insert_at_beg();  
    insert_at_end(); 
    insert_at_end(); 
    insert_at_end(); 
    delete_at_beg(); 
    delete_at_end(); 
    temp=head; 
    while(temp!=0) 
    { 
        printf("%d",temp->data); 
        temp=temp->next;
    } 
}
