#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
    ll n;
    cin >> n;

    vector<ll>v;

    for(ll i = 0; i < n; i++){
        ll num;
        cin >> num;
        v.push_back(num);    
    }

    sort(v.begin(), v.end());
    ll i = 0;
    ll j = n-1;

    ll mx = 0;
    while(i < j){
        mx = max(mx, (v[j] + v[i]) / 2);
        i++;
        j--;
    }


    cout << mx << endl;
}