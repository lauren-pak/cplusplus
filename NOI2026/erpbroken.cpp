#include <bits/stdc++.h>
using namespace std;

//
vector<pair<int, int>> adjlist[50001];

int shortest_distance(int source, int dist[50001]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));
    dist[source] = 0;
    while(!pq.empty()){
        pair<int, int> c = pq.top();
        pq.pop();
        if(c.first != dist[c.second]) continue; //if it is already computed 0=0
        for(auto i: adjlist[c.second]){
            if(dist[i.first] == -1 || dist[i.first] > c.first + i.second){
                dist[i.first] = c.first + i.second;
                pq.push(make_pair(dist[i.first], i.first));
            }
        }

    }
}




int main(){
    int n, e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adjlist[a].push_back(make_pair(b, w));
        adjlist[b].push_back(make_pair(a, w));
    }
    int s;
    cin>>s;
    int dist1[50001], dist2[50001];
    memset(dist1, -1, sizeof(dist1));
    memset(dist2, -1, sizeof(dist2));
    shortest_distance(0, dist1);
    shortest_distance(n-1, dist2);
    
    
    
    for(int i=0; i<s; i++){
        int a, b;
        cin>>a>>b;
        int totaldist = dist1[n-1];
        int cheaperOption = totaldist-dist1[a]-dist2[b]-1;
        int cheaperOp2 = totaldist-dist1[b]-dist2[a]-1;
        cheaperOption = max(cheaperOption, cheaperOp2);
        
        if( cheaperOption <0){
            cout<< -1;
        }
        else{
            cout<<cheaperOption;
        }


    }



}