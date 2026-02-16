#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    pair<int, int> arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i].first;
        arr[i].second = i;
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        if(arr[a].first > arr[b].first){
            arr[a].first=arr[b].first;
            arr[a].second=arr[b].second;
            cout<<arr[a].second;
        }
        else if(arr[b].first > arr[a].first){
            arr[b].first=arr[a].first;
            arr[b].second=arr[a].second;
            cout<<arr[b].second;
        }
        else{
            cout<<-1<<endl;
        }
    }
}