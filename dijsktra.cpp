#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int ts, te; cin>>ts>>te;
    vector<pair<int, int>> adjlist[n];
    for(int i=0; i<n; i++){
        int a, b, x;
        cin>>a>>b>>x;
        adjlist[a].push_back(make_pair(b, x));
        adjlist[b].push_back(make_pair(a, x));
    }
    priority_queue<pair<int, int>, vector<int, int>>, greater<pair<int, int>> pq;


    int dist[n] = {-1};
    dist[0] = 0;
    pq.push(make_pair(0, ts));

    //c.first is weight, c.second is node
    while(!pq.empty()){
        pair<int, int> c = pq.top();
        pq.pop();
        if (c.first != dist[c.second]) continue; //already computed

        for(auto i : adjList[c.second]){
            if(dist[i.first] == -1 || dist[i.first] > c.first + i.second){
                dist[i.first] = c.first + i.second;
                pq.push(make_pair(dist[i.first], i.first));
            }
        }

    }   

    cout<<dist[te];






}