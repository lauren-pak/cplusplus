//more efficient solution - don't need to create a seperate adjacency list, you can search in the grid itself.

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adjlist[101][101];
bool visited[101][101];
void dfs(int x, int y){
    visited[x][y] = true;
    for(pair<int, int> i: adjlist[x][y]){
        if(!visited[i.first][i.second]){
            dfs(i.first, i.second);
        }
    }
}

int main(){
    int r, c;
    cin>>r>>c;
    char a, table[r][c];
    memset(visited, false, sizeof(visited));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>a;
            table[i][j] = a;
            if(a=='H'){
                if((i-1) >=0 && table[i-1][j]=='H'){
                    adjlist[i][j].push_back(make_pair(i-1, j));
                    adjlist[i-1][j].push_back(make_pair(i, j));
                    
                }
                
                if((j-1) >= 0 && table[i][j-1]=='H'){
                    adjlist[i][j].push_back(make_pair(i, j-1));
                    adjlist[i][j-1].push_back(make_pair(i, j));
                    
                }
               
            }
        }
    }
    int counter=0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!visited[i][j] && table[i][j] == 'H'){
                dfs(i, j);
                counter++;
            }
        }
    }
    cout<<"Oh, bother. There are "<<counter<<" pools of hunny.";
}