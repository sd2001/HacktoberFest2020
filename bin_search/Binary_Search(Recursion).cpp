#include<iostream.h>
#include<conio.h>
#include<process.h>
int bsearch(int A[50],int lb,int ub,int ele,int n)
{static  int cnt=0;
 int mid=(lb+ub)/2;
cnt++;
  if(cnt==n&&A[mid]!=ele)
   {cout<<ele<<" not found in the array.";
     getch();
     exit(0);
     }
  if(A[mid]==ele)
   return (mid);
  if(A[mid]>ele)
   return bsearch(A,lb,mid-1,ele,n);
  if(A[mid]<ele)
   return bsearch(A,mid+1,ub,ele,n);
}
void main()
{ clrscr();
  int arr[50],n,i,j,temp,ele;
  cout<<"Enter the size of array : ";cin>>n;
  cout<<"Enter elements into the array :\n ";
  for(i=0;i<n;++i)
   cin>>arr[i];

  for(i=0;i<n;++i)
  for(j=i+1;j<n;++j)
     if(arr[i]>arr[j])
       { temp=arr[i];
	 arr[i]=arr[j];
	 arr[j]=temp;
	}

  cout<<"Sorted Array : ";
   for(i=0;i<n;++i)
     cout<<arr[i]<<" ";

  cout<<"\nEnter element to search : ";cin>>ele;
  cout<<ele<<" found at position "<<bsearch(arr,0,n-1,ele,n)+1;
   getch();
}
