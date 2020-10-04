#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *ROOT=NULL;
int min;
struct node *build_tree(struct node *t,int data)
{
	if(t!=NULL)
	{
		if(data< t->data)
			t->left=build_tree(t->left,data);
		if(data> t->data)
			t->right=build_tree(t->right,data);
	}
	else
	{
		t=malloc(sizeof(struct node));
		t->data=data;
		t->left=NULL;
		t->right=NULL;
	}
	return t;
}
struct node *deleted(int x,struct node *root)
{
	if(root!=NULL)
	{
		if(x< root->data)
			root->left=deleted(x,root->left);
		else if(x>root->data)
			root->right=deleted(x,root->right);
		else
		{
			struct node *t=NULL;
			if(root->left==NULL && root->right==NULL)
			{
				free(root);
				root=NULL;
			}
			else if(root->left==NULL)
			{
				t=root->right;
				free(root);
				root=t;
			}
			else if(root->right==NULL)
			{
				t=root->left;
				free(root);
				root=t;
			}
			else
			{
				t=root->right;
				while(t->left!=NULL)
					t=t->left;
				root->data=t->data;
				root->right=deleted(t->data,root->right);
			}
		}
	}
	return root;
}
void inorder(struct node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d  ",t->data);
		inorder(t->right);
	}
}
void main()
{
	int data,n,i,choice,x;
	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Exit\n");
		printf("Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Enter the number of nodes: ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				printf("Enter the element at [%d]: ",i);
				scanf("%d",&data);
				ROOT=build_tree(ROOT,data);
			}
			printf("\nINORDER   : ");
			inorder(ROOT);
			break;
		case 2:
			printf("Enter the element to be deleted: ");
			scanf("%d",&x);
			ROOT=deleted(x,ROOT);
			printf("\nINORDER   : ");
			inorder(ROOT);
			break;
		case 3:
			return;
		}
	}
}
