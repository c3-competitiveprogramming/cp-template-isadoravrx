#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

pair<ll, pair<ll,ll> > st[4*10000];
ll v[10000];

pair<ll, pair<ll,ll> > build(ll ind, ll l, ll r){
    if(l == r){
        return st[ind] = make_pair(v[l], make_pair(l,r));
    }

    ll mid = (l+r)/2;
    pair<ll, pair<ll,ll> > filhoesq = build(2*ind+1, l, mid);
    pair<ll, pair<ll,ll> > filhodir = build(2*ind+2, mid+1, r);
    st[ind] = max(filhoesq,filhodir);
    
    pair<ll, pair<ll,ll> >me = make_pair(filhoesq.first + filhodir.first, make_pair(l,r));
    st[ind] = max(st[ind], me);

    return st[ind];
}


int main(){
    ll t;
    cin >> t;

    while(t--){
        memset(st,0,sizeof(st));
        memset(v,0,sizeof(v));
        
        ll n;
        cin >> n;

        for(ll i = 0; i < n ; i++){
            cin >> v[i];
        }

        build(0,0,n-1);
        cout << st[0].first << " " << st[0].second.first << " " << st[0].second.second << endl;
    }
}