#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N], lis[N], lds[N], ans = 0;
    for (int i = 0; i < N; ++i) {
        cin>> arr[N];
        lis[i] = 1;
        lds[N-i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                lis[i] = max(lis[i], lis[j]+1);
            }
            if(arr[N-i] > arr[N-j]){
                lds[N-i] = max(lds[N-i], lds[N-j]+1);
            }
        }
    }
    for(int i=0; i<N; i++){
        ans = max(ans, lis[i]+lds[i-1]);
    }
    cout << ans;
}
