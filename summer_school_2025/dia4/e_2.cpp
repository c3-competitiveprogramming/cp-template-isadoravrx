#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){

    ll n;
    cin >> n;

    vector<ll>v(n);
    ll mult = 1;
    for(ll i = 0; i < n; i++){
        cin >> v[i];
        mult *= v[i];
    }

    
    vector<ll>v2;
    ll a;
    ll olda;
    int cont = 0;
    ll ans;
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            a = lcm(v[i], v[j]);
            if(cont == 0){
                cont = 1;
            }else{
                ans = lcm(olda,a);
            }
            
            olda = a;
        }
    }
    cout << mult/ans << endl;
}