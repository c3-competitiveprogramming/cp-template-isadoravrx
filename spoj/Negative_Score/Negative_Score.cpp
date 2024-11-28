#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
vector<ll>v(100000);
vector<ll>st(4 * 100000);

ll build(ll ind, ll l, ll r){
    if(l == r){
        st[ind] = v[l];
        return st[ind];
    }

    ll mid = (l+r)/2;
    st[ind] = min(build(2*ind + 1, l,mid) , build(2*ind + 2, mid+1, r)); 
    return st[ind];
}

ll query(ll a, ll b, ll ind, ll l, ll r){
    if(a > r || b < l){
        return 1000000000;
    }

    if(l >= a && r <= b){
        return st[ind];
    }

    int mid = (l+r)/2;
    return min(query(a,b,2*ind+1,l,mid), query(a,b,2*ind+2,mid+1,r));
}

int main(){
    ll t;
    scanf("%lld",&t);
    ll test = 1;
    while(t--){
        ll n,q;
        scanf("%lld %lld",&n, &q);

        v.assign(100000,0);
        st.assign(4 * 100000,0);
        for(ll i = 0; i < n ; i++){
           scanf("%lld", &v[i]);
        }

        build(0,0,n-1);

        printf("Scenario #%lld:\n", test);
        for(ll i = 0; i < q; i++){
            ll a,b;
            scanf("%lld %lld",&a, &b);
            a--;
            b--;
            printf("%lld\n", query(a,b,0,0,n-1));
        }
        test++;

        v.clear();
        st.clear();
    }
}