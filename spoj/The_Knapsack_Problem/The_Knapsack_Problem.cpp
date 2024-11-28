#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
typedef long long ll;
using namespace std;

ll s,n; 
ll memo[2002][2002];
vector<pair<ll,ll> >v;

ll dp(ll index, ll size){
    if(size > s){
        return 0;
    }   

    if(index == n){
        return 0;
    }

    if(memo[index][size] != -1){
        return memo[index][size];
    }

    ll v1 = 0; 
    if(size + v[index].first <= s){
        v1 = dp(index+1, size+v[index].first);
        v1 += v[index].second;   
    }
    ll v2 = dp(index+1, size);

    
    return memo[index][size] = max(v1,v2);
}
int main(){
    cin >> s >> n;
    memset(memo, -1, sizeof(memo));
    for(ll i = 0; i < n ;i++){
        ll peso, value;
        cin >> peso >> value;
        v.push_back(make_pair(peso,value));
    }

    cout << dp(0,0) << endl;
}