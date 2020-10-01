#include<stdio.h>
void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int key;
    scanf("%d",&key);
    int b[key];
    for(int i=0;i<key;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<key;i++)
    {
        int g=binarysearch(a,0,n,b[i]);
        printf("%d ",g);
    }
}
int binarysearch(int a[],int low,int high,int key)
{
    while(low<=high)
    {
        int mid;
        mid=(low+((high-low)/2));
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            high=mid-1;
        else if(a[mid]<key)
            low=mid+1;
    }
    return -1;
}
