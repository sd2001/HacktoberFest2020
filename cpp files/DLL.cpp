#include <iostream>
using namespace std;

struct node
{
	node* prev;
	int num;
	node* next;
};
class DLL
{
public:
	node *head;
	DLL()
	{ head=NULL; }
	void insertfirst();
	void insertlast();
	void deletefirst();
	void deletelast();
	void display();	
};

void DLL::insertfirst()
{
	node *ptr;
	ptr=new node;
	cout<<"Enter number\n";
	cin>>ptr->num;
	if(head==NULL)
	{ head=ptr; }
	else
	{
		ptr->next=head;
		ptr->prev=NULL;
		head=ptr;
	}
}

void DLL::insertlast()
{
	node *ptr;
	ptr=new node;
	cout<<"Enter number\n";
	cin>>ptr->num;
	if(head==NULL)
	{ head=ptr; }
	else
	{
		node *temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ptr;
	
		ptr->next=head;
		head=ptr;
	}
}

void DLL::deletefirst()
{
	if(head==NULL)
	{ return; }
	else
	{
		node *t=head;
		head=head->next;
		t->next=NULL;
		head->prev=NULL;
		delete t;
		t=NULL;
	}
}

void DLL::deletelast()
{
	if(head==NULL)
	{ return; }
	else
	{
		node *t=head;
		node *p=NULL;
		while(t->next)
		{
			p=t;
			t=t->next;
		}
		p->next=NULL;
		t->prev=NULL;
		delete t;
		t=NULL;
	}
}

void DLL::display()
{
	cout<<endl;
	if(!head)
	{
		cout<<"Empty list\n";
		return;
	}
	else
	{
		int count=0;
		node *p=head;
		while(p!=NULL)
		{
			cout<<p->num<<endl;
			p=p->next;
			count++;
		}
		cout<<endl<<"Total members : "<<count;
	}
	cout<<endl;
}

int main()
{
	DLL l1,l2;
	l1.insertfirst();
	l1.insertlast();
	l1.display();
	l1.deletefirst();
	l1.deletelast();
	
	return 0;
}
