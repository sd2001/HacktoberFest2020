#include <iostream>

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

    
    void Postorder(node *n)
    {
        if(n!=NULL)
        {
            Postorder(n->lchild);
            Postorder(n->rchild);
            cout<<n->data<<" ";
        }
    }
};

int main()
{
    Tree t;
    cout<<"PostOrder traversal: ";
    t.Postorder(t.r);
    cout<<endl;
    return 0;
}