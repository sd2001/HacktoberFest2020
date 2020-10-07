	
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define cheetah ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
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
    	string s;cin>>s;
    	int n = s.size();
    	int zero_count = 0,one_count = 0;
    	for(int i =0;i<n;i++){
    		if(s[i]=='1'){
    			one_count++;
    		}
    		else
    			zero_count++;
    	}
    	if(n<=2 || zero_count==0 || one_count==0){
    		cout<<s<<endl;;
    	}
    	else{
    		string s1="";
			for(int i=0;i<n;i++){
				s1+="10";
			}
    		cout<<s1<<endl;
    	}
    }
    
  return 0;
}



