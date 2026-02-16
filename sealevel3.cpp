#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[1000001];
bool vis[1000001];
int dist[1000001];
void dfs(int x, int d){
    if (vis[x]) return;
    vis[x] = true;
    dist[x] = d;
    for(auto i: adj_list[x]){
        dfs(i.first, d+ i.second);
    }
}


int main(){
    int n, q; cin>>n;
    
    for(int i=0; i<n-1; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj_list[a].push_back(make_pair(b, w));
        adj_list[b].push_back(make_pair(a, -w));
    }
    
    dfs(1, 0);
    
    cin>>q;
    for(int i=0; i<q; i++){
        int x, y;
        cin>>x>>y;
        
        cout<<dist[y]-dist[x]<<endl;
    }

}