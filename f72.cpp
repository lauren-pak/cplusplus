#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>> N;
    int drivers[N];
    int finalpoints[N];
    for (int i=0; i<N; i++){
        cin>>drivers[i];
    }
    sort(drivers, drivers + N, greater<int>());
    int win = 0;
    int maxs = INT_MIN;
    int maxs_index = 0;
    for (int i=0; i<N; i++){
        finalpoints[i] = drivers[i] + i + 1;
        
        if (finalpoints[i] >= maxs){
            maxs = finalpoints[i];
            maxs_index = i;
        }
        //cout << "driver: " << drivers[i] << " position: " << i << " points: " << finalpoints[i] << " max: "<< maxs << " win: " << win <<endl;
        
    }
    cout<< maxs_index + 1;
    
    
    
    
    
}

