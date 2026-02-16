#include <bits/stdc++.h>
using namespace std;

int main() {
    //make everything 0 indees
	int n, int k;
	cin>>n>>k;
	cin>>q;
	int maxs = INT_MIN;
	int sums[n-k+1][n-k+1];
	int arr[n][n];
	memset(arr, 0, sizeof(arr));
	memset(sums, 0, sizeof(sums));
	
	for(int i=0; i<q; i++){
	    int r, c, w;
	    cin>>r>>c>>w;
	    int rowiterations = min(r+1, min(k, n-r+1));
	    int columniterations = min(c+1, min(k, n-r+1));
	    for(int x=0; x<rowiterations; x++){
	        for(int y=0; y<columniterations; y++){
	            
	        }
	        
	    }
	    
	    
	}

}
