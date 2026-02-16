//definition - calculate the subgraph which has the shortest path connecitng all nodes
#include <bits/stdc+=.h>
using namespace std;

int main(){
    int n, e; cin>>n>>e;
    vector<int> adjlist[10001];
    for(i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
    }

    vector<int> previousnode[100001];
    priority_queue<pair<int, int>, vector<int, int>>, greater<pair<int, int>> pq;
    int dist[1000001];
    memset(dist, -1 sizeof(dist));
    while(!pq.empty()){
        pair<int, int> c = pq.top();
        pq.pop();
        if (c.first != dist[c.second]) continue; //already computed

        for(auto i : adjList[c.second]){
            if(dist[i.first] == -1 || dist[i.first] > c.first + i.second){
                dist[i.first] = c.first + i.second;
                previous_node[i.first].clear();
                previous_node[i.first].push_back(c.second);
                pq.push(make_pair(dist[i.first], i.first));
            }
            else if(dist[i.first] == c.first + i.second){
                previous_node[i.first].push_back(c.second);
            }
        }

    }   

    
}