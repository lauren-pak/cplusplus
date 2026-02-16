#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int, int>&i, const pair<int, int>&j) 
{ 
    return i.second < j.second; 
} 
int main(){
    int l, n;
    cin >> l >> n;
    int lis[n];
    pair<int, int> people[n];
    for(int i=0; i<n; i++){
        int t, s;
        cin >> t >> s;
        people[i] = make_pair(t, l/s+t);
    }
    sort(people, people+n, compare);
    vector<int> b;
    for(int i=0; i<n; i++){
        auto it = lower_bound(b.begin(), b.end(), people[i].first);
        if(it==b.end()) b.push_back(people[i].first);
        else *it = people[i].first;
    }
    cout<<b.size();
}


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int l, n;
// 	cin>>l>>n;
// 	pair<int, int> friends[n];
// 	vector<int> b;
	
	
// 	for(int i=0; i<n; i++){
// 	    cin >> friends[i].first;
// 	    cin >> friends[i].second;
// 	}
// 	sort(friends, friends + n, [](const pair<int, int>& a, const pair<int, int>& b) {
//         return a.first < b.first; // Compare second elements in ascending order
//     });
    

//     for(int i=0; i<n; i++){
//         int x = (l/friends[i].second) + friends[i].first;
//         auto it = lower_bound(b.begin(), b.end(), x);
//         if(it == b.begin()) b.push_back(x);
//         else{
//             *it = x;
//         }
        
//     }
//     cout<<b.size();

// }


