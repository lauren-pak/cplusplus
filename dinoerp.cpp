#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int dist[n][n]; //not a matrix, but like from dist node to dist node
    int vis=n*n;
    memset(dist, INT_MAX, sizeof(dist));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>dist[i][j];
            if(dist[i][j] == 0){
                dist[i][j] = INF;
            }
        }
        dist[i][i] = 0;
    }
    int maxs = 0;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                maxs = max(maxs, dist[i][j]);
            }
        }
    }
    cout<< maxs;



}