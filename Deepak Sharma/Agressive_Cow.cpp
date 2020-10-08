	
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define cheetah ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0)
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define endl ("\n");
typedef tree<ll int ,null_type,less<ll int> ,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//  *(set_name.find_by_order(k))    set_name.order_of_key(k)



bool check(int mid , int c, vector<int> v ){
	int prev = v[0];
	int count = 1;
	for(int i = 1;i<v.size();i++){
		if(v[i]-prev>=mid){
			count++;
			prev = v[i];
			if(count>=c)
				return true;
		}
	}
	return false;
}
 

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
		int n,c;
    	cin>>n>>c;
    	vector<int> v(n);
    	for(auto &it:v)
   			cin>>it;
   	    sort(all(v));
   		int s = v[0],e=1e9;
   		int ans = -1;
   		while(s<=e){
   			int mid = s+(e-s)/2; 
   			if(check(mid,c,v)){
   				ans = max(ans,mid);
   				s = mid+1;
   			}
   			else{
   				e = mid - 1;
   			} 
   		}
   		cout<<ans<<endl;
    }
    
  return 0;
}



