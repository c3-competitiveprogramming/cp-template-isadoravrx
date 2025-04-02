#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;

    vector<ll>v(n);

    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }

    ll maxcont = 0;
    bool b = true;
    for(ll i = 1; i < n; i++){
        ll cont = v[0] + v[n-1];
        ll j = i;
        while(j < n-1){
            cont += v[j];
            j += i;
        }

        if(b){
            maxcont = cont;
            b = false;
        }else{
            maxcont = max(maxcont, cont);
        }
    }

    cout << maxcont << endl;
}