#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e; cin >> n >> e;
    int ts, te; cin >> ts >> te;

    vector<pair<int, int>> adjlist[2501]; // Keeping this as-is
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for (int i = 0; i < e; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        adjlist[a].push_back(make_pair(b, x));
        adjlist[b].push_back(make_pair(a, x));
    }

    int dist[n];  
    fill(dist, dist + n, -1); 
    
    dist[ts] = 0; 
    pq.push(make_pair(0, ts));
    
    //The priority queue (pq) stores {weight, node} pairs, where:
        //c.first → current shortest distance from ts (source node).
        //c.second → current node being processed.
        
    //The adjacency list (adjlist[]) stores {neighbor, weight} pairs, where:
        //i.first → neighbor node connected to c.second.
        //i.second → edge weight between c.second and i.first.'''

    while (!pq.empty()) {
        pair<int, int> c = pq.top();
        pq.pop();
        if (c.first != dist[c.second]) continue; // Already processed with a shorter path

        for (auto i : adjlist[c.second]) {
            if (dist[i.first] == -1 || dist[i.first] > c.first + i.second) {
                dist[i.first] = c.first + i.second;
                pq.push(make_pair(dist[i.first], i.first));
            }
        }
    }

    if (dist[te] == -1) cout << "Unreachable"; 
    else cout << dist[te];

    return 0;
}
