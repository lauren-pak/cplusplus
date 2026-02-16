#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    pair<int, int> swords[n];
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        swords[i].first = a;
        swords[i].second = b;
    }
    sort(swords, swords+n);
    int maxs = INT_MIN;
    int useful =0;
    for(int i=n-1; i>=0; i--){
        if(swords[i].second > maxs){
            useful++;
            maxs = swords[i].second;
        }
    }
    cout<<useful;
}
