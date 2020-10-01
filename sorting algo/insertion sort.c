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
    int k,temp;
    for(i=1;i<n;i++)
    {
        k=i-1;
        temp=A[i];
        while(k>=0 && temp<A[k])
        {
            A[k+1]=A[k];
            k--;
        }
        A[k+1]=temp;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}
