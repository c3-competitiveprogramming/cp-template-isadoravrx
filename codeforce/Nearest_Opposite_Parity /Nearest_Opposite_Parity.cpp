#include <iostream>
#include <vector>
#include <map>
#include <cstring>
typedef long long ll;
using namespace std;

vector<ll>memo(200005,1000000000);
ll n;
map<ll,ll>ispar;
ll dp(vector<vector<ll> >&adj, vector<ll>&visited, ll par, ll no){
    if(visited[no] != 0){
        return 1000000000;
    }

    visited[no] = 1;
    if((par && ispar[no] == 0) || (!par && ispar[no] == 1)){
        return 1;
    }

    if(memo[no] != 1000000000){
        return memo[no] + 1;
    }

    for(auto x : adj[no]){  
        memo[no] = min(memo[no], dp(adj,visited, par, x));
    }

    return memo[no] + 1;
}
int main(){
   
    cin >> n;

    vector<vector<ll> >adj(n);
   
    for(ll i = 0; i < n ; i++){
        ll num;
        cin >> num;

        ll par = 1;
        if(num % 2 != 0){
            par = 0;
        }
        ispar[i] = par;
        if(i + num < n){
            adj[i].push_back(i + num);
        }

        if(i - num >= 0){
            adj[i].push_back(i - num);
        }
    }

    for(ll i = 0;i < n ; i++){ 
        if(memo[i] == 1000000000){
            vector<ll>visited(n);
            dp(adj, visited, ispar[i], i);
        }
        
        ll ans = memo[i];
        if(ans == 1000000000){
            ans = -1;
        }
        if(i == n-1){
            cout << ans << endl;
            break;
        }
        cout << ans << " ";
    }
}