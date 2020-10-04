#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int * arr = new int[n];
        
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        int k;
        cin>>k;
        
        int value = arr[k-1];
        
        sort(arr, arr+n);
        int ans;
        for(int i = 0; i<n; i++){
            if(arr[i]==value){
                ans = i;
                break;
            }
        }
        
        cout<<ans + 1<<endl;
        
    }
}
