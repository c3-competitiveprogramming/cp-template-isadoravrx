#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n; 

        vector<ll>v;
        for(int i = 0; i < n; i++){
            ll num;
            cin >> num;
            v.push_back(num);
        }

        sort(v.begin(),v.end());

        ll ans = 0;
        for(int i = n-3; i >= 0; i-=3){
            ans += v[i];
        }

        cout << ans << endl;
    }
}