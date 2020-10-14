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
    for(i=0;i<n-1;i++)
    {
        for(k=0;k<n-i-1;k++)
        {
            if(A[k]>A[k+1])
            {
                swap(&A[k],&A[k+1]);
            }
        }
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
