#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[1001];
int vis[1001];
int dfs(int x){
    if(vis[x] == 1) return 1;//there is a cycle
    if(vis[x] == 2) return 0; //visited
    vis[x] =1;
    for(int i: adjlist[x]){
        if(dfs(i)) return 1; //if dfs(i) == 1 means there is a cycle
    }
    vis[x] = 2; //mark node as completely visited so u know there wont be a cycle anymore
}



int main() {
    // Your code here
}