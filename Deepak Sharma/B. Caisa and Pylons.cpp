b

// id:-deepak290701

#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
     cin>>a[i];
   int count=a[0];
   int h=0;
   for(int i=0;i<n-1;i++){
      if(a[i]-a[i+1] >= 0){
        h+=(a[i]-a[i+1]);
      }
      else{
        if(h>0){
            h=h-abs(a[i]-a[i+1]);
            if(h<0){
                count+=abs(h);
                h=0;
            }
        }
        else{
            count+=abs(a[i]-a[i+1]);
        }
      }
   }
   cout<<count<<"\n";
    return 0;
}
