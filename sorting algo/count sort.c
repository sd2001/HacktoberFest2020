#include<stdio.h>
void main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    countsort(a,n,k);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
void countsort(int a[],int n,int k)
{
    int b[n];
    int count[k+1];
    for(int i=0;i<k+1;i++)
        count[i]=0;
    for(int i=0;i<n;i++)
        count[a[i]]++;
    for(int i=1;i<=k;i++)
        count[i]=count[i-1]+count[i];
    for(int i=n-1;i>=0;i--)
        b[--count[a[i]]]=a[i];
    for(int i=0;i<n;i++)
        a[i]=b[i];
}
