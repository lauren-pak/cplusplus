#include <bits/stdc++.h>
using namespace std;
int main(){
    int minx = INT_MAX; 
    int miny = INT_MAX;
    int maxx = INT_MIN; 
    int maxy = INT_MIN;
    for (int i=0; i<8; i++){
        int x; cin>> x;
        if (i % 2 ==0){
            minx = min(minx, x);
            maxx = max(maxx, x);
        }
        else{
            miny = min(miny, x);
            maxy = max(maxy, x); 
        }
    }
    int sidelength = max((maxx-minx), (maxy-miny));
    cout<< sidelength * sidelength;

}