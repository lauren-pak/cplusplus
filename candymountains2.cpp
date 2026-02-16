#include <bits/stdc++.h>
using namespace std;

int K, peb[1000], dp[1000];

int f(int x) {
    int y = INT_MAX;
    if (x == 0) return 0; // Base case
    if (dp[x] != -1) return dp[x];
    
    int result = INT_MIN;
    for (int j = 0; j<K+1; j++) {
        if((x-j) > 0){
            int y = min(f(x-j), y);
        }
        
    }
    dp[x] = max(peb[x], y);
    return dp[x];
}

int main() {
    int n;
    cin >> n >> K;

    for (int i = 0; i < n; ++i) {
        cin >> peb[i];
    }

    for(int i=0; i<n; i++){
        dp[i] = -1;
    }
    cout << f(n - 1); // Adjusted to use 0-based indexing

    return 0;
}






























//int indx=0;
    // int maxs=0, mins;
    // while(indx+k <= n){
    //     int sta;
    //     for(int i=indx; i<indx+k; i++){
    //         if(peb[i] < mins){
    //             mins = peb[i];
    //             sta = i;
    //         }
    //     }
    //     maxs = max(maxs, peb[sta]);
    //     indx = sta+1;


    // }
    // cout<<maxs;