//dfs is basically searching through a graph by looking at its neighbors, then the neighbors neighbors.
// THIS CODE DOESN'T WORK BUT IS SAVED TO SHOW THE PURPOSE OF DFS
//INHERENTLY backtracks (not explicitly coded), but if a node has finished looking through all it's neighbors, then it will automatically jump to one with unvisited neighbors)

#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[501];
bool visited[10001];
set<int> friends;
void dfs(int x){
    for(int i: adjlist[x]){
        if(visited[i]) continue;
        visited[i] = true;
        friends.insert(i);
        dfs(i);
    }
}

int main(){
    int m, n;
    cin>>m>>n;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    dfs(1);
    cout<<friends.size()-1;

}