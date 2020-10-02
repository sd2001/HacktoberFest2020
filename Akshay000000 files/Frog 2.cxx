#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int>v(n+1,0);
	vector<int>cost(n+1,0);
	for(int i=1;i<=n;i++){ 
		cin>>v[i];
	}
	cost[1]=0;
	cost[2]=abs(v[2]-v[1]);
	
	for(int i=3;i<=n;i++){
		cost[i]=abs(v[1]-v[i]);
		for(int j=1;j<=min(i-1,k);j++){
			cost[i]=min(cost[i-j]+abs(v[i]-v[i-j]),cost[i]);
		}
	}
	cout<<cost[n];
	return 0;
}
