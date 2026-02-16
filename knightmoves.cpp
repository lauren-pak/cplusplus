#include <bits/stdc++.h>
using namespace std;
int main(){
    int dir[8][2]= {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};


    int dist[10005][10005];
    queue<pair<int, int>> q; //node, dist from source
    memset(dist, -1, sizeof(dist));
    int source;
    q.push_back(make_pair(source, 0));

    while(!q.empty){
        v = q.front().first;
        d = q.front().second;
        q.pop();
        if (dist[v] != -1) continue;
        dist[v] = d;
        for(int i: arr[v]){
            q.push_back(make_pair(i, d+1));
        }
    }


}