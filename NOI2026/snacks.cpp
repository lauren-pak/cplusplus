#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    long long sums = 0;
    map<int, long long> freq;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sums += a;
        freq[a]++;
    }

    cout << sums << '\n';

    while (q--) {
        int l, r, j;
        cin >> l >> r >> j; 
        
        
        auto it = freq.lower_bound(l);

        while (it != freq.end() && it->first <= r) {
            long long cnt = it->second;
            int val = it->first;

            
            if (j!=val){
                freq[j] += cnt;
                sums -= cnt * val;
                sums += cnt * j;
                it = freq.erase(it);
            }else{
                ++it;
            }
            
        }


        cout << sums << '\n';
    }
}
