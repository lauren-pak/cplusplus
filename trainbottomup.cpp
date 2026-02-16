#include <bits/stdc++.h>
using namespace std;
int arr[10001], dp[10001];
int main(){
    int n; cin>>n;
    arr[0] = 1000000000; //ignore this
    for (int i=1; i<n+1; i++){
        cin>>arr[i];
    }
    arr[n+1] = 0; //ignore this
    
    for (int i = 0; i < 10001; ++i) {
        dp[i] = INT_MAX; 
    }    
    
    dp[0] = 0;
    for(int i=1; i<n+2; i++){
        for(int j=0; j<i; j++){
            if(arr[j] > arr[i]){
                dp[i] = min(dp[i], (dp[j]+(i-j) * (i-j)));
            }
        }
    }
    cout<<dp[n+1];
}