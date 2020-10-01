#include<stdio.h>
void main()
{
    int n;
    scanf("%d",&n);
    int i;
    int A[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int k;
    int minimum;
    for(i=0;i<n-1;i++)
    {
        minimum=i;
        for(k=i+1;k<n;k++)
        {
            if(A[k]<A[minimum])
                minimum=k;
        }
        if(minimum!=i)
            swap(&A[i],&A[minimum]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
