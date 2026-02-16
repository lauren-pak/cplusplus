#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int way1maxsum[n]; int way1max[n];
    int way2maxsum[n]; int way2max[n];
    way1maxsum[0] = way1max[0]= arr[0];
    way2maxsum[n-1] = way2max[n-1] = arr[n-1];
    for (int i=1; i<n; i++){
        way1maxsum[i] = max(way1maxsum[i-1] + arr[i], arr[i]);
        way1max[i] = max(way1maxsum[i], way1max[i-1]);
        way2maxsum[n-i-1] = max(way2maxsum[n-i] + arr[n-i-1], arr[n-i-1]);
        way2max[n-i-1] = max(way2maxsum[n-i], way2max[ni-1]);
    }
    int ans = INT_MIN;
    (for i=0; i<N-1; i++){
        ans = max(ans, way1max[i] + way2max[i+1]);
    }
    cout << ans;

    

}