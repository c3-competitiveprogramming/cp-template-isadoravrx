#include <iostream>
#include <vector>
#include <cstring>
typedef long long ll;
using namespace std;
ll v[100000];
ll st[4 * 100000 + 1];

ll query(ll a, ll b, ll ind, ll l, ll r){
    if(r < a || l > b){
        return 0;
    }

    if(l >= a && r <= b){
        return st[ind];
    }

    ll mid = (l + r)/2;
    return query(a,b,ind*2 + 1, l, mid) + query(a,b,ind*2 +2, mid + 1, r);
}

void update(ll a, ll b, ll x, ll ind, ll l, ll r){
    if(r < a || l > b){
        return;
    }

    if(l == r){
        st[ind] += x;
        return;
    }
    ll mid = (l + r)/2;
    update(a,b,x,ind*2 + 1, l, mid);
    update(a,b,x,ind*2 +2, mid + 1, r);
    st[ind] = st[ind*2 + 1] + st[ind*2 + 2];
}

int main(){
    ll t;
    scanf("%lld", &t);

    while(t--){
        ll n,c;

        memset(v, 0, sizeof(v));
        memset(st, 0, sizeof(st));
        scanf("%lld %lld", &n, &c);
        for(ll i = 0; i < c; i++){
            ll num;
            scanf("%lld", &num);
            if(num == 0){ //inserir
                ll p,q,v;
                scanf("%lld %lld %lld", &p, &q, &v);
                p--;
                q--;
                update(p,q,v,0,0,n-1);
            }else{//consulta
                ll p,q;
                scanf("%lld %lld", &p, &q);
                p--;
                q--;
                printf("%lld\n", query(p,q,0,0,n-1));
            }
        }
    }
}