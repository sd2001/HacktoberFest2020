#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int R, C;
    cin>>R>>C;
    for (int i = 0; i<20; i++)
    {
        cout<<"U";
        for (int j = 0; j<20*(i+1); j++) cout<<"R";
        for (int j = 0; j<20*(i+1); j++) cout<<"L";
    }
}
