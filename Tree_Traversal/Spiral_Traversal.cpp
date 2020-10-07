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

class Stack
{
    int top,size;
    node **a;
    public:
    Stack()
    {
        size=100;
        a=new node*[size];
        top=-1;
    }
    void push(node* x)
    {
        top++;
        a[top]=x;
    }
    node* pop()
    {
        node* temp=a[top];
        top--;
        return temp;
    }
    bool isEmpty()
    {
        if(top==-1)
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

    void preOrder(node *n)
    {
        Stack s;
        while(!s.isEmpty() || n!=NULL)
        {
            if(n!=NULL)
            {
                cout<<n->data<<" ";
                s.push(n);
                n=n->lchild;
            }
            else
            {
                node* b;
                b=s.pop();
                n=b->rchild;
            }
        }
    }

    void Inorder(node *n)
    {
        Stack s;
        while(!s.isEmpty() || n!=NULL)
        {
            if(n!=NULL)
            {
                s.push(n);
                n=n->lchild;
            }
            else
            {
                node* b;
                b=s.pop();
                cout<<b->data<<" ";
                n=b->rchild;
            }
        }
    }

    void Postorder(node *n)
    {
        stack <int> s;
        while(!s.empty() || n!=NULL)
        {
            if(n!=NULL)
            {
                s.push((int)n);
                n=n->lchild;
            }
            else
            {
                int b;
                b=s.top();
                s.pop();
                if(b>0)
                {
                    s.push(-1*b);
                    n=((node*)b)->rchild;
                }
                else
                {
                    cout<<((node*)(-1*b))->data<<" ";
                }

            }
        }
    }

    void spiralTraversal(node *n)
    {
        Stack s1,s2;
        s1.push(n);
        while(!s1.isEmpty() || !s2.isEmpty())
        {
            while(!s1.isEmpty())
            {
                node* t=s1.pop();
                cout<<t->data<<" ";
                if(t->rchild)
                    s2.push(t->rchild);
                if(t->lchild)
                    s2.push(t->lchild);
            }
            while(!s2.isEmpty())
            {
                node* t=s2.pop();
                cout<<t->data<<" ";
                if(t->lchild)
                    s1.push(t->lchild);
                if(t->rchild)
                    s1.push(t->rchild);
            }
        }
    }
};



int main()
{
    Tree t;
    cout<<endl;
    cout<<"PreOrder traversal: ";
    t.preOrder(t.r);
    cout<<endl;
    cout<<"InOrder traversal: ";
    t.Inorder(t.r);
    cout<<endl;
    cout<<"PostOrder traversal: ";
    t.Postorder(t.r);
    cout<<endl;
    cout<<"Spiral traversal: ";
    t.spiralTraversal(t.r);
    cout<<endl;
    return 0;
}