#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }

    return gcd(b, a % b);
}

int main(){
    ll n;

    while(cin >> n){
        if(n == 0){
            break;
        }

        ll g = 0;

        map<pair<ll,ll>,ll>mp;
        for(ll i = 1; i < n ; i++){
            for(ll j = i + 1; j <= n ; j++){
                ll result;
                if(mp.find(make_pair(i,j)) == mp.end()){
                    result = gcd(i,j);
                    mp[make_pair(i,j)] = result;
                }else{
                    result = mp[make_pair(i,j)];
                }
                g += result;
            }
        }

        cout << g << endl;
    }
}