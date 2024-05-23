#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;
ll n,m;
ll bestsum = 1000000000000000000;


void dfs(vector<vector<ll> >&v,vector<vector<ll> > &visited,int i, int j, ll sum){
    sum += v[i][j];
    visited[i][j] = 1;
    if(i == n -1 && j == m - 1){
        bestsum = min(bestsum, sum);
        return;
    }
    
    if(i > n-1 || j > m -1){
        return;
    }

    if(i != 0 && visited[i-1][j] == 0){
        dfs(v,visited,i-1,j,sum);
    }
    if(i != n-1 && visited[i+1][j] == 0){
        dfs(v,visited,i+1,j,sum);
    }
    if(j != 0 && visited[i][j-1] == 0){
        dfs(v,visited,i,j-1,sum);
    }
    if(j != m-1 && visited[i][j+1] == 0){
        dfs(v,visited,i,j+1,sum);
    }
}

int main(){
    ll t;
    cin >> t;

    while(t--){
        cin >> n >> m;
    

    
        vector<vector<ll> >v(n, vector<ll>(m));
        vector<vector<ll> > visited(n, vector<ll>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ll num;
                cin >> num;

                v[i][j] = num;
            }
        }
         
        bestsum = 1000000000000000000;
        dfs(v,visited, 0,0,0);
        cout << bestsum << endl;
    }
}
