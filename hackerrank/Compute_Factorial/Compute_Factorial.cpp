#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;
ll resto=1e9+7;


int main(){

    vector<ll>mp(1000005);
    mp[0] = 1;
    mp[1] = 1;
    ll num = 2;
    for(int i = 2; i <= 1000001; i++){
        mp[i] = num;
        num = ((num % resto) * ((i+1) % resto)) % resto;
    }

    ll t,n;
    cin>>t;
    while(t--){
        cin >> n;
        cout << mp[n] << endl;
    }
    return 0;
} 