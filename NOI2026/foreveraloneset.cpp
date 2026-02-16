#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>m>>n;
    set<int> cats;
    for(int i=0; i<n; i++){
        int a, b;
        cin>> a>>b;
        if (a==b){
            continue;
        }
        cats.insert(a);
        cats.insert(b);
    }
    
    cout<<(m-cats.size());
}