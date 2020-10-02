//https://www.spoj.com/problems/AGGRCOW/


#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(long long int g[],long long int n,long long int m,long long int c)
{
	long long int p=1,gap=0;
	for(long long int i=0;i<n-1;i++)
	{
		gap = gap + g[i];
		if(gap>=m)
		{
			p++;
			gap=0;
		}
	}
	if(p>=c)
		return true;
	else
		return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,c,i;
		cin>>n>>c;
		long long int a[n],g[n-1],r=0,l,m,ans;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=1;i<n;i++)
		{
			g[i-1]=a[i]-a[i-1];
			r=r+g[i-1];
		}
		l=g[0];
		while(l<=r)
		{
			m=l+(r-l)/2;
			if(isPossible(g,n,m,c))
			{
				ans=m;
				l=m+1;
			}
			else
				r=m-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}