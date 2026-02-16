#include <bits/stdc++.h>
using namespace std;
int dp[10001];
int arr[10001];
int f(int x){
    if (dp[x]!=INT_MAX){
        return dp[x];
        
    }
    for(int i=0; i<x; i++){
        if(arr[i] >= arr[x]){
            dp[x] = min(dp[x], f(i) + (i-x)*(i-x));
        }
    }
    return dp[x];
}



int main(){
    int n; cin>>n;
    arr[0] = 1000000000;
    dp[0]=0;
    arr[n+1] = 0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        dp[i] = INT_MAX;
    }
    dp[n+1] = INT_MAX;
    cout<< f(n+1);
}