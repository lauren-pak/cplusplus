#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int arr[n];
    int seats=0;
    if(n%2==1){
        seats = (n+1)/2;
    }
    else{
        seats = n/2;
    }
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int maxs=0;
    sort(arr, arr+n, greater<int>());
    for(int i=0; i<seats; i++){
        maxs=max(maxs, maxs+arr[i]);
    }
    cout<<maxs;

}

#use DP to solve?