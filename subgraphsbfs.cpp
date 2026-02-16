#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, n; cin>>x>>n;
    vector<int> adj_list[x];
    int total = 0;
    bool vis[x] = {false};
    
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);

    }
    for(int i=0; i<x; i++){
        if (vis[i]!=1){
            total++;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (q.size()){
                int c = q.front();
                q.pop();
                for (int j: adj_list[c]){
                    if (vis[j]) continue;
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
    }
    cout<<total;


}