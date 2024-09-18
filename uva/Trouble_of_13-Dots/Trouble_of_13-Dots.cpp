#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

ll n;
ll  maxindice = 0;
int memo[105][400000];

ll recursive(ll index, vector<pair<ll,ll> >&v, ll sumbudget, ll sumindice, ll budget){
    if(memo[index][sumbudget] != -1){
        return memo[index][sumbudget];
    }
    if(index == n){
        if(maxindice < sumindice){
            maxindice = sumindice;
        }
        return maxindice;
    }

    
    bool b = false;
    if(sumbudget + v[index].first > 2000){
        budget += 200;
        b = true;
    }
    
    ll n1 = -1, n2 = -1;
    if(sumbudget + v[index].first <= budget ){
        n1 = recursive(index+1, v, sumbudget + v[index].first, sumindice+ v[index].second, budget);
    }
    
    if(b){
        budget-=200;
    }
    n2 = recursive(index+1, v, sumbudget, sumindice, budget);
    memo[index][sumbudget] = max(n1,n2);

    return memo[index][sumbudget];
   
}

int main(){
    
    ll budget;
    while(cin >> budget >> n){
       
        maxindice = 0;
        memset(memo, -1, sizeof(memo));

        vector<pair<ll,ll> >v;
        for(int i = 0; i < n; i++){
            ll value, indice;
            cin >> value >> indice;
            v.push_back(make_pair(value, indice));
        }

        sort(v.begin(),v.end());
        cout << recursive(0,v,0,0, budget) << endl;
        

    }
}