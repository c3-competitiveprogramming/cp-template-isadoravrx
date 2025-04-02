#include <iostream>
#include <map>
#include <vector>
#include <cassert>
#include <random>
#include <chrono>     

typedef long long ll;
using namespace std;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int uniform(ll l, ll r) {
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

const int MOD = 1e9 + 7;
const int H = 13;
const int P = uniform(1, MOD-1);
const int P2 = uniform(1, MOD-1);

struct tree {
	int fn;
	vector<vector<int> > g;
	vector<int> sz, cs;
	vector<bool> forb;

	tree(int n_) : fn(n_), g(n_), sz(n_), forb(n_) {}

	void dfs_size(int v, int p) {
		sz[v] = 1;
		for (int u : g[v]) if (u != p and !forb[u]) {
			dfs_size(u, v), sz[v] += sz[u];
		}
	}
	
	int subtree_hash(int v, int p) {
		int h = H;
		for (int u : g[v]) if (u != p and !forb[u]) {
			h = ll(h) * (P + subtree_hash(u, v)) %  MOD;
		}
		return h;
	}
	int tree_hash(int v=0) {
		cs.clear();
		dfs_size(v, -1);
		return subtree_hash(v, -1);
		
	}
};

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        tree t1(n);
        for(int i = 0; i < n-1; i++){
            int a,b;
            cin >>a >> b;

            a--;
            b--;
            t1.g[a].push_back(b);
            t1.g[b].push_back(a);
        }   

        tree t2(n);
        for(int i = 0; i < n-1; i++){
            int a,b;
            cin >>a >> b;

            a--;
            b--;
            t2.g[a].push_back(b);
            t2.g[b].push_back(a);
        }
        
        int h1 = t1.tree_hash();
        int h2 = t2.tree_hash();

        if(h1 == h2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
}