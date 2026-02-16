#include <bits/stdc++.h>
//unweighted
using namespace std;
int main(){
    int n;
    int adjmtrx[n][n];
    vector<int> adj_list[n];
    for(int i=0; i<n; i++){
        int a; b;
        cin>> a >> b;
        adjmtrix[a][b] = 1;
        adjmtrx[b][a] = 1;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

}