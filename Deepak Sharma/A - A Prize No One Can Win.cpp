#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cheetah ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0)
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define endl ("\n");
 
int main (){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif

    cheetah;
    cout<<fixed;
    cout.precision(10);
    int t=1;
    // cin>>t;
    while(t--){
    	ll int n,x;cin>>n>>x;
    	ll int a[n];
    	ll int count=1;
    	for(ll int i=0;i<n;i++)
    		cin>>a[i];
    	sort(a,a+n);
    	for(ll int i=1;i<n;i++){
    		if((a[i]+a[i-1])>x){
    			break;
    		}
    		count++;
    	}
    	cout<<count<<endl;
    }
    
  return 0;
}
