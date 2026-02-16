#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adjlist[1000];
int main(){
    int e, a, b, w;
    cin>>e;
    for(int i=0; i<e; i++){
        cin>>a>>b>>w;
        adjlist[a].push_back(make_pair(b, w));
        adjlist[b].push_back(make_pair(a, w));
    }

}