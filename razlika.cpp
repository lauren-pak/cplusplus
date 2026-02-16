#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n>>k;
	int arr[n];
	int diff[n-1];
	multiset<int> ms;

	for(int i=0; i<n; i++){
	    cin>>arr[i];
    } 
	  
	sort(arr, arr+n);
	
	for(int i=0; i<n-1; i++){
	    diff[i] = arr[i+1] - arr[i];
	    if (i < n-k-1){
	        ms.insert(diff[i]);
	    }
	}
	
	
	int minz = INT_MAX;
	for(int i=0; i<n-k-1; i++){
	    int start = i;
	    int end = n-k+i-2;
	    
	    int maxdiff= arr[end+1] - arr[start];
	    
	    if(i==n-k-1){
	        ms.erase(diff[start]);
	        ms.insert(diff[end]);
	    }
	    
	   
	   minz = min(minz, (*ms.begin() + maxdiff));
	   
	    
	    ms.erase(diff[start]);
	    ms.insert(diff[end]);
	    
	}
	cout<<minz;

}



//cout<<"min diff:" << *ms.begin() << " ";
	    //cout<<"max diff:" << maxdiff<<" ";
	    //cout<<"minz:" << minz << " ";
	    //cout<<"size of ms:" << ms.size()<< endl;