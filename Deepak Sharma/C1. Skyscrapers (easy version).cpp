	
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define cheetah ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl ("\n");
typedef tree<ll int ,null_type,less<ll int> ,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//  *(set_name.find_by_order(k))    set_name.order_of_key(k)
 
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
    	ll int n;cin>>n;
    	ll int a[n];
    	for(int i=0;i<n;i++){
    		cin>>a[i];
    	}
    	vector<int> v(n);
    	ll int sum = 0;
    	for(int i=0;i<n;i++){
    		ll int sum1 = a[i];
    		vector<int> v1(n);
    		v1[i]=a[i];
    		int temp = a[i];
    		for(int left = i-1;left>=0;left--){
    			if(a[left]>=temp){
    				v1[left]=temp;
    			}
    			else{
    				v1[left]=a[left];
    				temp = a[left];
    			}
    			sum1+=v1[left];
    		}
    		temp = a[i];
    		for(int right=i+1;right<n;right++){
    			if(a[right]>=temp){
    				v1[right]=temp;
    			}
    			else{
    				v1[right]=a[right];
    				temp=a[right];
    			}
    			sum1+=v1[right];
    		}
    		if(sum1>sum){
    			v=v1;
    			sum=sum1;
    		}
    	}
    	for(auto it:v)
    		cout<<it<<" ";
    }
    
  return 0;
}



