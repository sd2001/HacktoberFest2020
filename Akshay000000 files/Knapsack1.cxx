#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;
int main(){
	int n,maxw;
	cin >>n>>maxw;
	multimap<int,int>m;
	for(int i=0;i<n;i++){
		int v,w;cin >>w>>v;
		m.insert({v,w})
		};
	multimap<int,int>iterator itr;
	itr=m.end();
	for(;itr>=itr.begin();itr--){
		if((maxw-itr->second)>=0){
			cost=cost+itr->first;
			maxw=maxw-itr->second;
			}
		else { cout << cost;return 0;}
		}
	return 0;
}	
