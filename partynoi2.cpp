#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int seats=0;
    int maxs=0;

    if(n%2==1){
        seats = (n+1)/2;
    }
    else{
        seats = n/2;
    }
    int curtotal=0;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        if (i<seats){
            pq.push(x);
            curtotal+=x;
            maxs = max(maxs, curtotal);
        }
        else if(x > pq.top()){
            curtotal = curtotal-pq.top() + x;
            maxs = max(maxs, curtotal);
            pq.pop();
            pq.push(x);
        }
    }
    cout<<maxs;

}