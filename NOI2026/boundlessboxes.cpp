#include <bits/stdc++.h>
using namespace std;
int main(){
    int m, n, s;
    cin>>m>>n>>s;
    queue<pair<int, int>> q;
    int dist[1001][1001];
    memset(dist, -1, sizeof(dist));
    for(int i=0; i<s; i++){
        int a, b;
        cin>>a>>b;
        a--; b--;
        q.push(make_pair(a, b));
        dist[a][b] = 0;
    }
    
    int d1[8] = {-1,-1,-1, 0,0, 1,1,1};
    int d2[8] = {-1, 0, 1,-1,1,-1,0,1};
    
    int maxs = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int newx = x+d1[i];
            int newy = y+d2[i];
            if(newx >= 0 && newx < m && newy >= 0 && newy < n){
                if(dist[newx][newy] == -1){
                    dist[newx][newy] = dist[x][y] + 1;
                    maxs = max(dist[newx][newy], maxs);
                    q.push(make_pair(newx, newy));
                }
            }
        }
        
    }
    cout<<maxs+1;
    
    
}