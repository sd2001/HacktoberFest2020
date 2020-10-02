#include <iostream>
#include <stack>

using namespace std;

struct node
{
    node* lchild;
    int data;
    node* rchild;
};

class queue
{
    int size,front,rear;
    node **a;
    public:
  queue()
  {
      size = 100;
      front = rear = -1;
      a = new node*[size];
  }
  void enqueue(node *x)
  {
       rear++;
      a[rear]=x;
  }
  node* dequeue()
  {
      front++;
      return a[front];
  }
  bool isEmpty()
  {
      if(front!=-1 && front==rear)
        return true;
      else
        return false;
  }
};

class Tree
{
    public:
    node* r;
    Tree()
    {
        queue q;
        int d;
        cout<<"Enter root value "<<endl;
        cin>>d;
        r = new node();
        r->data=d;
        r->lchild=NULL;
        r->rchild=NULL;
        q.enqueue(r);
        while(!q.isEmpty())
        {
            node* x;
            x=q.dequeue();
            cout<<"Enter left child of "<<x->data<<" ";
            cin>>d;
            if(d!=-1)
            {
                node* n = new node();
                n->data=d;
                n->lchild=NULL;
                n->rchild=NULL;
                q.enqueue(n);
                x->lchild=n;
            }
            cout<<"Enter right child of "<<x->data<<" ";
            cin>>d;
            if(d!=-1)
            {
                node* n = new node();
                n->data=d;
                n->lchild=NULL;
                n->rchild=NULL;
                q.enqueue(n);
                x->rchild=n;
            }
        }
    }

    void Left_Boundary_Traversal(node *n)
    {
        if(n==NULL)
            return;
        if(n->lchild)
        {
            cout<<n->data<<" ";
            Left_Boundary_Traversal(n->lchild);
        }
        else if(n->rchild)
        {
            cout<<n->data<<" ";
            Left_Boundary_Traversal(n->rchild);
        }
    }
    void Right_Boundary_Traversal(node *n)
    {
        if(n==NULL)
            return;
        if(n->rchild)
        {
            Right_Boundary_Traversal(n->rchild);
            cout<<n->data<<" ";
        }
        else if(n->lchild)
        {
            Right_Boundary_Traversal(n->lchild);
            cout<<n->data<<" ";
        }
    }
    void leaf_nodes_traversal(node *n)
    {
        if(n->lchild)
            leaf_nodes_traversal(n->lchild);
        if(n->rchild)
            leaf_nodes_traversal(n->rchild);
        if(!n->lchild && !n->rchild)
            cout<<n->data<<" ";
    }
    void boundary_traversal(node *n)
    {
        Left_Boundary_Traversal(n);
        leaf_nodes_traversal(n);
        Right_Boundary_Traversal(n->rchild);
    }
};

int main()
{
    Tree t;
    cout<<endl<<"Boundary Traversal: "
    t.boundary_traversal(t.r);
    return 0;
}