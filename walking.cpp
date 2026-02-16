#include <bits/stdc++.h>
using namespace std;

int main() {
	int l, n;
	cin>>l>>n;
	pair<int, int> friends[n];
	int arr[n], lis[n];
	int ans=0;
	for(int i=0; i<n; i++){
	    cin >> friends[i].first;
	    cin >> friends[i].second;
	}
	sort(friends, friends + n, [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first; 
    });
    for(int i=0; i<n; i++){
        arr[i] = (l/friends[i].second) + friends[i].first;
        lis[i] = 1;
        for(int j=0; j<i; ++j){
            if(arr[j] > arr[i]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        ans = max(ans, lis[i]);
    }
    cout<<ans;

}
