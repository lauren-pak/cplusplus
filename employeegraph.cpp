#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[1000001];
int vis[1000001];
int finddepth(int x){
    int maxdepth = 1;
    if (vis[x]) return 0;
    vis[x] = 1;
    for(int i: adjlist[x]){
        maxdepth = max(maxdepth, finddepth(i) + 1);
    }
    return maxdepth;
}


int main(){
    int n; cin>>n;
    for(int i=1; i<n; i++){
        int p; cin>>p;
        adjlist[p].push_back(i);
    }
    cout<<finddepth(0);
    
    

}
