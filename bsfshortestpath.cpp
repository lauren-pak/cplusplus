#include <bits/stdc++.h>
using namespace std;
//BFS SHORTEST PATH 
int main(){
    vector<int> adjlist[10005];
    int dist[10005];
    queue<pair<int, int>> q; //node, dist from source
    memset(dist, -1, sizeof(dist));
    int source;
    q.push_back(make_pair(source, 0));

    while(!q.empty){
        v = q.front().first;
        d = q.front().second;
        q.pop();
        if (dist[v] != -1) continue;
        dist[v] = d;
        for(int i: arr[v]){
            q.push_back(make_pair(i, d+1));
        }
    }

//bfs general
    vector<int> adj[1000009];
    bool vis[1000009];

    queue<int> q;
    q.push(s); //start node
    while (q.size()) {
    int c = q.front();q.pop();
    for (int j: adj[c]) {
    if (vis[j]) continue;
    vis[j] = 1;
    q.push(j);
    }
}

}