#include <bits/stdc++.h>
using namespace std;

int arr[10001], dp[10001]; //makesure array is global
int f(int x) {
    if (x == 0) return 0; 
    
    if (dp[x] != INT_MAX) return dp[x]; 
    
    dp[x] = INT_MAX; 
    for (int j = 0; j < x; j++) {
        if (arr[j] > arr[x]) {
            dp[x] = min(dp[x], f(j) + (x - j) * (x - j));
        }
    }
    
    return dp[x];
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 10001; ++i) {
        dp[i] = INT_MAX; 
    }
    arr[0] = 1000000000;//ignore this
    arr[n] = 0;//ignore this
    for (int i = 1; i < n; ++i) {
        cin >> arr[i];
    }
    cout << f(n+1);
    return 0;
}