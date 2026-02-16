#include <bits/stdc++.h>
using namespace std;

//
vector<pair<int, int>> adjlist[1001];
int shortest_distance(int source, int target, int dist[1001]){
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
    return dist[target];
}




int main(){
    int n, e, t, h;
    cin>>n>>e>>t>>h;
    for(int i=0; i<e; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adjlist[a].push_back(make_pair(b, w));
    }
    int dist1[1001], dist2[1001];
    memset(dist1, -1, sizeof(dist1));
    memset(dist2, -1, sizeof(dist2));

    //way 1 distance
    int cost1= shortest_distance(t, h, dist1);
    int cost2 = shortest_distance(h, t, dist2);
    if (cost1==-1 || cost2==-1){
        cout<<-1;
    }
    else{
        cout<<cost1+cost2;

    }


}