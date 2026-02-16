//bfs is searching nodes based on its level. 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>> n>>m;
    bool visited[n];
    vector<int> adjlist[n];
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
        
    }
    queue<int> q;
    int depth=0;
    int counter=0;
    q.push(1);
    visited[1] = true;
    while(q.size()){
        int c = q.front();
        q.pop();
        counter++;
        if(depth < 2){
            for(int j: adjlist[c]){
            if(vis[j]) continue;
            vis[j] == true;
            q.push(j)
            }
            depth++;
        }
        
    }
    cout<<counter;
}
