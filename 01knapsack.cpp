#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, r;
    cin>> a >> b >> r;
    int arr[a][b];
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            int x; int y;
            cin >> x >> y; 
            arr[i][j] = 2 * (x + y);
        }
    }

    



}