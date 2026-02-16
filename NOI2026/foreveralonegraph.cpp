#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> m >>n;
    vector<int> adjlist[m];
    for (int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        if(a==b){
            continue;
        }
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int count=0;
    for(int i=0; i<m; i++){
        if (adjlist[i].size() ==0){
            count++;
        }
    }
    cout<<count;
}
