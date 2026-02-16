#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adjlist[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dikstras(int dist[], int start){

    while (!pq.empty()) pq.pop(); // Clear the priority queue

    dist[start] = 0;
    pq.push(make_pair(0, start));

    //c.first is weight, c.second is node
    while(!pq.empty()){
        pair<int, int> c= pq.top();
        pq.pop();
        if (c.first != dist[c.second]) continue; //already computed

        for(auto i : adjlist[c.second]){
            if(dist[i.first] == -1 || dist[i.first] > c.first + i.second){
                dist[i.first] = c.first + i.second;
                pq.push(make_pair(dist[i.first], i.first));
            }
        }

    }   
}
int main(){
    int n, e; cin>>n>>e;
    for(int i=0; i<e; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adjlist[a].push_back(make_pair(b, w));
        adjlist[b].push_back(make_pair(a, w));
    }
    int dist1[n];
    int dist2[n];
    memset(dist1, -1, sizeof(dist1));
    memset(dist2, -1, sizeof(dist2));

    dikstras(dist1, 0);
    dikstras(dist2, n-1);

    int d = dist1[n-1];

    int k; cin>>k;
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        int D = dist1[n-1];
        int erp=-1;
        if(dist1[x] > 0 && dist2[y] > 0 || dist2[x] > 0 && dist1[y] > 0){
            int erp1 = D-dist1[x] - dist2[y] - 1;
            int erp2 =D-dist2[x] - dist1[y] - 1;
            erp = max(erp1, erp2);

        }

        if(erp<0){
            cout << -1 << endl;
        }
        else{
            cout << erp << endl;
        }

    


}


//calculation errors, check if greater than 0