//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0


#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(long long int a[], long long int n, long long int m, long long int mid)
{
    long long int s=0,p=1;
    for(int i=0;i<n;i++)
    {
        s=s+a[i];
        if(s>mid)
        {
            s=a[i];
            p++;
            if(p>m || s>mid)
                return false;
        }
    }
    return true;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,m,s=0;
	    cin>>n;
	    long long int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        s=s+a[i];
	    }
	    cin>>m;
	    long long int l=a[n-1],r=s,mid,ans;
	    while(l<=r)
	    {
	        mid = l + (r-l)/2;
	        if(isPossible(a,n,m,mid))
	        {
	            ans=mid;
	            r=mid-1;
	        }
	        else
	        {
	            l=mid+1;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}