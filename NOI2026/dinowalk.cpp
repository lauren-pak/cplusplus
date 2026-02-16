#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dist[n+1][n+1];
    memset(dist, -1, sizeof(dist));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int w;
            cin>>w;
            dist[i][j] = w;
        }
    }
    //min of max
    //max - longest path instead of shorteest path

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]));
            }
        }
    }
    int mheight = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mheight = min(dist[i][j], mheight);
        }
    }
    cout<<mheight;

}