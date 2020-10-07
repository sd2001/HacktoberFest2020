	
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
    int t;
    cin>>t;
    while(t--){
    	int n;cin>>n;
    	int count = 0;
    	vector<int> v;
    	int no = 1;
    	while(n>0){
    		int temp = n%10;
    		if(n%10>0){
    			v.pb(temp*no);
    		}
    		n/=10;
    		no*=10;
    		count++;
    	}
    	cout<<v.size()<<endl;
    	reverse(all(v));
    	for(auto it:v)
    		cout<<it<<" ";
    	cout<<endl;
    }
    
  return 0;
}



