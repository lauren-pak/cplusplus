#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
        if(i==0){
            int leftgears = 1;
            int leftspeeds =1;
        }
        leftspeeds = (leftgears/arr[i]) * leftspeeds;
        leftgears = arr[i];
    }

    if(leftspeeds == 1){
        cout<<"YES";
    }
    else{
        cout<<"NO"
    }


}