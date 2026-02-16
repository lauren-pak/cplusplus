#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pair<int, int>> primMST(int V, vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min heap (weight, node)
    vector<int> key(V, INT_MAX); // Minimum edge weight to reach a node
    vector<int> parent(V, -1); // Store MST edges
    vector<bool> inMST(V, false); // Track included nodes

    key[0] = 0; // Start from node 0
    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue; // Skip already included nodes
        inMST[u] = true;

        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) { // Only update if a better edge is found
                key[v] = weight;
                pq.push({weight, v});
                parent[v] = u; // Store edge (u, v) in MST
            }
        }
    }

    // Construct MST edges
    vector<pair<int, int>> mst;
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1)
            mst.push_back({parent[i], i});
    }
    return mst;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    vector<pair<int, int>> mst = primMST(V, adj);

    cout << "Edges in Minimum Spanning Tree:\n";
    for (auto &[u, v] : mst) {
        cout << u << " - " << v << endl;
    }

    return 0;
}
