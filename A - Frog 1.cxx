#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <bitset>

using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>v(n+1,0);
	vector<int>cost(n+1,0);
	for(int i=1;i<n+1;++i){
		cin>>v[i];
		}
	cost[1]=0;
	cost[2]=cost[1]+abs(v[1]-v[2]);
	for(int i=3;i<n+1;++i){
		cost[i]=min(cost[i-2]+abs(v[i-2]-v[i]),cost[i-1]+abs(v[i-1]-v[i]));
	}
	cout << cost[n];
	return 0;
}
