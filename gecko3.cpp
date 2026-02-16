#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int dp [1001][1001];
int gecko(int x, int y){
    if(x==0) return dp[x][y] = arr[x][y];
    if(dp[x][y] != INT_MIN) return dp[x][y];
    dp[x][y] = max(gecko(x-1, y), max(gecko(x-1, y-1), gecko(x-1, y+1))) + arr[x][y];
    return dp[x][y];
}



int main(){
    int n, m; cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    int maxs = INT_MIN;
    for(int i=0; i<m; i++){
        maxs = max(maxs, gecko(n-1, i));
    }

    cout<<maxs;

}