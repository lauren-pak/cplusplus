 #include <bits/stdc++.h>
 using namespace std;
 int main(){
     int N; int money;
     cin>>N>>money;
     int coin[N];
     int dp[money+1];
     fill(dp, dp + money + 1, INT_MAX);
     
     for(int i=0; i<N; i++){
         cin>>coin[i];
     }
     dp[0] = 0;
     for (int i=1; i<money+1; i++){
         for(int j=0; j<N; j++){
             if (i-coin[j] >= 0 && dp[i - coin[j]] != INT_MAX){
                 dp[i] = min(dp[i], dp[i-coin[j]] + 1);
             }
         }
     }
     if(dp[money] == INT_MAX){
         cout<<-1;
     }else{
         cout<<dp[money];
     }
     
     
 }
     




//TOPDOWN APPROACH

// #include <bits/stdc++.h>
// using namespace std;
// int n, v, coins[101], dp[101];
// int mincoins(int val){
//     if (val==0) return 0;
//     if (dp[val]!= -1) return dp[val];
//     dp[val] = 1000000;
//     for(int i=0; i<n; i++){
//         if(val>=coins[i]) dp[val] = min(dp[val], mincoins(val-coins[i])+1);
//     }
//     return dp[val];

// }

// int main(){
//     memset(dp, -1, sizeof(dp));
//     cin >> n >>v;
//     for(int i=0; i<n; i++){
//         cin>>coins[i];
//     }
//     cout << mincoins(v);
    
    
// }


