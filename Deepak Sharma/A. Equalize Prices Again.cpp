

//id:- deepak290701

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main() {
	// your code goes here
	fastio;
	ll int t;
	cin>>t;
	while(t--){
		ll int n;
		ll int sum=0;
		cin>>n;
		ll int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		ll int a1=int(sum/n);
		if(n*a1<sum)
			a1++;

		cout<<a1<<"\n";
	}
	return 0;
}
