#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cheetah ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0)
#define f first
#define s second
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
    	string s;
    	cin>>s;
    	
    	for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]=='A'&&s[i+1]=='B')
        {
            for(int j=i+2;j<s.length()-1;j++)
            {
                if(s[j]=='B'&&s[j+1]=='A')
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
        if(s[i]=='B'&&s[i+1]=='A')
        {
            for(int j=i+2;j<s.length()-1;j++)
            {
                if(s[j]=='A'&&s[j+1]=='B')
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
        
    }
    cout<<"NO"<<endl;

    }
    
  return 0;
}





