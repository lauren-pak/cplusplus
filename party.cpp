//bfs is searching nodes based on its level. 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>> n>>m;
    bool vis[n+1];
    vector<int> adjlist[n+1];
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
        
    }
    queue<int> q;
    int counter=0;
    q.push(1);
    memset(vis, 0, sizeof(vis));
    vis[1] = true;
    int level=0;
    //you must add a level after all immediate nodes which have been added per cycle have been covered. add an extra for loop inside. 
    while(q.size() && level < 3){
        int sz = q.size(); //number of nodes at that level. 
        for(int i=0; i<sz; i++){
            int c = q.front();
            q.pop();
            if(c!=1) counter++;
            for(int j: adjlist[c]){
                if(vis[j]) continue;
                vis[j] = true;
                q.push(j);
            }
        }
        level++;
    }
    cout<<counter;
}
