#include <bits/stdc++.h>
using namespace std;

int main() {
	int, n, s;
	cin>>n>>s;
    set<pair<int, int> all;
    int students[n][s];
    pair<int, int> temp[n];
    int mins, tempmins = INT_MAX;
    int maxs, tempmaxs = INT_MIN;
	for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
	        cin>>students[i][j];
	        all.insert(make_pair(students[i][j], i);
	        if(j == n-1){
	            sort(students[i], students[i] + s);
	            temp[i] = make_pair(students[i][0], i);
	            
	        }
	    }
	}
	auto it = all.begin();
	while (it){
	    int val = *it;
	    for(int i=0; i<n; i++){
	        if temp[i].first > val{
	            
	        }
	    }
	}
	
	 
	

	
	
	

}
