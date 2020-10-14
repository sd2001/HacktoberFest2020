#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct node *start = NULL;
struct node *start2 = NULL;
struct node *newstart = NULL;

struct node *create_ll(struct node *start)  //Function to create a Linked List
{
	int num;
	struct node *new_node , *ptr;
	printf("Enter the values to be inserted into a linked list?\n");	
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = num;
	   	if(start==NULL)
		{
			new_node->next = NULL;
			start = new_node;
		}
		else
		{
			ptr = start;
			while(ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new_node;
			new_node->next = NULL;
		}
		scanf("%d",&num);
	}
	return start;
}

struct node *display(struct node *start)  //Function to display the Linked List
{
	struct node *ptr;
	printf("Linked List:\n");
	ptr=start;
	while(ptr->next!=NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("%d",ptr->data);
	return start;
}

bool empty_list(struct node *start)  //Function to check if a List is empty or not
{
    if(start == NULL)
      return true;
    return false;
}

struct node *insert(struct node *start) //Function to insert an element into a Linked List
{
	int val,num,pos,ch;
	struct node *ptr, *preptr, *new_node, *temp;
	printf("How do you want your element to be inserted?\n");
	printf("1. By specifying the position\n");
	printf("2. By specifying the data after which the element needs to be inserted\n");
	scanf("%d",&ch);
	if(ch==2)
	{
		printf("Enter the value after which the new element needs to be inserted\n");
		scanf("%d",&val);
		printf("Enter the value to be inserted\n");
		scanf("%d",&num);
		new_node = (struct node *)malloc(sizeof(struct node));
	    new_node->data = num;
		ptr=start;
		preptr=ptr;
		if(start->data==val)
		{
			temp = start->next;
			start->next = new_node;
			new_node->next = temp;
		}
		else
		{
		while(preptr->data!=val)
		{
			preptr=ptr;
			ptr = ptr->next;
		}
		preptr->next = new_node;
		new_node->next = ptr; 
	    }
    }
    else if(ch==1)
    {
    	printf("Enter the position of the new element to be inserted\n");
		scanf("%d",&pos);
		printf("Enter the value to be inserted\n");
		scanf("%d",&num);
		new_node = (struct node *)malloc(sizeof(struct node));
	    new_node->data = num;
		ptr=start;
		preptr=ptr;
		int count=1;
		if(pos==1)
		{
			new_node->next = start;
			start = new_node;
		}
		else
		{
			while(count!=pos)
		   {
			preptr=ptr;
			ptr = ptr->next;
			count++;
		   }
		preptr->next = new_node;
		new_node->next = ptr;
		} 	
	}
	return start;
}

struct node *del(struct node *start) //Function to delete an element into a Linked List
{
	int val,pos,ch;
	struct node *ptr, *preptr, *temp;
	printf("How do you want your element to be deleted?\n");
	printf("1. By specifying the position\n");
	printf("2. By specifying the value of the element to be deleted\n");
	scanf("%d",&ch);
	if(ch==2)
	{
		printf("Enter the value of the element to be deleted\n");
		scanf("%d",&val);
		ptr=start;
		preptr=ptr;
		if(start->data==val)
		{
			start = start->next;
			free(ptr);
		}
		else
		{
		while(ptr->data!=val)
		{
			preptr=ptr;
			ptr = ptr->next;
		}
		preptr->next = ptr->next; 
		free(ptr);
	    }
    }
    else if(ch==1)
    {
    	printf("Enter the position of the element to be deleted\n");
		scanf("%d",&pos);
		ptr=start;
		preptr=ptr;
		int count=1;
		if(pos==1)
		{
			start = start->next;
			free(ptr);
		}
		else
		{
			while(count!=pos)
		    {
			preptr=ptr;
			ptr = ptr->next;
			count++;
		    }
		preptr->next = ptr->next; 
		free(ptr);
		} 	
	}
	return start;
}

int main()
{
	int select;
	do
	{
		printf("Main Menu\n");
		printf("\n1. Create a Linked List\n");
		printf("2. Display Linked List\n");
		printf("3. Insert element in the  Linked List\n");
		printf("4. Delete element from the Linked List\n");		
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &select);
		switch(select)
		{
			case 1: start = create_ll(start);
					printf("\nLINKED LIST CREATED\n");
					break;
			case 2: printf("DISPLAYING...");
					start = display(start);
					printf("\n");
					break;
			case 3: start=insert(start);
					printf("DISPLAYING UPDATED LINKED LIST...");
					start=display(start);
					printf("\n");
					break;
			case 4: if(empty_list(start)==true)
					{
						printf("UNDERFLOW...PLEASE CREATE A LINKED LIST\n");
						start = create_ll(start);
					}	
					if(empty_list(start)==false)
					{											
						start=del(start);
						printf("DISPLAYING UPDATED LINKED LIST...");
						start=display(start);
						printf("\n");
			    	}
		}
	}while(select != 5);
	return 0;
}
