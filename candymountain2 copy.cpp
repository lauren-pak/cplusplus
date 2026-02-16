#include <bits/stdc++.h>
using namespace std;

int K, peb[100001], dp[100001];

int f(int x) {
    if (x == 0) return peb[0]; // Base case
    if (dp[x] != -1) return dp[x];
    
    int y = INT_MAX;
    int best = 0
    for (int j = 1; j <= K; j++) {
        if (x - j >= 0) {
            y = min(f(x - j), y);
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

    for (int i = 0; i < n; i++) {
        dp[i] = -1;
    }
    cout << f(n - 1); // Adjusted to use 0-based indexing

    return 0;
}

//update so it can jump to. random peb and end from a random peb but other than that good job lauren