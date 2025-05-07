#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

int main(){
    ll n;
    cin >> n;

    ll ans = n;
    for(ll i = n; i >= 2; i--){
        bool b = true;
        for(ll j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                b = false;
                break;
            }
        }

        if(b){
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}