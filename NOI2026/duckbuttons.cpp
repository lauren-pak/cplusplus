#include <bits/stdc++.h>
using namespace std;

int main() {
    typedef long long ll;
	ll n, d;
	cin>>n>>d;
	pair<ll, ll> arr[n]; // always cin N before arr
	ll prevgreatest = 0;
	
	for(ll i=0; i<n; i++){
	    cin>>arr[i].first;
	    arr[i].second = i;
	}
	
	sort(arr, arr+n, [](const std::pair<ll, ll>& a, const std::pair<ll, ll>& b) {
        return a.first > b.first;
    });
	
	ll total = 0;
	
	total += arr[0].first * arr[0].second;
	prevgreatest = arr[0].second;
	
	for(int i=1; i<n; i++){
	   if (arr[i].second > prevgreatest){
	       total += arr[i].first * (arr[i].second - prevgreatest);
	       prevgreatest = arr[i].second;
	   }
	        
	        
	}
	
	cout<<total;

}
