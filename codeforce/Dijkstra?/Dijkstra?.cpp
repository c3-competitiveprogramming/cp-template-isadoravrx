#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
ll dist[100002];
ll n,m;
vector<ll>ans;
ll mindist = 100000000000000000;

void djk(vector<set<pair<ll,ll> > >&adj, ll start){
    set<pair<pair<ll,ll> , vector<ll> > >st;
    st.insert(make_pair(make_pair(0,start),ans));
    dist[start] = 0;

    while(!st.empty()){
        ll no = (*st.begin()).first.second;
        ll cost = (*st.begin()).first.first;
        vector<ll>temp = (*st.begin()).second;

        if(no == n && cost < mindist){
            ans = temp;
            mindist = cost;
        }

        st.erase(st.begin());
        for(auto it : adj[no]){
            if(it.second + cost < dist[it.first] || dist[it.first] == -1){
                dist[it.first] = it.second + cost;
                temp.push_back(it.first);
                st.insert(make_pair(make_pair(dist[it.first], it.first),temp));
                temp.pop_back();
            }
        }
    }
}


int main(){
   
    cin >> n >> m;

    vector<set<pair<ll,ll> > >adj(n+1);
    map<pair<ll,ll>,ll >mp;
    for(ll i = 0; i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == b){
            continue;
        }

        if(mp.find(make_pair(a,b)) == mp.end()){
            adj[a].insert(make_pair(b,c));
            adj[b].insert(make_pair(a,c));
        }else{
            if(mp[make_pair(a,b)] > c){
                auto it = adj[a].find(make_pair(b,mp[make_pair(a,b)]));
                adj[a].erase(it);

                it = adj[b].find(make_pair(a,mp[make_pair(a,b)]));
                adj[b].erase(it);
            }
        }
        
    }

    memset(dist,-1,sizeof(dist));
    djk(adj,1);

    if(ans.size() == 0){
        cout << -1 << endl;
        return 0;
    }
    cout << 1 << " ";
    for(ll i = 0; i < ans.size(); i++){
        if(i != 0 ){
            cout << " ";
        }
        cout << ans[i];
    }  

    cout << endl;

}