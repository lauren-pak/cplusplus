#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c, k;
    cin >> n >> c >> k;
    int arr[n];
    multiset<int> ms;
    int total=0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        if(i<k+1){
            ms.insert(arr[i]);
        }
        if(i<c){
            total+=arr[i];
        }
    }
    
    for(int i=0; i<n-k; i++){
        int begindex = i; 
        int endindex = k+i;
        int count=0;
        int cursum=0;
        if(i==n-k-1){
            ms.erase(arr[begindex]);
            ms.insert(arr[endindex]);
        }
        for (auto it= --ms.end(); count < c; it--){
            cursum += *it;
            count++;
            
        }
        ms.erase(arr[begindex]);
        ms.insert(arr[endindex]);
        total = max(total, cursum);
    }
    cout<<total;

}
