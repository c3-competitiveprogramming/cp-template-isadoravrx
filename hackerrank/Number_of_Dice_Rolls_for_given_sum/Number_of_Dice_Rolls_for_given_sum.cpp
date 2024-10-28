#include <iostream>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;
ll resto = 1e9+7;
map<pair<ll,ll>,ll> c;

int main(){
    ll t;
    cin >> t;   

    map<ll,ll>mp;
    for(int i = 0; i <= 100000; i++ ){
        c[make_pair(i,i)] = 1;
        c[make_pair(0,i)] = 1;
        ll sum = 2;
        for(int j = 1; j < i ; j++){
            c[make_pair(i,j)] = (c[make_pair(i-1,j)] % resto) + (c[make_pair(i-1,j-1)] % resto);
            sum = (sum % resto) + (c[make_pair(i,j)] % resto);
        }
        mp[i] = sum % resto;
    }   
    while(t--){
        ll n;
        cin >> n;
        cout << mp[n-1] << endl;
    }
}