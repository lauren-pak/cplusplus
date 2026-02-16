#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[10001];
int vis[100001];
vector<int> topo;

bool hascycle(int x){
    if(vis[x]==1) return true;
    if(vis[x]==2) return false;
    vis[x] = 1;
    for(int i: adjlist[x]){
        if (hascycle(i) == true) return true;
    }
    topo.push_back(x);
    vis[x] = 2;
    return false;
}

int main(){
    int n, e;
    cin>>n>>e;
    memset(vis, -1, sizeof(vis));
    for(int i=0; i<e; i++){
        int a, b, c;
        char c1, c2;
        cin>>a>>c1>>b>>c2>>c;
        if(c1 == '>'){
            adjlist[a].push_back(b);
            adjlist[a].push_back(c);
        }
        else{
            adjlist[a].push_back(c);
            adjlist[b].push_back(c);
        }
    }

    for(int i=0; i<n; i++){
        if(vis[i] == -1) {
            if(hascycle(i)){
                cout<<0;
                return 0;
            }
        
        }
    }
    reverse(topo.begin(), topo.end());

    for(int i: topo){
        cout<<i<<" ";
    }



    
}