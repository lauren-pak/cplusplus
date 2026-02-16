#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[5009];
int dp[5009];
int paths(int v){
    if (dp[v] != -1) return dp[v];
    dp[v] = 0;
    for(int i: adjlist[v]){
        dp[v] += paths(i);
    }
    return dp[v];
}
int main(){
    int n, e;
    cin>>n >> e;
    for(int i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
    }
    dp[A]
}