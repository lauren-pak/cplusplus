#include <bits/stdc++.h>
using namespace std;
int vis[100001];
vector<pair<int, int>> adjlist[100001];
//1 mean cycle exists, 2 means visited, 0 means unvisited.

int cyclecheck(int x){
    if(vis[x] == 1) return 1; 
    if(vis[x] == 2) return 0; 
    vis[x] =1; 
    for(pair<int, int> i: adjlist[x]){
        int b = i.first;
        if(vis[b] != 2 && cyclecheck(b)) return 1;
    }
    vis[x] = 2; 
    return 0; 

}
int dp[100001];
bool done[100001];
int longest_path(int u, int target){
    if (done[u]) return dp[u];
    int res = INT_MIN;
    for(auto i: adjlist[u]){
        int v = i.first;
        int w = i.second;
        int temp = longest_path(v, target);
        if(temp != INT_MIN) res = max(res, temp + w);
    }
    done[u] = true;
    if(u == target) dp[u] = max(res, 0); //incase its int min
    else dp[u] = res;
    return dp[u];
    
    
}


int main(){
    int n, e, s, d;
    cin>>n>>e>>s>>d;
    for(int i=0; i<e; i++){
        int a, b, t;
        cin>>a>>b>>t;
        adjlist[a].push_back(make_pair(b, t));
    }
    memset(vis, 0, sizeof(vis));
    memset(done, 0, sizeof(done));
    int result = cyclecheck(s);
    
    if(vis[d] == 0){
        cout << -2;        // no path exists
    }
    else if(result == 1){
        cout << -1;        // infinite path due to cycle
    }
    else{
        cout<<longest_path(s, d);
    }


}