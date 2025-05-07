#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int visited[502][502];
int n,lava;

bool ok(int x,int y){
    if(x >= 0 && x < n && y >=0 && y < n){
        return true; 
    }

    return false;
}

void dfs( vector<vector<char> >&v, int x, int y){
    for(int i = 0; i < 4; i++){
        int xi = x + dx[i];
        int yi = y + dy[i];
        if(ok(xi,yi) && visited[xi][yi] == 0 && (v[xi][yi]- '0') <= lava){
            visited[xi][yi] = 1;
            v[xi][yi] = '*';
            dfs(v,xi,yi);   
        }
    }
}


int main(){
   
    cin >> n >> lava;

    string s;
    getline(cin,s);
    vector<vector<char> >v(n, vector<char>(n));
    for(int i = 0; i < n ; i++){
        getline(cin,s);
        for(int j = 0; j < n ; j++){
            v[i][j] = s[j];
        }
    }

    

    if(v[0][0] - '0' <= lava){
        dfs(v,0,0); 
        v[0][0] = '*';
    }
    
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            cout << v[i][j];
        }
        cout << endl;
    }
}