#include <iostream>
#include <map>
typedef long long ll;
using namespace std;
ll resto = 1e9+7;

int main(){ 
    ll pot = 1;
    map<ll,ll>mp;
    for(ll i = 0; i <= 100000; i++){
        mp[i] = pot % resto;
        pot = ((pot % resto) * 2) % resto;
    }

    ll t;
    cin >> t;

    while(t--){
        ll a,b;
        cin >> a >> b;

        if(a == b){
            cout << (mp[a] %  resto) << endl;
        }else{
            cout << (mp[a] %  resto + mp[b] %  resto) %  resto << endl;
        }
    }

    return 0;
}