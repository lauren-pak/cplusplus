#include <bits/stdc++.h>
using namespace std;

int parent[1001], rankarr[1001];

// Find function with path compression
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); 
}

// Union function with union by rank
void unite(int a, int b) {
    int roota = find(a);
    int rootb = find(b);
    
    if (roota != rootb) {
        if (rankarr[roota] > rankarr[rootb]) {
            parent[rootb] = roota;
        } else if (rankarr[roota] < rankarr[rootb]) {
            parent[roota] = rootb;
        } else {
            parent[rootb] = roota;
            rankarr[roota]++;
        }
    }
}

// Kruskal’s Algorithm (Only returns MST weight)
int kruskal(int n, vector<pair<int, pair<int, int>>> &edges) {
    sort(edges.begin(), edges.end()); // Sort edges by weight

    // Initialize Union-Find
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankarr[i] = 0;
    }

    int totalweight = 0, counter = 0;
    for (auto &e : edges) {
        int weight = e.first;
        int a = e.second.first;
        int b = e.second.second;

        if (find(a) != find(b)) { // If no cycle
            totalweight += weight;
            unite(a, b);
            counter++;
            if (counter == n - 1) break; // MST complete
        }
    }
    return totalweight;
}

int main() {
    int n, e;
    cin >> n >> e;
    
    vector<pair<int, pair<int, int>>> edges; // (weight, (nodeA, nodeB))

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }

    int mstweight = kruskal(n, edges);

    cout<<mstweight;
    return 0;
}
