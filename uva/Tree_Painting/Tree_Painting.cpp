#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<vector<ll> >adj(200002);
ll tamanho[200002];
ll initscore = 0;
ll ans = 0;
ll n;

void init(ll no, ll parent){
    tamanho[no] = 1;

    for(auto filho : adj[no]){
        if(filho != parent){
            init(filho,no);
            tamanho[no] += tamanho[filho];
        }
    }

    initscore += tamanho[no];
}

void dfs(ll no, ll parent, ll score){
    ans = max(score,ans);
    for(auto filho : adj[no]){
        if(filho != parent){
            dfs(filho, no, score + n - 2 * tamanho[filho]);
        }
    }
}


int main(){
    cin >> n;

    for(int i = 0; i < n -1; i++){
        ll a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init(1,-1);
    dfs(1,-1 ,initscore);
    cout << ans << endl;
}