#include <bits/stdc++.h>
using namespace std;

bool comp (int a, int b) {
  return a > b;
}


int main() {
	int n; 
	cin >> n;
	int prices[n];
	int increasing[n];
	int total = 0;
	for (int i=0; i<n; i++){
	    cin >>prices[i];
	    total += prices[i];
	}
	for (int i=0; i<n; i++){
	    cin >>increasing[i];
	}
	sort(increasing, increasing + n, comp);

	for (int i=1; i<n; i++){
	    total += increasing[i] * i;
	}
	cout<<total;

}
