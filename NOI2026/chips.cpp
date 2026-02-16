#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
	    int a, b, cb, ca, fa;
	    cin>>a>>b>>ca>>cb>>fa;
	    int BtoA = (b/cb) * ca;
	    int RemainingB = b-BtoA;
	    int NeededLeft = fa-a-BtoA;
	    cout<<"remainingB: "<<RemainingB << ", BtoA: " << BtoA<<", Neededleft: " << NeededLeft <<endl;
	    if(NeededLeft <=0){
	        cout<<0<<endl;
	    }
	    else{
	        int mins = INT_MIN;
    	    int IterationCyclesB = (NeededLeft/cb)+1; //0 to n to n+1
    	    
    	    for(int j=0; j<=IterationCyclesB; j++){
    	        int BtoAval = j*ca;
    	        int A_additional=max(0, NeededLeft-BtoAval);
    	        int bnums;
    	        if (NeededLeft % cb ==0 && j*cb > NeededLeft){
    	            bnums = NeededLeft-RemainingB;
    	            
    	        }
    	        else{
    	            bnums = max((j*cb-RemainingB), 0);
    	        }
    	        
    	        mins = max(mins, (bnums + A_additional));
    	    }
    	    
    	    cout<<mins<<endl;
	    }
	    
	}

}
