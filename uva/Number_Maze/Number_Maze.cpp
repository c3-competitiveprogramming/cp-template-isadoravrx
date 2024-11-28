#include <iostream>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;
ll n,m;


void djk(vector<vector<ll> >&v, vector<vector<ll> >&dist){

    set<pair<ll,pair<ll,ll> > >st;
    st.insert(make_pair(v[0][0],make_pair(0,0)));
    dist[0][0] = v[0][0];

    while(!st.empty()){
        ll cost = (*st.begin()).first;
        ll i = (*st.begin()).second.first;
        ll j = (*st.begin()).second.second;

        st.erase(st.begin());

        if(i != 0){
            if(v[i-1][j] + cost < dist[i-1][j]){ //cima
                dist[i-1][j] = v[i-1][j] + cost;
                st.insert(make_pair(dist[i-1][j],make_pair(i-1,j)));
            } 
        }
        if(i != n-1){
            if(v[i+1][j] + cost < dist[i+1][j]){//baixo
                dist[i+1][j] = v[i+1][j] + cost;
                st.insert(make_pair(dist[i+1][j],make_pair(i+1,j)));
            }
        }
        if(j != 0){
            if(v[i][j-1] + cost < dist[i][j-1]){//esq
                dist[i][j-1] = v[i][j-1] + cost;
                st.insert(make_pair(dist[i][j-1],make_pair(i,j-1)));
            }
        }
        if(j != m-1){
            if(v[i][j+1] + cost < dist[i][j+1]){//dir
                dist[i][j+1] = v[i][j+1] + cost;
                st.insert(make_pair(dist[i][j+1],make_pair(i,j+1)));
            }
        }

    }

}

int main(){
    ll t;
    cin >> t;

    while(t--){
        cin >> n >> m;

        vector<vector<ll> >v(n, vector<ll>(m));
        vector<vector<ll> >dist (n, vector<ll>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ll num;
                cin >> num;

                v[i][j] = num;
                dist[i][j] = 1000000000000000000; //10e18
            }
        }
        djk(v, dist);
        cout << dist[n-1][m-1] << endl;
    }
}
