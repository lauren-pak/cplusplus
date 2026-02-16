#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    pair<int, int> arr[n];
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        arr[i] = make_pair(x, y);
    }
    sort(arr, arr+n);
    int useful=0;
    int prevmax = INT_MIN;
    for(int i=n-1; i>-1; i--){
        if(arr[i].second > prevmax){
            useful++;
        }
        prevmax = max(prevmax, arr[i].second);
    }
    
    cout<<useful;
}