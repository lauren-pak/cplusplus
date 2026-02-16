#include <bits/stdc++.h>
using namespace std;
int vis[100001];
vector<int> adjlist[100001];
//1 mean cycle exists, 2 means visited, 0 means unvisited.
int 012dfs(int x){
    if(vis[x] == 1) return 1; //there is a cycle.
    if(vis[x] == 2) return 0; //visited before
    vis[x] =1; //visited through searching a node's neighbors
    for(int i: adjlist[x]){
        if(dfs(i)) return 1; //cycle exists
        vis[x] = 2; //finished searching through all the neighbors, completely visited.
        return 0; //no cycle, for backtracking purposes.
    }

}
int main(){

}