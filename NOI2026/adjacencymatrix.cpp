#include <bits/stdc++.h>
using namespace std;

int main(){
    int v, e, w, a, b;
    int adjmatrix[1005][1005]; //arbritary number because there could be an infinite number of connections if the graph is cyclic
    cin>>e; //number of edges
    memset(adjmatrix, -1, sizeof(adjmatrix));
    for(int i=0; i<e; i++){
        cin>>a >> b >> w;
        adjmatrix[a][b] = w;
        adjmatrix[b][a] = w;
    }
}