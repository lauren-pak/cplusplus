#include <bits/stdc++.h>
using namespace std;
//mrt stations are 0-indexed. 

int main(){
    int n, e, q;
    cin>>n>>e>>q;
    int dist[n+1][n+1];
    memset(dist, -1, sizeof(dist));

    for(int i=0; i<e; i++){
        int a, b, w;
        cin>>a>>b>>w;
        dist[a][b] = w;
        dist[b][a] = w;
    }
    for(int i=0; i<n; i++){
        dist[i][i]=0;
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k]==-1 || dist[k][j] == -1){
                    continue;
                }
                else if(dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                
            }
        }
    }
    for(int i=0; i<q; i++){
        int x, y;
        cin>>x>>y;
        cout<<dist[x][y]<<endl;
    }
}