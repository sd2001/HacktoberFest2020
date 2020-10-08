
// id:-deepak290701

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m1;
    cin>>n>>m1;
    multimap<int,int,greater <int> > m;
    while(m1>0){
        int temp,temp1;
        cin>>temp>>temp1;
        m.insert(make_pair(temp1,temp));
        m1--;
    }

    int ans=0;
    int matches=0;
    for(auto it:m){
        if(matches+it.second<=n){
            matches+=it.second;
            ans+=it.second*it.first;
        }
        else{
            int temp=n-matches;
            ans+=temp*it.first;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}

